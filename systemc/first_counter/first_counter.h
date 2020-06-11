#include <iostream>
#include "systemc.h"

SC_MODULE (first_counter) {
	sc_in_clk     clock ;      // Clock input of the design
	sc_in<bool>   reset ;      // active high, synchronous Reset input
	sc_in<bool>   enable;      // Active high enable signal for counter
	sc_out<sc_uint<4> > counter_out; // 4 bit vector output of the counter

	//------------Local Variables Here---------------------
	sc_uint<4>	count;

	void incr_count(void); 	// process

	// Constructor for the counter
	// Since this counter is a positive edge trigged one,
	// We trigger the below block with respect to positive
	// edge of the clock and also when ever reset changes state
	SC_CTOR(first_counter) {
		std::cout << "Executing new" << endl;
		SC_METHOD(incr_count);
		sensitive << reset;
		sensitive << clock.pos();
	}
};
