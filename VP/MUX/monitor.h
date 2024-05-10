//monitor.h
#include<systemc.h>
SC_MODULE(monitor)
{
	sc_in<bool> a,b,c,d,f,s0,s1;

	void mon()
	{
		cout<<"Inputs: "<<a<<b<<c<<d<<s0<<s1<<"Output: "<<f<<endl;
	}

	SC_CTOR(monitor)
	{
		SC_METHOD(mon);
		sensitive<<a<<b<<c<<d<<s0<<s1;
	}
};
