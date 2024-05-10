#include<systemc.h>

SC_MODULE(monitor)
{
	sc_in<bool>clk,rst;
	sc_in<sc_uint<4>>count;

	void counts(){
		cout<<"Inputs are :"<< clk<<" reset is "<< rst <<" Outputs are :"<<count<<endl;
	}

	SC_CTOR(monitor){
		SC_METHOD(counts);
		sensitive<<clk.pos()<<rst;
	}
};
