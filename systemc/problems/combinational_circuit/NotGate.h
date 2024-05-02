#ifndef __NOT_GATE_H__
#define __NOT_GATE_H__

class NotGate : public sc_module {
public:
	sc_in<bool> in;
	sc_out<bool> out;

	NotGate(sc_module_name name);
	void end_of_elaboration();
	void evaluate();
};

#endif
