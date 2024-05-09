#include "systemc.h"
SC_MODULE(driver)
{

	sc_out<bool> a0;
	sc_out<bool> a1;
	sc_out<bool> a2;
	sc_out<bool> a3;

	sc_out<bool> sel0;
	sc_out<bool> sel1;

	void inputs()
	{
		for (int j = 0; j < 16; j++)
		{
			a0.write(j & 0x01);
			a1.write(j & 0x02);
			a2.write(j & 0x04);
			a3.write(j & 0x08);
			for (int i = 0; i < 4; i++)
			{
				sel0.write(i & 0x01);
				sel1.write(i & 0x02);
				wait(5, SC_NS);
			}
		}
	}

	SC_CTOR(driver)
	{
		SC_THREAD(inputs);
		sensitive << a0 << a1 << a2 << a3 << sel0 << sel1;
	}
};
