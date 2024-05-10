#include<systemc.h>

SC_MODULE(driver)
{
	sc_out<bool>rst;
	sc_in<bool>clk;

	void counting(){

  		wait(5,SC_NS);
   		rst.write(true);
   		wait(5,SC_NS);
   		rst.write(false);
   
   		wait(5,SC_NS);
   		rst.write(true);
   		wait(5,SC_NS);
   		rst.write(false);
   
 	        wait(5,SC_NS);
   		rst.write(true);
   		wait(5,SC_NS);
   		rst.write(false);
   
   	sc_stop();
   }
   
   	SC_CTOR(driver){
   		SC_THREAD(counting);
  	 	sensitive<<clk.pos()<<rst;
  	 }
 };
