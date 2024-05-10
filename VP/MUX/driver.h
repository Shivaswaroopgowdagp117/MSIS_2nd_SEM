//driver.h
#include <systemc.h>
SC_MODULE(driver)
{
	sc_out<bool> a,b,c,d,s0,s1;

	void inputs()
	{
		a.write(true);
		b.write(false);
		c.write(true);
		d.write(false);
		s0.write(false);
		s1.write(false);wait(5, SC_NS);
		
		a.write(true);
		b.write(false);
		c.write(true);
		d.write(false);
		s0.write(true);
		s1.write(false);wait(5, SC_NS);
		
		a.write(true);
		b.write(false);
		c.write(true);
		d.write(false);
		s0.write(false);
		s1.write(true);wait(5, SC_NS);
		
		a.write(true);
		b.write(false);
		c.write(true);
		d.write(false);
		s0.write(true);
		s1.write(true);wait(5, SC_NS);
		
	}
		SC_CTOR(driver)
		{
			SC_THREAD(inputs);
			sensitive <<a<<b<<c<<d<<s0<<s1;
		}
	
};
