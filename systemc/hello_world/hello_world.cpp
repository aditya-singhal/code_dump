#include <iostream>
#include "systemc.h"

class hello_world : public sc_module {
public:
	sc_in<bool> test;
	hello_world(sc_module_name name) : sc_module(name){
		SC_HAS_PROCESS(hello_world);
		SC_THREAD(print_hello_world);
		dont_initialize();
		sensitive << test.pos();

		SC_METHOD(test_hello);
	}

	void test_hello() {
		std::cout << "Method Hello world!\n";	
	}

	void print_hello_world(){
		while(1) {
			std::cout << "Thread Hello world!\n";
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

	pl061(sc_module_name name) : sc_module(name){
		SC_HAS_PROCESS(pl061);
	}
    void before_end_of_elaboration() {
        std::cout << "pl061 before end_of_elaboration()\n";
    }
    void end_of_elaboration() {
        std::cout << "pl061 end_of_elaboration!\n";
    }
    void start_of_simulation() {
        std::cout << "pl061 start_of_simulation!\n";
    }
    void end_of_simulation() {
        std::cout << "pl061 end_of_simulation!\n";
    }
};

void sc_in<bool>::end_of_elaboration() {
	std::cout << "sc_in end_of_elaboration!\n";
};

int sc_main( int argc, char* argv[]) {
	sc_signal<bool> s1;

	pl061 hello1("hello1");
	hello_world hello("hi");
	hello.test.bind(s1);
	s1.write(1);

	hello.test_hello();	// Calling SC_METHOD explicitely

	std::cout << "before sc_start!\n";
	sc_start(100, SC_NS);
	return 0;
}
