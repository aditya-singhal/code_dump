#include "LC3.h"
#include "debug.h"

#define INSTR_ADD_IMMEDIATE_VALUE_MASK	0x1F
#define INSTR_AND_IMMEDIATE_VALUE_MASK	0x1F
#define INSTR_LD_OFFSET_MASK			0x1FF
#define INSTR_ST_OFFSET_MASK			0x1FF
#define INSTR_LDR_OFFSET_MASK			0x3F
#define INSTR_LEA_OFFSET_MASK			0x1FF
#define INSTR_BR_OFFSET_MASK			0x1FF
#define INSTR_JSR_OFFSET_MASK			0x7FF
#define INSTR_BR_N_FLAG					0x04
#define INSTR_BR_Z_FLAG					0x02
#define INSTR_BR_P_FLAG					0x01

#define TRAP_VECTOR_INPUT				0x23
#define TRAP_VECTOR_OUTPUT				0x21
#define TRAP_VECTOR_HALT				0x25

#define OPCODE_ADD			1
#define OPCODE_AND			5
#define OPCODE_NOT			9
#define OPCODE_LD			2
#define OPCODE_LDI			10
#define OPCODE_LDR			6
#define OPCODE_LEA			14
#define OPCODE_ST			3
#define OPCODE_STR			7
#define OPCODE_STI			11
#define OPCODE_BR			0
#define OPCODE_JSR			4
#define OPCODE_JMP			12
#define OPCODE_RTI			8
#define OPCODE_TRAP			15
#define OPCODE_RESERVED		13

#define TOTAL_GENERAL_PURPOSE_REGISTERS	8

void setup_transaction( tlm::tlm_generic_payload* trans,
						tlm::tlm_command cmd,
						uint16_t address,
						uint16_t *data );

/**************************************************
Function name: LC3()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
LC3::LC3(sc_module_name name) : sc_module(name),	\
	m_R(TOTAL_GENERAL_PURPOSE_REGISTERS, 0) {
	
	FUNC_INFO();
	SC_HAS_PROCESS(LC3);
	this->m_PC = 0;
 	this->m_privilege = false;
 	this->m_priority = 0;
	this->m_N = false;
	this->m_Z = false;
	this->m_P = false;

	SC_THREAD(step);
	SC_METHOD(reset_asserted);
	dont_initialize();
	sensitive << nReset.neg();

	//std::cout << "LC3 constructor called\t" << this << "\n";
}

/**************************************************
Function name: ~LC3()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
LC3::~LC3() {
	//std::cout << "LC3 destructor called\t" << this << "\n";
}

/**************************************************
Function name: reset()
Description: Reset the variables to initial value
Parameters: None
Return type: None
**************************************************/
void LC3::reset(){
	this->m_PC = 0x00;
 	this->m_privilege = false;
 	this->m_priority = 0;
	this->m_N = false;
	this->m_Z = false;
	this->m_P = false;
	for (int i=0; i<TOTAL_GENERAL_PURPOSE_REGISTERS;i++){
		m_R[i] = 0;
	}
}

/**************************************************
Function name: step()
Description: 1 cycle of instruction fetch,decode and execute
Parameters: None
Return type: None
**************************************************/
void LC3::step() {
	uint16_t instruction = 0;
	tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload;
    sc_time delay;

	while(true){ 
		PRINT("step cycle\n");
		if ( nIRQ.read() == 0 ){
			PRINT("irq_asserted\n");
			irq_asserted();
		}
		setup_transaction( trans, tlm::TLM_READ_COMMAND, this->m_PC,
						   &(instruction));
		isocket->b_transport( *trans, delay );
		this->m_PC += 1;
		wait(1,SC_NS);
		//std::cout << "Instruction: " << instruction << "\n";
		//cout << "Decoding the instruction\n";
		decode_and_execute(instruction);
		wait(1,SC_NS);
	}
}

/**************************************************
Function name: decode_and_execute()
Description: Instruction decode and execute
Parameters: Instruction
Return type: None
**************************************************/
void LC3::decode_and_execute(uint16_t instruction) {
	uint8_t opcode = 0;

	opcode = instruction >> 12;
	switch(opcode){
		case OPCODE_ADD: op_add(instruction); break;
		case OPCODE_AND: op_and(instruction); break;
		case OPCODE_NOT: op_not(instruction); break;
		case OPCODE_LD: op_ld(instruction); break;
		case OPCODE_LDI: op_ldi(instruction); break;
		case OPCODE_LDR: op_ldr(instruction); break;
		case OPCODE_LEA: op_lea(instruction); break;
		case OPCODE_ST: op_st(instruction); break;
		case OPCODE_STR: op_str(instruction); break;
		case OPCODE_STI: op_sti(instruction); break;
		case OPCODE_BR: op_br(instruction); break;
		case OPCODE_JSR: op_jsr(instruction); break;
		case OPCODE_JMP: op_jmp(instruction); break;
		case OPCODE_RTI: op_rti(instruction); break;
		case OPCODE_TRAP: op_trap(instruction); break;
		default: std::cout << "No operation\n"; break;
	}
}

void LC3::reset_asserted(){
	PRINT("reset_asserted\n");
	this->reset();
	this->m_PC = 0x00;
}

void LC3::irq_asserted() {
	//Here I am storing PC value in the m_R[6] register,
	//but it should be saved at the memory location pointed by R6
	PRINT("saved PC value: ");
	cout << this->m_PC << "\n";
	this->m_R[6] = this->m_PC;
	this->m_PC = 0x01;
	this->nIRQ.write(1);
}

/**************************************************
Function name: op_add()
Description: Add either 2 registers or 1 register and an immediate value
			 according to a flag 
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_add( uint16_t instruction ){
	bool immediate_flag = 0;
	uint16_t immediate_value = 0;
	uint8_t src1 = 0;
	uint8_t src2 = 0;
	uint8_t dest = 0;

	immediate_flag = (instruction >> 5) & 0x1;
	dest = (instruction >> 9) & 0x7;
	src1 = (instruction >> 6) & 0x7;

    if (immediate_flag == true) {
		immediate_value = sign_extend((instruction) & INSTR_ADD_IMMEDIATE_VALUE_MASK, 5);
		this->m_R[dest] = this->m_R[src1] + immediate_value;
    } else {
		src2 = instruction & 0x7;
		this->m_R[dest] = this->m_R[src1] + this->m_R[src2];
    }
	std::cout << "Add instruction output: " << this->m_R[dest] << "\n";
	this->update_flags(dest);
}

/**************************************************
Function name: op_and()
Description: And either 2 registers or 1 register and an immediate value
			 according to a flag 
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_and( uint16_t instruction ){
	bool immediate_flag = 0;
	uint16_t immediate_value = 0;
	uint8_t src1 = 0;
	uint8_t src2 = 0;
	uint8_t dest = 0;

	immediate_flag = (instruction >> 5) & 0x1;
	dest = (instruction >> 9) & 0x7;
	src1 = (instruction >> 6) & 0x7;

    if (immediate_flag == true) {
		immediate_value = sign_extend((instruction) & INSTR_AND_IMMEDIATE_VALUE_MASK, 5);
		this->m_R[dest] = this->m_R[src1] & immediate_value;
    } else {
		src2 = instruction & 0x7;
		std::cout << "src1: " << this->m_R[src1] << "\n";
		std::cout << "src2: " << this->m_R[src2] << "\n";
		this->m_R[dest] = this->m_R[src1] & this->m_R[src2];
    }
    std::cout << "And instruction output: " << this->m_R[dest] << "\n";
    this->update_flags(dest);
}

/**************************************************
Function name: op_not()
Description: Bit-wise complement of the contents of SR is stored in DR
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_not( uint16_t instruction ){
	uint8_t dest = 0;
	uint8_t src1 = 0;

	dest = (instruction >> 9) & 0x7;
	src1 = (instruction >> 9) & 0x7;
	this->m_R[dest] = ~(this->m_R[src1]);
	std::cout << "Not instruction output: " << this->m_R[dest] << "\n";
	this->update_flags(dest);
}

/**************************************************
Function name: op_ld()
Description: Contents of memory at PC + offset are loaded into DR
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_ld( uint16_t instruction ){
	uint16_t memory_location = 0;
	uint16_t dest = 0;
	tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload;
    sc_time delay;

	dest = (instruction >> 9) & 0x7;
	//offset should be -256 <= offset <= 255
	memory_location = this->m_PC + sign_extend((instruction) & INSTR_LD_OFFSET_MASK, 9);
	//this->dport->read(memory_location, this->m_R[dest]);
	setup_transaction( trans, tlm::TLM_READ_COMMAND, memory_location,&(this->m_R[dest]));
	dsocket->b_transport( *trans, delay );
	std::cout << "ld instruction: ";
	std::cout << this->m_R[dest] << "(0x"<< memory_location << ") --> " <<"R"<< dest <<"\n";
	this->update_flags(dest);
}

/**************************************************
Function name: op_st()
Description: Contents of SR is stored at memory PC + offset 
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_st( uint16_t instruction ){
	uint16_t memory_location = 0;
	uint8_t src = 0;
	tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload;
    sc_time delay;

	std::cout << "st instruction\n";
	src = (instruction >> 9) & 0x7;
	memory_location = this->m_PC + sign_extend((instruction) & INSTR_ST_OFFSET_MASK, 9);
	//this->dport->write(memory_location, this->m_R[src]);
	setup_transaction( trans, tlm::TLM_WRITE_COMMAND, memory_location,&(this->m_R[src]));
	dsocket->b_transport( *trans, delay );
}

/**************************************************
Function name: op_ldi()
Description: Indirect addressing, First read address from PC + offset,
			 then contents at that address is loaded into DR
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_ldi( uint16_t instruction ){
	uint16_t memory_location = 0;
	uint16_t memory_location_final = 0;
	uint16_t dest = 0;
	tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload;
    sc_time delay;

	dest = (instruction >> 9) & 0x7;
	//offset should be -256 <= offset <= 255
	memory_location = this->m_PC + sign_extend((instruction) & INSTR_LD_OFFSET_MASK, 9);
	//this->dport->read(memory_location, memory_location_final);
	setup_transaction( trans, tlm::TLM_READ_COMMAND, memory_location, &memory_location_final);
	dsocket->b_transport( *trans, delay );

	//this->dport->read(memory_location_final, this->m_R[dest]);
	setup_transaction( trans, tlm::TLM_READ_COMMAND, memory_location_final, &(this->m_R[dest]));
	dsocket->b_transport( *trans, delay );

	this->update_flags(dest);
	std::cout << "ldi instruction: ";
	std::cout << this->m_R[dest] << "(0x"<< memory_location_final << ") --> " <<"R"<< dest <<"\n";
}

/**************************************************
Function name: op_sti()
Description: Indirect addressing, The contents of SR is stored at the address
			 stored at memory PC + offset 
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_sti( uint16_t instruction ){
	uint16_t memory_location = 0;
	uint16_t memory_location_final = 0;
	uint16_t src = 0;
	tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload;
    sc_time delay;	

	src = (instruction >> 9) & 0x7;
	memory_location = this->m_PC + sign_extend((instruction) & INSTR_LD_OFFSET_MASK, 9);
	//this->dport->read(memory_location, memory_location_final);
	setup_transaction( trans, tlm::TLM_READ_COMMAND, memory_location, &memory_location_final);
	dsocket->b_transport( *trans, delay );

	//this->dport->write(memory_location_final, this->m_R[src]);
	setup_transaction( trans, tlm::TLM_WRITE_COMMAND, memory_location_final, &(this->m_R[src]));
	dsocket->b_transport( *trans, delay );	
	std::cout << "sti instruction: ";
	std::cout << this->m_R[src] << "(R" << src << ") --> 0x" << memory_location_final << "\n";

}

/**************************************************
Function name: op_ldr()
Description: Contents of memory at base register + offset are loaded into DR
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_ldr( uint16_t instruction ){
	uint16_t memory_location = 0;
	uint16_t dest = 0;
	uint16_t base = 0;
	tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload;
    sc_time delay;	

	std::cout << "ldr instruction\n";
	dest = (instruction >> 9) & 0x7;
	base = (instruction >> 6) & 0x7;
	memory_location = this->m_R[base] + sign_extend((instruction) & INSTR_LDR_OFFSET_MASK, 6);
	//this->dport->read(memory_location, this->m_R[dest]);
	setup_transaction( trans, tlm::TLM_READ_COMMAND, memory_location, &(this->m_R[dest]));
	dsocket->b_transport( *trans, delay );
	this->update_flags(dest);
}

/**************************************************
Function name: op_str()
Description: Contents of memory at base register + offset are loaded into DR
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_str( uint16_t instruction ){
	uint16_t memory_location = 0;
	uint16_t src = 0;
	uint16_t base = 0;
	tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload;
    sc_time delay;	

	std::cout << "str instruction\n";
	src = (instruction >> 9) & 0x7;
	base = (instruction >> 6) & 0x7;
	memory_location = this->m_R[base] + sign_extend((instruction) & INSTR_LDR_OFFSET_MASK, 6);
	//this->dport->write(memory_location, this->m_R[src]);
	setup_transaction( trans, tlm::TLM_WRITE_COMMAND, memory_location, &(this->m_R[src]));
	dsocket->b_transport( *trans, delay );	
}

/**************************************************
Function name: op_lea()
Description: Address obtained by PC + offset is loaded in DR
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_lea( uint16_t instruction ){
	uint16_t memory_location = 0;
	uint16_t dest = 0;
	tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload;
    sc_time delay;	

	std::cout << "lea instruction\n";
	dest = (instruction >> 9) & 0x7;
	//offset should be -256 <= offset <= 255
	memory_location = this->m_PC + sign_extend((instruction) & INSTR_LEA_OFFSET_MASK, 9);
	//this->dport->write(memory_location, this->m_R[dest]);
	setup_transaction( trans, tlm::TLM_WRITE_COMMAND, memory_location, &(this->m_R[dest]));
	dsocket->b_transport( *trans, delay );	
	this->update_flags(dest);
}

/**************************************************
Function name: op_br()
Description: If any respective flag specified in the instruction is set, 
			 then program branches to the location PC + offset
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_br( uint16_t instruction ){
	uint8_t condition = 0;

	std::cout << "branch to address: ";
	condition = (instruction >> 9) & 0x7;
	if ( ( ( condition & INSTR_BR_N_FLAG) == true) || ( ( condition & INSTR_BR_Z_FLAG) == true) || \
		( ( condition & INSTR_BR_P_FLAG) == true) ) {
		this->m_PC = this->m_PC + sign_extend((instruction) & INSTR_BR_OFFSET_MASK, 9);
		std::cout << this->m_PC << "\n";
	} else {
		//do nothing
	}
}

/**************************************************
Function name: op_jmp()
Description: The program unconditionally jumps to the location specified	\
			 by the contents of the base register.
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_jmp( uint16_t instruction ){
	uint16_t base = 0;

	std::cout << "jmp instruction\n";
	base = (instruction >> 6) & 0x7;
	this->m_PC = this->m_R[base];
}

/**************************************************
Function name: op_jsr()
Description: According to label flag, program either jumps to the address    \
			 stored at base register or PC + offset 
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_jsr( uint16_t instruction ) {
	bool label_flag = 0;
	uint16_t base = 0;

	std::cout << "jsr instruction\n";
	label_flag = (instruction >> 11) & 0x1;
	if (label_flag == true){
		//JSR
		this->m_PC = this->m_PC + sign_extend((instruction) & INSTR_JSR_OFFSET_MASK, 11);
	} else {
		//JSRR
		base = (instruction >> 6) & 0x7;
		this->m_PC = this->m_R[base];
	}
}

/**************************************************
Function name: op_rti()
Description: RTI instruction
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_rti( uint16_t instruction ) {
	std::cout << "rti instruction\n";

	//here I am using r6 to store PC location, but the
	//location pointed by R6 should be used
	this->m_PC = this->m_R[6];
	PRINT("Loaded pc value: ");
	cout << this->m_PC << "\n";
}

/**************************************************
Function name: op_trap()
Description: Trap instruction
Parameters: Instruction
Return type: None
**************************************************/
void LC3::op_trap( uint16_t instruction ) {
	//uint16_t trap_vector = 0;
	
	std::cout << "trap instruction\n";
	//trap_vector = instruction & 0xFF;
	// Saving the return address in R6
	this->m_R[6] = this->m_PC;
	// The starting address of this system call is stored in
	// memory location pointed by trap vector
	//this->dport->read(trap_vector, this->m_PC);
	while(1);
}

/**************************************************
Function name: sign_extend()
Description:  Sign extend a two's complement number to 16 bits
Parameters: None
Return type: None
**************************************************/
uint16_t LC3::sign_extend(uint16_t x, int bit_count) {
	if ((x >> (bit_count - 1)) & 1) {
		x |= (0xFFFF << bit_count);
	}
	return x;
}

/**************************************************
Function name: update_flags()
Description: Update PSR register flags
Parameters: None
Return type: None
**************************************************/
void LC3::update_flags(uint16_t register_addr) {
	if (this->m_R[register_addr] == 0) {
		this->m_Z = true;
		this->m_P = false;
		this->m_N = false;
	} else if (( this->m_R[register_addr] >> 15) & 0x01 ) {
		//a 1 in the left-most bit indicates negative
		this->m_Z = false;
		this->m_P = false;
		this->m_N = true;
	} else {
		this->m_P = true;
		this->m_Z = false;
		this->m_N = false;
	}
}

void setup_transaction( tlm::tlm_generic_payload* trans,
						tlm::tlm_command cmd,
						uint16_t address,
						uint16_t *data ) {
	
	// Initialize 8 out of the 10 attributes, byte_enable_length and extensions being unused
	trans->set_command( cmd );
	static uint8_t byte_enable[2] = {0xFF, 0xFF};
	
	trans->set_address( static_cast<uint64_t>(address) );
	trans->set_data_ptr( reinterpret_cast<unsigned char*>(data) );
	trans->set_data_length( 2 );
	trans->set_streaming_width( 2 ); // = data_length to indicate no streaming
	trans->set_byte_enable_length( 2 );
	trans->set_byte_enable_ptr( reinterpret_cast<unsigned char*>(byte_enable) );
	trans->set_dmi_allowed( false ); // Mandatory initial value
	trans->set_response_status( tlm::TLM_INCOMPLETE_RESPONSE ); // Mandatory initial value
}
