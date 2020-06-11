#include <iostream>
#include "systemc.h"

class hello_world : public sc_module {
public:
	sc_in<bool> test;
	hello_world(sc_module_name name) : sc_module(name){
		SC_HAS_PROCESS(hello_world);
		SC_THREAD(print_hello_world);
		dont_initialize();
		//sensitive << test;
	}

	void print_hello_world(){
		while(1){
			std::cout << "Hello world!\n";
			wait(5,SC_NS);
		}
	}
	void before_end_of_elaboration() {
		std::cout << "before_end_of_elaboration!\n";
	}
	void end_of_elaboration() {
		std::cout << "end_of_elaboration!\n";
	}
	void start_of_simulation() {
		std::cout << "start_of_simulation!\n";
	}
	void end_of_simulation() {
		std::cout << "end_of_simulation!\n";
	}
};

class pl061 : public sc_module {
public:
    // pl061_regs pl061_registers;
    // tlm_utils::simple_target_socket<pl061> target_socket;
    // sc_in<bool> reset;
    // sc_out<bool> irq_out;
    // sc_inout<bool> gpio_pins[8];
    // sc_event gpio_read_event;
    // sc_event gpio_write_event;
    // sc_event interrupt_enable_event;
    // sc_event update_interrupt_sensitivity_event;
    // sc_event interrupt_clear_event;

    // interrupt_handler_desc_t interrupt_handler_desc[8]; 
    // pl061(sc_module_name name);
    // void b_transport_cb(tlm::tlm_generic_payload& gp, sc_time& delay);

	pl061(sc_module_name name) : sc_module(name){
		SC_HAS_PROCESS(pl061);
		//SC_THREAD(print_hello_world);
		//dont_initialize();
		//sensitive << test;
	}
    void before_end_of_elaboration() {
        std::cout << "before end_of_elaboration()\n";
        //irq_out.write(0);
    }
    void end_of_elaboration() {
        std::cout << "end_of_elaboration!\n";
    }
    void start_of_simulation() {
        std::cout << "start_of_simulation!\n";
    }
    void end_of_simulation() {
        std::cout << "end_of_simulation!\n";
    }
};

void sc_in<bool>::end_of_elaboration() {
	std::cout << "sc_in end_of_elaboration!\n";
};

int sc_main( int argc, char* argv[]) {
	sc_signal<bool> s1;

	pl061 hello1("j");
	//hello_world hello("hi");
	hello.test.bind(s1);
	s1.write(1);

	//hello.print_hello_world();

	std::cout << "before sc_start!\n";
	sc_start(100, SC_NS);
	return 0;
}
