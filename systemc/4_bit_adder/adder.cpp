#include <iostream>
#include "adder.h"

adder::adder(sc_module_name name) : sc_module(name), 
									single_bit_adder("single_bit_adder",4),
										in1("in1"),
										in2("in2"),
										carry_in("carry_in"),
										out("out"),
										carry_out("carry_out") {


    SC_HAS_PROCESS(adder);
    SC_METHOD(evaluate);
    dont_initialize();
    sensitive << clock.pos();
    
    SC_METHOD(get_output);
    dont_initialize();
    sensitive << carry_out << out1 << out2 << out3 << out4 ;

   	single_bit_adder[0].carry_out.bind(a1_c);
	single_bit_adder[1].carry_in.bind(a1_c);
	single_bit_adder[1].carry_out.bind(a2_c);
	single_bit_adder[2].carry_in.bind(a2_c);
	single_bit_adder[2].carry_out.bind(a3_c);
	single_bit_adder[3].carry_in.bind(a3_c);

	single_bit_adder[0].in1.bind(a1_in);
	single_bit_adder[0].in2.bind(b1_in);
	single_bit_adder[1].in1.bind(a2_in);
	single_bit_adder[1].in2.bind(b2_in);
	single_bit_adder[2].in1.bind(a3_in);
	single_bit_adder[2].in2.bind(b3_in);
	single_bit_adder[3].in1.bind(a4_in);
	single_bit_adder[3].in2.bind(b4_in);

	single_bit_adder[0].out.bind(out1);
	single_bit_adder[1].out.bind(out2);
	single_bit_adder[2].out.bind(out3);
	single_bit_adder[3].out.bind(out4);

	single_bit_adder[0].carry_in.bind(carry_in);
	single_bit_adder[3].carry_out.bind(carry_out);
}

void adder::evaluate() {
	sc_uint<4> input_1;
	sc_uint<4> input_2;

	input_1 = in1->read();
	input_2 = in2->read();
	a1_in.write(input_1[0]);
	a2_in.write(input_1[1]);
	a3_in.write(input_1[2]);
	a4_in.write(input_1[3]);
	b1_in.write(input_2[0]);
	b2_in.write(input_2[1]);
	b3_in.write(input_2[2]);
	b4_in.write(input_2[3]);
}

void adder::get_output() {
	sc_uint<4> output;

	output[0] = single_bit_adder[0].out->read();
	output[1] = single_bit_adder[1].out->read();
	output[2] = single_bit_adder[2].out->read();
	output[3] = single_bit_adder[3].out->read();
	out->write(output);
}
