#include "cell.h"

class top : public sc_module {
public:
	sc_in<bool> clk;
	sc_clock cell_clk;
	int **cell_nc;
	sc_vector < sc_vector <cell> > grid;
	sc_vector < sc_vector <sc_signal<bool> > > grid_signals;
	int grid_size;

	top(sc_module_name name, int size);
	~top();
	void print(void);

private:
	int evaluate_neighbour_count(int row, int column, uint8_t size);
	void bind_ports();
};
