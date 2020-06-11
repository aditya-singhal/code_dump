#include <iostream>
#include "adder.h"

int sc_main(int argc, char* argv[]){
	sc_signal<sc_uint<4> > a;
	sc_signal<sc_uint<4> > b;
	sc_signal<sc_uint<4> > out;
	sc_buffer<bool> carry_in;
	sc_buffer<bool> carry_out;
	sc_signal<bool> clock_main;
	adder adder_obj("adder_obj");
	
	adder_obj.in1.bind(a);
	adder_obj.in2.bind(b);
	adder_obj.carry_in.bind(carry_in);
	adder_obj.out.bind(out);
	adder_obj.carry_out.bind(carry_out);
	adder_obj.clock.bind(clock_main);
	clock_main.write(0);
	sc_start(0,SC_NS);

	std::cout << "in1\t" << "in2\t" << "out" << "\n";
	for (int i=0; i<16;i++) {
		for (int j=0; j<16;j++) {
			a.write(i);
			b.write(j);
			carry_in.write(0);
			clock_main.write(1);
			sc_start(1,SC_NS);
			clock_main.write(0);
			sc_start(1,SC_NS);
			std::cout << i << "\t" << j << "\t" << out << "\n";
		}
	}

	while(1);
	return 0;
}
