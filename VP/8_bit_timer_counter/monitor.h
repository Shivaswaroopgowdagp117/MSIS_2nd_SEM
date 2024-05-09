#include "systemc.h"
SC_MODULE(monitor)
{
       sc_bv<8> ctlr;
       sc_bv<8> compare;
       sc_bv<8> interrupt;
       sc_bv<8> value;
       
       
	sc_in<bool> clk;

	void mon()
	{
		cout << "ctrl= " <<ctrl <<"value= " <<value << "interrupt= "<<interrupt << "compare="
		<<compare <<endl;
	}

	SC_CTOR(monitor)
	{
		SC_METHOD(mon);
		sensitive << clk.pos();
	}
};
