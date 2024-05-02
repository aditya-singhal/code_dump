#ifndef __CELL_H__
#define __CELL_H__

#include <systemc.h>

class cell : public sc_module {
public:
	sc_in<bool> clk;
	sc_vector<sc_in<bool> > neighbour;
	sc_out<bool> state;

	cell(sc_module_name name);
	~cell();

	void set_neighbour_size(int size);
	void step(void);
};

#endif
