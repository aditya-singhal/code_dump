#include <iostream>
#include <string>
#include "cell.h"
#include "top.h"
#include "debug.h"
#include "systemc.h"

#define GRID_SIZE	10
//check if can be made private
sc_time cell_clk_period(1,SC_NS);

inline bool is_location_valid(int row, int column, uint8_t grid_size){
	if( (row < 0) || (column < 0) ){
		return false;
	} else if ( (row > grid_size-1) || (column > grid_size-1) ) {
		return false;
	} else {
		return true;
	}
}

top::top(sc_module_name name, int size): sc_module(name),
										 cell_clk("cell_clock",cell_clk_period,0.5),
										 grid("grid", size),
										 grid_signals("grid_signals", size),
										 grid_size(size) {

    SC_HAS_PROCESS(top);

	this->clk.bind(cell_clk);

	cell_nc = new int*[grid_size];
	for(int i = 0; i < grid_size; ++i) {
    	cell_nc[i] = new int[grid_size];
	}

	for (int row = 0; row < grid_size; row++) {
		for (int column = 0; column < grid_size; column++) {
			cell_nc[row][column] = \
				evaluate_neighbour_count(row, column, grid_size);
		}
	}

	for (int row = 0; row < grid_size; row++) {
		grid[row].init(grid_size);
	}

	for (int row = 0; row < grid_size; row++) {
		grid_signals[row].init(grid_size);
	}

	for (int row = 0; row < grid_size; row++) {
		for (int column = 0; column < grid_size; column++) {
			grid[row][column].set_neighbour_size(cell_nc[row][column]);
		}
	}

	bind_ports();

	SC_METHOD(print);
	sensitive << clk.neg();
}

top::~top(){
	FUNC_INFO();
}

void top::print(void){
	//PRINT("print");
	for (int row = 0; row < grid_size; row++) {
		for (int column = 0; column < grid_size; column++) {
			if (grid[row][column].state->read() == false) {
				cout << " . ";
			} else {
				cout << " x ";
			}
		}
		cout << "\n";
	}
	cout << "\n\n";
}

int sc_main(int argc, char* argv[]) {
		
	top top1("top1", GRID_SIZE);

	//glider pattern
	top1.grid[1][1].state.write(true);
	top1.grid[1][2].state.write(true);
	top1.grid[1][3].state.write(true);
	top1.grid[2][1].state.write(true);
	top1.grid[3][2].state.write(true);

	//glider pattern
	// top1.grid[7][8].is_cell_alive = true;
	// top1.grid[7][9].is_cell_alive = true;
	// top1.grid[8][7].is_cell_alive = true;
	// top1.grid[8][8].is_cell_alive = true;
	// top1.grid[9][8].is_cell_alive = true;

	//patten
	// top1.grid[3][2].state.write(true);
	// top1.grid[3][4].state.write(true);
	// top1.grid[3][2].state.write(true);
	// top1.grid[4][4].state.write(true);
	// top1.grid[4][4].state.write(true);
	// top1.grid[4][4].state.write(true);
	// top1.grid[3][1].state.write(true);
	// top1.grid[3][3].state.write(true);
	// top1.grid[1][2].state.write(true);
	// top1.grid[2][3].state.write(true);
	
	sc_start(20,SC_NS);
	//sc_start();
	return 0;
}

void top::bind_ports(){
	int neighbour_row = 0;
	int neighbour_column = 0;
	int neighbour_count = 0;

	for (int row = 0; row < GRID_SIZE; row++) {
		for (int column = 0; column < GRID_SIZE; column++) {
			neighbour_count = 0;
			grid[row][column].clk.bind(cell_clk);
			grid[row][column].state.bind(grid_signals[row][column]);

			//bind with element at N
			neighbour_row = row - 1;
			neighbour_column = column;
			if (is_location_valid(neighbour_row, neighbour_column,GRID_SIZE ) == true ){
				grid[row][column].neighbour[neighbour_count++].
				bind(grid_signals[neighbour_row][neighbour_column]);
				//cout << "N Binding done\n";
			}

			//bind with element at NE
			neighbour_row = row - 1;
			neighbour_column = column + 1;
			if (is_location_valid(neighbour_row, neighbour_column,GRID_SIZE ) == true ){
				grid[row][column].neighbour[neighbour_count++].
				bind(grid_signals[neighbour_row][neighbour_column]);
				//cout << "NE Binding done\n";
			}

			//bind with element at E
			neighbour_row = row;
			neighbour_column = column + 1;
			if (is_location_valid(neighbour_row, neighbour_column,GRID_SIZE ) == true ){
				grid[row][column].neighbour[neighbour_count++].
				bind(grid_signals[neighbour_row][neighbour_column]);
				//cout << "E Binding done\n";			
			}

			//bind with element at SE
			neighbour_row = row + 1;
			neighbour_column = column + 1;
			if (is_location_valid(neighbour_row, neighbour_column,GRID_SIZE ) == true ){
				grid[row][column].neighbour[neighbour_count++].
				bind(grid_signals[neighbour_row][neighbour_column]);
				//cout << "SE Binding done" << neighbour_count << "\n";				
			}

			//bind with element at S
			neighbour_row = row + 1;
			neighbour_column = column;
			if (is_location_valid(neighbour_row, neighbour_column,GRID_SIZE ) == true ){
				grid[row][column].neighbour[neighbour_count++].
				bind(grid_signals[neighbour_row][neighbour_column]);
				//cout << "S Binding done\n";
			}

			//bind with element at SW
			neighbour_row = row + 1;
			neighbour_column = column - 1;
			if (is_location_valid(neighbour_row, neighbour_column,GRID_SIZE ) == true ){
				grid[row][column].neighbour[neighbour_count++].
				bind(grid_signals[neighbour_row][neighbour_column]);
				//cout << "SW Binding done\n";
			}
			//bind with element at W
			neighbour_row = row;
			neighbour_column = column - 1;
			if (is_location_valid(neighbour_row, neighbour_column,GRID_SIZE ) == true ){
				grid[row][column].neighbour[neighbour_count++].
				bind(grid_signals[neighbour_row][neighbour_column]);\
				//cout << "W Binding done\n";
			}		
			//bind with element at NW
			neighbour_row = row - 1;
			neighbour_column = column - 1;
			if (is_location_valid(neighbour_row, neighbour_column,GRID_SIZE ) == true ){
				grid[row][column].neighbour[neighbour_count++].
				bind(grid_signals[neighbour_row][neighbour_column]);
				//cout << "NW Binding done\n";
			}
		}
	}
}

int top::evaluate_neighbour_count(int row, int column, uint8_t size){
	int neighbour_row = 0;
	int neighbour_column = 0;
	int neighbour_count = 0;

	//bind with element at N
	neighbour_row = row - 1;
	neighbour_column = column;
	if (is_location_valid(neighbour_row, neighbour_column,size ) == true ){
		neighbour_count++;
	}

	//bind with element at NE
	neighbour_row = row - 1;
	neighbour_column = column + 1;
	if (is_location_valid(neighbour_row, neighbour_column,size ) == true ){
		neighbour_count++;
	}

	//bind with element at E
	neighbour_row = row;
	neighbour_column = column + 1;
	if (is_location_valid(neighbour_row, neighbour_column,size ) == true ){
		neighbour_count++;
	}

	//bind with element at SE
	neighbour_row = row + 1;
	neighbour_column = column + 1;
	if (is_location_valid(neighbour_row, neighbour_column,size ) == true ){
		neighbour_count++;
	}

	//bind with element at S
	neighbour_row = row + 1;
	neighbour_column = column;
	if (is_location_valid(neighbour_row, neighbour_column,size ) == true ){
		neighbour_count++;
	}

	//bind with element at SW
	neighbour_row = row + 1;
	neighbour_column = column - 1;
	if (is_location_valid(neighbour_row, neighbour_column,size ) == true ){
		neighbour_count++;
	}

	//bind with element at W
	neighbour_row = row;
	neighbour_column = column - 1;
	if (is_location_valid(neighbour_row, neighbour_column,size ) == true ){
		neighbour_count++;
	}

	//bind with element at NW
	neighbour_row = row - 1;
	neighbour_column = column - 1;
	if (is_location_valid(neighbour_row, neighbour_column,size ) == true ){
		neighbour_count++;
	}

	return neighbour_count;
}
