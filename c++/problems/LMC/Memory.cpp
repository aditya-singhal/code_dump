#include <fstream>
#include "Memory.h"

#define MEMORY_SIZE		100

/**************************************************
Function name: Memory()
Description: Constructor, initialise memory_content with MEMORY_SIZE
Parameters: None
Return type: None
**************************************************/
Memory::Memory() : memory_content(MEMORY_SIZE, 0) {
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
bool Memory::load(std::string file_name){
	std::ifstream input_file;
	std::string line;
	std::string comment = "#";
	uint32_t mem_location_index = 0;

	input_file.open(file_name);
	if (!input_file) {
		std::cerr << "Unable to open file " << file_name;
		return false;
	}

	while ( getline (input_file, line) ) {
    	if (line[0] == '#'){
    		//std::cout << "comment, ignore it\n" << '\n';
    	} else {
    		if (line[0] == 'A'){
				mem_location_index = std::stoi(&line[1]);
    			//std::cout << myint1 << '\n';
    		} else if (line[0] == 'D') {
				this->memory_content[mem_location_index++] = std::stoi(&line[1]);
    			//std::cout << myint2 << '\n';
    		}
    		else{
    			continue;
    		}
    	}
    }

	input_file.close();
	std::cout << "Memory loaded\n";

	return true;
}
