//monitor.h
#include<systemc.h>
SC_MODULE(monitor)
{
	sc_in<bool> t,q;
	sc_in<bool> clk;

	void mon()
	{
		cout<<"Input T: "<<t<<"Output Q:= "<<q<<endl;
	}

	SC_CTOR(monitor)
	{
		SC_METHOD(mon);
		sensitive<<clk.pos();
	}
};
