#include "systemc.h"
SC_MODULE(driver)
{	sc_out<bool> a1,b1,c1;

	void inputs()
	{	
		a1.write(false);
		b1.write(false);
		c1.write(false); wait(5,SC_NS);
	
		a1.write(false);
		b1.write(false);
		c1.write(true); wait(5,SC_NS); 
		
		a1.write(false);
		b1.write(true);
		c1.write(false); wait(5,SC_NS);
		
		a1.write(false);
		b1.write(true);
		c1.write(true); wait(5,SC_NS);
		
		a1.write(true);
		b1.write(false);
		c1.write(false); wait(5,SC_NS);
		
		a1.write(true);
		b1.write(false);
		c1.write(true); wait(5,SC_NS);
		
		a1.write(true);
		b1.write(true);
		c1.write(false); wait(5,SC_NS);
		
		a1.write(true);
		b1.write(true);
		c1.write(true); wait(5,SC_NS);
		}
	
		SC_CTOR(driver)
		{
			SC_THREAD(inputs);
			sensitive <<a1 <<b1 <<c1;
		}
};
