#include "systemc.h"
SC_MODULE(driver)
{
	sc_out<bool> d_in;
	sc_in<bool> clk;
	sc_time t3;

	void inputs()
	{
		for (int i = 0; i < 4; i++)
		{
			d_in.write(false);
			
			wait();

			t3 = sc_time_stamp();
			cout << "Value of t3 " << t3.to_string() << endl;

			d_in.write(true);
			
			wait();

			t3 = sc_time_stamp();
			cout << "Value of t3 " << t3.to_string() << endl;
		}
	}

	SC_CTOR(driver)
	{
		SC_THREAD(inputs);
		sensitive << clk.pos();
	}
};
