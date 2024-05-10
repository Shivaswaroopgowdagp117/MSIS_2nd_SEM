//driver.h
#include <systemc.h>
SC_MODULE(driver)
{
	sc_out<bool> d;
	sc_in<bool> clk;

	void inputs()
	{
		wait();
		d.write(false);
		wait();
		d.write(true);
		wait();
	}
		SC_CTOR(driver)
		{
			SC_THREAD(inputs);
			sensitive <<clk.pos();
		}
	
};
