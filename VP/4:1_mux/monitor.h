#include "systemc.h"
SC_MODULE(monitor)
{

	sc_in<bool> a0;
	sc_in<bool> a1;
	sc_in<bool> a2;
	sc_in<bool> a3;

	sc_in<bool> sel0;
	sc_in<bool> sel1;

	sc_in<bool> out;

	void mon()
	{
		cout << "Inputs: " << a3 << a2 << a1 << a0 << " Sel " << sel1 << sel0 << " Output: " << out << endl;
	}

	SC_CTOR(monitor)
	{
		SC_METHOD(mon);
		sensitive << a0 << a1 << a2 << a3 << sel0 << sel1 << out;
	}
};
