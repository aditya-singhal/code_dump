#ifndef __HM_TEST_H__
#define __HM_TEST_H__

class hm_test : public sc_module {
public:
	sc_out<bool> out_A;
	sc_out<bool> out_B;
	sc_out<bool> out_C;
	sc_out<bool> out_D;
	sc_in<bool> in;
 
	hm_test(sc_module_name name);
	void end_of_elaboration();
 	void stimulate_n_monitor(bool a, bool b, bool c, bool d);
	void test();
};

#endif
