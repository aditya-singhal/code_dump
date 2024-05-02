// File: main.cpp
// The executable should be run with the file to be loaded in memory as
// argument, like:
// $ lc3sim memfile

#include "LC3.h"
#include "Memory.h"

int main(int argc, char *argv[]) {
	// TODO: Check if argc is right, etc..
	// Instantiate components
	LC3 lc3;
	Memory memory;
 
	// "Connect" them
	lc3.iport = &memory;
	lc3.dport = &memory;
 
	// Initialize
	memory.load(argv[1]); 
 
 	// Simulate
	for(int i=0; i < 5; i++ ) {
		lc3.step();
	}
}
