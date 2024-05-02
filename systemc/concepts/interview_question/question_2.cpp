#include <iostream>
#define SC_INCLUDE_DYNAMIC_PROCESSES
#include "systemc.h"

class monitor_module : public sc_module {
public:
	uint32_t monitor_val;
	sc_port<sc_signal_out_if<bool> > monitor_out;
	sc_port<sc_signal_in_if<bool> > monitor_in;
	
	monitor_module(sc_module_name name) : sc_module(name){
		SC_HAS_PROCESS(monitor_module);

		SC_THREAD(monitor_input);
		sensitive << monitor_in;
		dont_initialize();

		// SC_METHOD(monitor_output);
		// sensitive << monitor_out;
		// dont_initialize();
	}
	void monitor_input(){
		bool input_value;
		
		while(1){
			std::cout << "@" << sc_time_stamp() << ": Input changed, Wait for 25ns" << "\n";
			input_value = monitor_in->read();
			sc_spawn(sc_bind(&monitor_module::monitor_output, this, input_value));
			wait();
		}
	}
	void monitor_output(bool input_value) {
		wait(25, SC_NS);
		monitor_out->write(input_value);
		wait(SC_ZERO_TIME);
		std::cout << "@" << sc_time_stamp() << ": high signal: " << monitor_out->read() << "\n";
	}
};

int sc_main(int argc, char* argv[]) {
	sc_buffer<bool> s1_in;
	sc_signal<bool,SC_MANY_WRITERS> s1_out;

	monitor_module monitor_obj("monitor_obj");
	monitor_obj.monitor_in.bind(s1_in);
	monitor_obj.monitor_out.bind(s1_out);

	s1_in.write(1);
	sc_start(1,SC_NS);
	s1_in.write(0);
	sc_start(1,SC_NS);
	s1_in.write(1);
	sc_start(1,SC_NS);
	s1_in.write(1);
	sc_start(1,SC_NS);
	s1_in.write(0);
	sc_start(1,SC_NS);
	s1_in.write(0);
	//s1_in.write(1);
	sc_start(100,SC_NS);
	return 0;
}