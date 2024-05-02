#ifndef __OR_GATE_H__
#define __OR_GATE_H__

class OrGate : public sc_module {
public:
	sc_in<bool> in0;
	sc_in<bool> in1;
	sc_out<bool> out;

	OrGate(sc_module_name name);
	void end_of_elaboration();
	void evaluate();
};

#endif
