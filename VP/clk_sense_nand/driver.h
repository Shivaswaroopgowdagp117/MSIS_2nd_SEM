#include "systemc.h"
SC_MODULE(driver)
{	sc_out<bool> a1,b1;
        sc_time             t3;
        sc_in<bool> clk;

	void inputs()
	{	 wait();
		a1.write(false);
		b1.write(false);
	        //wait(2,SC_NS);
	         //wait();
	        t3 = sc_time_stamp();
	        cout <<"Value of t3 "<< t3.to_string() << endl;
	       wait();
		a1.write(false);
		b1.write(true);
		   
		 //wait(2,SC_NS);
		  t3 = sc_time_stamp();
	        cout <<"Value of t3 "<< t3.to_string() << endl;
	         wait(); 
		a1.write(true);
		b1.write(false);
		 
		// wait(2,SC_NS);
		  t3 = sc_time_stamp();
	        cout <<"Value of t3 "<< t3.to_string() << endl;
	       
		  wait(); 
		a1.write(true);
		b1.write(true);
		
		// wait(2,SC_NS);
		  t3 = sc_time_stamp();
	        cout <<"Value of t3 "<< t3.to_string() << endl;
		
		
		wait();
		}
	
		SC_CTOR(driver)
		{
			SC_THREAD(inputs);
			sensitive <<clk.pos();
		}
};
