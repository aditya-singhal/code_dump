#include <iostream>
#include "bit_adder.h"

bit_adder::bit_adder(sc_module_name name) : sc_module(name),
											in1("in1"),
											in2("in2"),
											carry_in("carry_in"),
											out("out"),
											carry_out("carry_out"){

   SC_HAS_PROCESS(bit_adder);
   SC_METHOD(evaluate);
   dont_initialize();
   sensitive << in1 << in2 << carry_in;
}

void bit_adder::evaluate(){
	sc_uint<2> result = 0;

	result = in1->read() + in2->read() + carry_in->read();
	out->write(result[0]);
	carry_out->write(result[1]);
}
