#include "systemc.h"
SC_MODULE(halfadder)
{
      sc_in<bool> clk;
	sc_in<bool> a1;
	sc_in<bool> b1;
	sc_out<bool> sum,carry;
	void compute_halfadder()
	{	
		sum.write((a1.read() ^  b1.read()));
		carry.write((a1.read() &&  b1.read()));
	}
	SC_CTOR(halfadder)
	{
		SC_METHOD(compute_halfadder);
		sensitive <<clk.pos();
	}
};
