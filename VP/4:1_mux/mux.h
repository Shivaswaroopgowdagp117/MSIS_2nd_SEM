#include "systemc.h"
SC_MODULE(mux)
{
	sc_in<bool> a0;
	sc_in<bool> a1;
	sc_in<bool> a2;
	sc_in<bool> a3;

	sc_in<bool> sel0;
	sc_in<bool> sel1;

	sc_out<bool> out;

	void _mux()
	{
		if (sel0.read() == 0 && sel1.read() == 0)
		{
			out.write(a0.read());
		}
		else if (sel0.read() == 1 && sel1.read() == 0)
		{
			out.write(a1.read());
		}
		else if (sel0.read() == 0 && sel1.read() == 1)
		{
			out.write(a2.read());
		}
		else
		{
			out.write(a3.read());
		}
	}
	SC_CTOR(mux)
	{
		SC_METHOD(_mux);
		sensitive << sel0 << sel1;
	}
};
