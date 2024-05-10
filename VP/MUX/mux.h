//mux.h
#include <systemc.h>
SC_MODULE(mux)
{
	sc_in<bool> s0;
	sc_in<bool> s1;
	sc_in<bool> a;
	sc_in<bool> b;
	sc_in<bool> c;
	sc_in<bool> d;
	sc_out<bool> f;
	void compute_mux()
	{
		if((s1.read()==false) && (s0.read()==false))
		{
			f.write(a.read());
		}
		else if((s1.read()==false) && (s0.read()==true))
		{
			f.write(b.read());
		}
		if((s1.read()==true) && (s0.read()==false))
		{
			f.write(c.read());
		}
		if((s1.read()==true) && (s0.read()==true))
		{
			f.write(d.read());
		}
		
	}
	SC_CTOR(mux)
	{
		SC_METHOD(compute_mux);
		sensitive<<s0<<s1<<a<<b<<c<<d;
	}
};
