#ifndef __BIT_ADDER_H__
#define __BIT_ADDER_H__

#include <systemc.h>

class bit_adder : public sc_module {
public:
	sc_port<sc_signal_in_if<bool> > in1;
	sc_port<sc_signal_in_if<bool> > in2;
	sc_port<sc_signal_in_if<bool> > carry_in;
	sc_port<sc_signal_out_if<bool> > out;
	sc_port<sc_signal_out_if<bool> > carry_out;
	bit_adder(sc_module_name name);
	void evaluate();
};

#endif