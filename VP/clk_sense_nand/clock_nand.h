#include "systemc.h"
SC_MODULE(andgate)
{
      sc_in<bool> clk;
	sc_in<bool> a1;
	sc_in<bool> b1;
	sc_out<bool> d1;
	void compute_and()
	{	
		d1.write(!(a1.read() &&  b1.read()));
	}
	SC_CTOR(andgate)
	{
		SC_METHOD(compute_and);
		sensitive <<clk.pos();
	}
};
