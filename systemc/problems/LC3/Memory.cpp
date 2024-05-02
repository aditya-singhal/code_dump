#include <fstream>
#include "Memory.h"
#include "debug.h"

//sc_dt::uint16 not working ....why?

#define __MEMORY_SIZE		pow(2,16)

/**************************************************
Function name: Memory()
Description: Constructor, initialise memory_content with MEMORY_SIZE
Parameters: None
Return type: None
**************************************************/
Memory::Memory(sc_module_name name) : sc_module(name),
									  memory_socket("memory_socket"),
 									  memory_content(__MEMORY_SIZE, 0) {
	
	FUNC_INFO();
	memory_socket.register_b_transport(this, &Memory::b_transport);
	//std::cout << "Memory constructor called\t" << this << "\n";
}

/**************************************************
Function name: ~Memory()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
Memory::~Memory() {
	//std::cout << "Memory destructor called\t" << this << "\n";
}

/**************************************************
Function name: load()
Description: Load the memory with values as specified in file
Parameters: None
Return type: Return "true" on success
**************************************************/
bool Memory::load(char* file_name){
	std::ifstream input_file;
	std::string line;
	uint32_t mem_location_index = 0;

	input_file.open(file_name);
	if (!input_file) {
		std::cerr << "Unable to open file " << file_name;
		return false;
	}

	std::cout << "Loading file into memory...\n";
	while ( getline (input_file, line) ) {
    	if (line[0] == '#'){
    		//std::cout << "comment, ignore it\n" << '\n';
    	} else {
    		if (line[0] == 'A'){
    			sscanf(&line[1], "%x", &mem_location_index); 
				//mem_location_index = std::atoi(&line[1], 0, 16);
    			//std::cout << mem_location_index << '\n';
    		} else if (line[0] == 'D') {
    			sscanf(&line[1], "%x", &(this->memory_content[mem_location_index]) ) ;
				//this->memory_content[mem_location_index++] = std::stoi(&line[1],0, 16);
    			//std::cout <<"@" << mem_location_index <<": "<< this->memory_content[mem_location_index] << '\n';
    			mem_location_index++;
    		}
    		else{
    			continue;
    		}
    	}
    }

	input_file.close();
	std::cout << "Memory loaded!\n";

	return true;
}

/**************************************************
Function name: b_transport()
Description: b_transport call
Parameters: None
Return type: Return "true" on success
**************************************************/
void Memory::b_transport( int id, tlm::tlm_generic_payload& trans,
						  sc_time& delay ){
	
	tlm::tlm_command cmd = trans.get_command();
    uint64_t    addr = trans.get_address();
    unsigned char*   data_ptr = trans.get_data_ptr();
    unsigned int     len = trans.get_data_length();
    unsigned char*   byt = trans.get_byte_enable_ptr();
    unsigned int     wid = trans.get_streaming_width();

    uint8_t *byte_enable = reinterpret_cast<uint8_t*>(byt);
    uint16_t mem_addr = addr & 0xFFFF;

    if (mem_addr >= sc_dt::uint64(__MEMORY_SIZE) || len > 2 || wid > 2	|| \
    	((byte_enable[0] != 0xFF) || (byte_enable[1] != 0xFF) ) ) {
		SC_REPORT_ERROR("TLM-2", "Target does not support given generic payload transaction");
    }

    if ( cmd == tlm::TLM_READ_COMMAND ) {
      data_ptr[0] = this->memory_content[addr] & 0xFF;
      data_ptr[1] = ( (this->memory_content[addr]) >> 8 ) & 0xFF ;

    } else if ( cmd == tlm::TLM_WRITE_COMMAND ) {
		this->memory_content[addr] = (data_ptr[0] & 0xFF ) |	\
									 ((data_ptr[1]<<8) & 0xFF );
    }

    //wait(10,SC_NS);
    trans.set_response_status( tlm::TLM_OK_RESPONSE );
}
