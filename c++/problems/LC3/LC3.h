#ifndef __LC3_H__
#define __LC3_H__

#include "Memory.h"

class LC3 {
public:
	bus_if *iport; // Instruction access, only reads
	bus_if *dport; // Data access for load/store, reads and writes

	LC3();
	~LC3();
	void reset();
	void step();
	uint16_t device_read();
	void device_write(uint16_t data);

private:
	std::vector<uint16_t> m_R;
	uint16_t m_PC;

	// Various fields of PSR register
	bool m_privilege;
	int m_priority;
	bool m_N;
	bool m_Z;
	bool m_P;
	
	void decode_and_execute(uint16_t instruction);
	void op_add(uint16_t instruction);
	void op_and(uint16_t instruction);
	void op_not(uint16_t instruction);
	void op_ld(uint16_t instruction);
	void op_ldi(uint16_t instruction);
	void op_ldr(uint16_t instruction);
	void op_lea(uint16_t instruction);
	void op_st(uint16_t instruction);
	void op_str(uint16_t instruction);
	void op_sti(uint16_t instruction);
	void op_br(uint16_t instruction);
	void op_jsr(uint16_t instruction);
	void op_jmp(uint16_t instruction);
	void op_rti(uint16_t instruction);
	void op_trap(uint16_t instruction);
	typedef void (*fptr) (short unsigned int);
	void update_flags(uint16_t register_addr);
	uint16_t sign_extend(uint16_t x, int bit_count);
};

#endif
