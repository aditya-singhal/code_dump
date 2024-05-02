#include "LMC.h"
#include <stdint.h>

#define NUMERIC_CODE_ADD	1
#define NUMERIC_CODE_SUB	2
#define NUMERIC_CODE_STA	3
#define NUMERIC_CODE_LDA	5
#define NUMERIC_CODE_BRA	6
#define NUMERIC_CODE_BRZ	7
#define NUMERIC_CODE_BRP	8
#define NUMERIC_CODE_IO		9
#define NUMERIC_CODE_INP	1
#define NUMERIC_CODE_OUT	2
#define NUMERIC_CODE_HLT	0

/**************************************************
Function name: LMC()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
LMC::LMC() {
	//std::cout << "LMC constructor called\t" << this << "\n";
	this->m_PC = 0;
	this->m_ACC = 0;
 	this->m_N = false;
}

/**************************************************
Function name: ~LC3()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
LMC::~LMC() {
	//std::cout << "LMC destructor called\t" << this << "\n";
}

/**************************************************
Function name: reset()
Description: Reset the variables to initial value
Parameters: None
Return type: None
**************************************************/
void LMC::reset(){
	this->m_PC = 0;
	this->m_ACC = 0;
	this->m_N = false;
}

/**************************************************
Function name: device_read()
Description: Read data from input device
Parameters: None
Return type: Output data
**************************************************/
uint16_t LMC::device_read() {
	uint16_t data;
	std::cin >> data;
	return data;
}

/**************************************************
Function name: device_write()
Description: Write to output device
Parameters: Input data
Return type: None
**************************************************/
void LMC::device_write(uint16_t data) {
	std::cout << data;
}

/**************************************************
Function name: step()
Description: 1 cycle of instruction fetch,decode and execute
Parameters: None
Return type: None
**************************************************/
void LMC::step() {
	uint16_t instruction = 0;

	while(this->m_PC < 10) {
		this->port->read(this->m_PC, instruction);
		this->m_PC += 1;
		//std::cout << "Instruction: " << (unsigned int )instruction << "\n";
		decode_and_execute(instruction);
	}
}

/**************************************************
Function name: decode_and_execute()
Description: Instruction decode and execute
Parameters: Instruction
Return type: None
**************************************************/
void LMC::decode_and_execute(uint16_t instruction) {
	uint8_t memory_location = 0;
	uint16_t mem_data = 0;

    memory_location = instruction % 100;
    switch(instruction / 100) {
		case NUMERIC_CODE_HLT: {
    		std::cout << "HLT instruction\n";
    		break;
    	}
    	case NUMERIC_CODE_ADD: {
    		std::cout << "ADD instruction: ";
    		std::cout << "Add memory location content to acc\n";
    		this->port->read(memory_location, mem_data);
			if ((this->m_ACC + mem_data ) > 999) {
				this->m_ACC = 999;
				this->m_N = true;
			} else {
				this->m_ACC = this->m_ACC + mem_data;
				this->m_N = false;
			}
    		break;
    	}
		case NUMERIC_CODE_SUB: {
			std::cout << "SUB instruction: ";
			std::cout << "Subtract memory location content from acc\n";
    		this->port->read(memory_location, mem_data);
			if ((this->m_ACC - mem_data ) < 0) {
				this->m_ACC = 0;
				this->m_N = true;
			} else {
				this->m_ACC = this->m_ACC - mem_data;
				this->m_N = false;
			}
    		break;
    	}

		case NUMERIC_CODE_STA: {
			std::cout << "STA instruction: ";
			std::cout << "Store acc content at memory location\n";
			this->port->write(memory_location, this->m_ACC);
    		break;
    	}
		case NUMERIC_CODE_LDA: {
			std::cout << "LDA instruction: ";
			std::cout << "Load content at memory location to acc\n";
			this->port->read(memory_location, this->m_ACC);
    		break;
    	}
		case NUMERIC_CODE_BRA: {
			std::cout << "BRA instruction: ";
			std::cout << "Unconditional branch\n";
    		this->m_PC = memory_location;
    		break;
    	}
		case NUMERIC_CODE_BRZ: {
			std::cout << "BRZ instruction: ";
			std::cout << "Branch if 0\n";
			if (this->m_ACC == 0) {
				this->m_PC = memory_location;
			}
    		break;
    	}
		case NUMERIC_CODE_BRP: {
			std::cout << "BRP instruction: ";
			std::cout << "Branch if positive\n";
			if (this->m_N == false) {
				this->m_PC = memory_location;
			}
    		break;
    	}
		case NUMERIC_CODE_IO: {
			if (memory_location == NUMERIC_CODE_INP) {
				std::cout << "INP instruction: ";
				std::cout << "Read acc from input device\t";
				this->m_ACC = device_read();
			} else if (memory_location == NUMERIC_CODE_OUT){
				std::cout << "OUT instruction: ";
				std::cout << "Write acc to output device\t";
				device_write(this->m_ACC);
				std::cout << "\n";
			} else {
				std::cout << "Else, do nothing\n";
			}
    		break;
    	}
    	default: {
			std::cout << "Default, do nothing\n";
    		break;
    	}
    }
}
