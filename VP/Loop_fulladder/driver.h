#include "systemc.h"
#include <iostream>
#include <vector>
SC_MODULE(driver)
{
        int counter=0;
        //int<sc_bv> counter=0;
   	sc_out<bool> a1,b1,cin;
        sc_time             t3;
        sc_in<bool> clk;

	void inputs()
	{	
	
	while(counter<8)
	   {
	     
		a1.write(counter & 0x01);
		b1.write(counter & 0x02);
		cin.write(counter & 0x04);
	       
	        t3 = sc_time_stamp();
	        cout <<"Value of t3 "<< t3.to_string() << endl;
	         counter++;
	          wait();
	         }
		
	}
	
		SC_CTOR(driver)
		{
			SC_THREAD(inputs);
			sensitive <<clk.pos();
		}
};
