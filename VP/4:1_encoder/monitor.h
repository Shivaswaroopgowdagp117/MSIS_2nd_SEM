#include "systemc.h"
SC_MODULE(monitor){

sc_in<bool> a0,a1,a2,a3,en;
sc_in<sc_uint<2>>d;

void mon()
{
cout << "Inputs: en "<<en<<" a "<<a3<<a2<<a1<<a0  << " Output: "<<d<<endl; 
}

	SC_CTOR(monitor)
	{
		SC_METHOD(mon);
		sensitive <<a0<<a1<<a2<<a3<<en;
	}
};
