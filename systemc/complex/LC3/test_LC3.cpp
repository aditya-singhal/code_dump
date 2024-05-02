// File: main.cpp
// The executable should be run with the file to be loaded in memory as
// argument, like:
// $ lc3sim memfile

#include "LC3.h"
#include "Memory.h"
#include "Bus.h"
#include "debug.h"

class Top : public sc_module {
public:
	LC3 *lc3;
	Memory *memory;
	Bus *bus;

	Top(sc_module_name name, char* argv) : sc_module(name) {
		int status = 0;
	 	
		FUNC_INFO();

	 	lc3 = new LC3("lc3");
	 	memory = new Memory("memory");
	 	bus = new Bus("bus",3);

		// "Connect" them
		lc3->isocket.bind(bus->master_socket);
		lc3->dsocket.bind(bus->master_socket);

		bus->slave_socket.bind(memory->memory_socket);
		status = bus->add_address_range(0x0, 0x3, 0);
		if (status != 0 ){
			cout << "add_address_range error\n";
		}

		bus->slave_socket.bind(memory->memory_socket);
		status = bus->add_address_range(0x4, 0x50, 1);
		if (status != 0 ){
			cout << "add_address_range error\n";
		}

		bus->slave_socket.bind(memory->memory_socket);
		status = bus->add_address_range(0x51, 0x300, 2);
		if (status != 0 ){
			cout << "add_address_range error\n";
		}

		// Initialize memory
		status = memory->load(argv);
		if (status != true){
			cout << "Error in loading memory!\n";
		}
	}
};

int sc_main(int argc, char *argv[]) {
	sc_signal<bool> nReset;
	sc_signal<bool> nIRQ;

	if (argc != 2){
		cout << "Error! Kindly provide input memory file\n";
		return 0;
	}

	Top top1( "top1", argv[1]);
	top1.lc3->nReset.bind(nReset);
	top1.lc3->nIRQ.bind(nIRQ);

	nReset = true;
	nIRQ = true;

	sc_start(10, SC_NS);
	PRINT("1 start cyle ended\n")

	// Assert reset
	nReset = false;
	sc_start(10, SC_NS); // Check if reset occurred
	PRINT("2 start cyle ended\n")

	//De-assert reset
	nReset = true;
	sc_start(10, SC_NS); // Ensure enough time - at least stack pointer should be setup
	PRINT("3 start cyle ended\n")\

	//Assert interrupt
	nIRQ = false;
	sc_start(10, SC_NS); // Check if the IRQ handler executed
	PRINT("4 start cyle ended\n")  		

 	//De-assert interrupt
 	nIRQ = true;
 	sc_start(40, SC_NS); // Check if execution continues after IRQ handler returns

	// sc_start();
	return 0;
}
