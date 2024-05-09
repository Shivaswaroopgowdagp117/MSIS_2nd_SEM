#include "systemc.h"
SC_MODULE(driver)
{	sc_out<bool> a1,a2,en;

	void inputs()
	{	
	    en.write(true);
	    for(int i = 0;i<4;i++){
		a1.write(i&0x01);
		a2.write(i&0x02);
		wait(5,SC_NS);
	
	    }
	    en.write(false);
	    for(int i = 0;i<4;i++){
		a1.write(i&0x01);
		a2.write(i&0x02);
		wait(5,SC_NS);
	
	    }
	}
	
		SC_CTOR(driver)
		{
			SC_THREAD(inputs);
			sensitive <<a1 <<a2 << en;
		}
};
