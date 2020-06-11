#ifndef __ADDER_H__
#define __ADDER_H__

#include <systemc.h>
#include "bit_adder.h"

class adder : public sc_module {
public:
	sc_vector<bit_adder> single_bit_adder;

	sc_port<sc_signal_in_if<sc_uint<4> > > in1;
	sc_port<sc_signal_in_if<sc_uint<4> > > in2;
	sc_port<sc_signal_in_if<bool> > carry_in;
	sc_port<sc_signal_out_if<sc_uint<4> > > out;
	sc_port<sc_signal_out_if<bool> > carry_out;
	sc_in<bool> clock;

	sc_buffer<bool> a1_c, a2_c, a3_c;
	sc_signal<bool> a1_in, a2_in, a3_in, a4_in;
	sc_signal<bool> b1_in, b2_in, b3_in, b4_in;
	sc_signal<bool> out1, out2, out3, out4;
	adder(sc_module_name name);
	void evaluate();
	void get_output();
};

#endif