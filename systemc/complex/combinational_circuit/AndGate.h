#ifndef __AND_GATE_H__
#define __AND_GATE_H__

class AndGate : public sc_module {
public:
	sc_in<bool> in0;
	sc_in<bool> in1;
	sc_out<bool> out;

	AndGate(sc_module_name name);
	void end_of_elaboration();
	void evaluate();
};

#endif
