#include<systemc.h>

SC_MODULE(logic)
{
	sc_in<bool>clk,rst;
	sc_out<sc_uint<4>>count;

	sc_uint<4> counter;

	void method(){
		if(rst.read()){
			counter= 0;
			count.write(counter);
		}
		else{
			counter = (counter+1)%9;
			count.write(counter);
		}
	}

	SC_CTOR(logic){
		SC_METHOD(method);
	sensitive<<clk.pos()<<rst;
	}
};

