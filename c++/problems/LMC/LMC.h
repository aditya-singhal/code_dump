#ifndef __LMC_H__
#define __LMC_H__

#include "Memory.h"

class LMC {
public:
	bus_if *port; // Port to access memory

	LMC();
	~LMC(); 
	void reset();
	void step();
	uint16_t device_read();
	void device_write(uint16_t data);

private:
	uint8_t m_PC;
	uint16_t m_ACC;
 	bool m_N;
	void decode_and_execute(uint16_t instruction);
};

#endif