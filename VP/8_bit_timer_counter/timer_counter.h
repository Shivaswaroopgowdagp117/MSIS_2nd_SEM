#include "systemc.h"
SC_MODULE(counter)
{

       sc_bv<8> ctrl=0;
       sc_bv<8> value=0;
       sc_bv<8> compare=0;
       sc_bv<8> interrupt=0;
       
	sc_in<bool> clk;
	
	void compute_result()
	{
	
	        value++;
	        if(ctrl & 0x1)
	        {
	           if(ctrl & 0x02)
	           {
	             value==compare;
	             cout<< "The value get matched"<<endl;
	             }
	             if(ctrl & 0x04)
	           {
	             if(value==0xFF)
	               value=0;
	         }}
	         if(value==255 && !(ctrl & 0x04))
	         value=254; 
		
	}
	SC_CTOR(counter)
	{
		SC_METHOD(compute_result);
		sensitive << clk.pos();
	}
};
