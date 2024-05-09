#include "systemc.h"
SC_MODULE(monitor){

sc_in<bool> a1,b1,sum,carry;
  sc_in<bool> clk;

void mon()
{
cout << "Inputs: "<<a1 <<b1 << " Output: " << " sum=" <<sum << " carry=" << carry << endl; 
}

	SC_CTOR(monitor)
	{
		SC_METHOD(mon);
		sensitive <<clk.pos();
	}
};
