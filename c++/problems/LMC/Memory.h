#ifndef __MEMORY_H__
#define __MEMORY_H__

#include "bus_if.h"
#include <vector>

class Memory : public bus_if {
public:
	Memory();
	~Memory();
	virtual status_t read(uint8_t addr, uint16_t &data){
		data = this->memory_content[addr];
		return BUS_OK;
	}
	virtual status_t write(uint8_t addr, uint16_t data){
		this->memory_content[addr] = data;
		return BUS_OK;
	}
	
 	bool load(std::string file_name);

private:
	std::vector<unsigned int> memory_content;
};

#endif