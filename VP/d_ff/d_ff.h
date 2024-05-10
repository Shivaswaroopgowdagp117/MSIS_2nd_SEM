#include "systemc.h"
SC_MODULE(d_ff)
{
	sc_in<bool> clk;
	sc_in<bool> d_in;
	sc_out<bool> q;
	sc_out<bool> qbar;

	uint dprev=0;
	void compute_result()
	{
		q.write(dprev);
		qbar.write(!dprev);
		dprev = d_in.read();
	}
	SC_CTOR(d_ff)
	{
		SC_METHOD(compute_result);
		sensitive << clk.pos();
	}
};
