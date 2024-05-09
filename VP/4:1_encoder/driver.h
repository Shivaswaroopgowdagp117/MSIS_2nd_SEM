#include "systemc.h"
SC_MODULE(driver)
{	sc_out<bool> a0,a1,a2,a3,en;

	void inputs()
	{	
	    en.write(true);
	    int in_arr[] = {0,1,2,4,8};
	    for(int i = 0;i<5;i++){
	    	a0.write(in_arr[i]&0x01);
	    	a1.write(in_arr[i]&0x02);
	    	a2.write(in_arr[i]&0x04);
	    	a3.write(in_arr[i]&0x08);
		wait(5,SC_NS);
	
	    }
	    en.write(false);
	    for(int i = 0;i<5;i++){
	    	a0.write(in_arr[i]&0x01);
	    	a1.write(in_arr[i]&0x02);
	    	a2.write(in_arr[i]&0x04);
	    	a3.write(in_arr[i]&0x08);
		wait(5,SC_NS);
	    }
	}
	
		SC_CTOR(driver)
		{
			SC_THREAD(inputs);
			sensitive <<a0<<a1<<a2<<a3 << en;
		}
};
