//driver.h
#include <systemc.h>
SC_MODULE(driver)
{
	sc_out<bool> t;
	sc_in<bool> clk;

	void inputs()
	{
		wait();
		t.write(false);
		wait();
		t.write(true);
		wait();
	}
		SC_CTOR(driver)
		{
			SC_THREAD(inputs);
			sensitive <<clk.pos();
		}
	
};
