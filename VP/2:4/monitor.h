#include "systemc.h"
SC_MODULE(monitor){

sc_in<bool> a1,a2,en;
sc_in<bool>d1,d2,d3,d4;

void mon()
{
cout << "Inputs: en "<<en<<" a2 "<<a2<<" a1 "<<a1  << " Output: "<<d4<<d3<<d2<<d1<<endl; 
}

	SC_CTOR(monitor)
	{
		SC_METHOD(mon);
		sensitive <<a1 <<a2<<en;
	}
};
