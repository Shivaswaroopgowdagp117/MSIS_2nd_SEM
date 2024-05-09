#include "systemc.h"
SC_MODULE(monitor){

sc_in<bool> a1,b1,d1;
  sc_in<bool> clk;

void mon()
{
cout << "Inputs: "<<a1 <<b1 << " Output: "<<d1 <<endl; 
}

	SC_CTOR(monitor)
	{
		SC_METHOD(mon);
		sensitive <<clk.pos();
	}
};
