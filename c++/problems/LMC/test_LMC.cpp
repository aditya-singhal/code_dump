#include "LMC.h"
#include "Memory.h"

int main(int argc, char *argv[]) {
	// TODO: Check if argc is right, etc..
	// Instantiate components
	LMC lmc;
	Memory memory;
 
	// "Connect" them
	lmc.port = &memory;
 
	// Initialize
	memory.load(argv[1]); 
 
 	// Simulate
	while(1) {
		lmc.step();
	}
}
