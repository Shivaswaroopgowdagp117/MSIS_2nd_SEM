#include "systemc.h"
SC_MODULE(fulladder)
{
      sc_in<bool> clk;
	sc_in<bool> a1;
	sc_in<bool> b1;
	sc_in<bool> cin;
	sc_out<bool> sum,carry;
	void compute_fulladder()
	{	
		sum.write(a1.read() ^  b1.read()^cin.read());
		carry.write((a1.read() &&  b1.read())||(cin.read() &&  b1.read())||(a1.read() && cin.read()));
	}
	SC_CTOR(fulladder)
	{
		SC_METHOD(compute_fulladder);
		sensitive <<clk.pos();
	}
};
