#include <iostream>
#include "systemc.h"

class monitor_module : public sc_module {
public:
	uint32_t monitor_val;
	sc_port<sc_signal_out_if<uint32_t> > monitor_out;
	sc_port<sc_signal_in_if<bool>,0 > monitor_in;
	
	monitor_module(sc_module_name name) : sc_module(name){
		SC_HAS_PROCESS(monitor_module);

		SC_METHOD(monitor_input);
		sensitive << monitor_in;
		dont_initialize();

		SC_METHOD(monitor_output);
		sensitive << monitor_out;
		dont_initialize();
	}
	void monitor_input(){
		for (int i=0; i<monitor_in.size();i++){
			if ( monitor_in[i]->read() == 1 ){
				monitor_out->write(i);
				break;
			}
		}
	}
	void monitor_output(){
		std::cout << "@" << sc_time_stamp() << ": high signal: " << monitor_out->read() << "\n";
	}
};

int sc_main(int argc, char* argv[]) {
	sc_signal<bool> s1;
	sc_signal<bool> s2;
	sc_signal<bool> s3;
	sc_signal<bool> s4;
	sc_signal<bool> s5;
	sc_signal<uint32_t> s6;

	monitor_module monitor_obj("monitor_obj");
	monitor_obj.monitor_in.bind(s1);
	monitor_obj.monitor_in.bind(s2);
	monitor_obj.monitor_in.bind(s3);
	monitor_obj.monitor_in.bind(s4);
	monitor_obj.monitor_in.bind(s5);
	monitor_obj.monitor_out.bind(s6);
	s6.write(0);

	s2.write(1);
	sc_start(1,SC_NS);
	s2.write(0);
	s3.write(1);
	sc_start(1,SC_NS);
	s3.write(0);
	s4.write(1);
	sc_start(1,SC_NS);
	s4.write(0);
	s5.write(1);
	sc_start(1,SC_NS);
	s5.write(0);
	s1.write(1);
	sc_start(1,SC_NS);
	return 0;
}