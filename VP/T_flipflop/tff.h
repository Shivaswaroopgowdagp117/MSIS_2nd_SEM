//andgate.h
#include <systemc.h>
SC_MODULE(tff)
{
	sc_in<bool> t;
	sc_out<bool> q;
	sc_in<bool> clk;
	
	void compute_tff()
	{
		q.write(!(t.read()));
	}
	SC_CTOR(tff)
	{
		SC_METHOD(compute_tff);
		sensitive<<clk.pos();
	}
};
