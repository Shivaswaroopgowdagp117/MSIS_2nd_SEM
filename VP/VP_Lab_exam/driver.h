#include <systemc.h>

SC_MODULE(driver)
{

	sc_out<bool>rst;
	sc_in<bool>clk;
	void input(){
	
	
	
	
		rst.write(true);
		wait(2,SC_NS);
		rst.write(true);
		wait(2,SC_NS);
		
		
		
		rst.write(false);
		wait(5,SC_NS);
		
		rst.write(false);
		wait(5,SC_NS);
		
		rst.write(false);
		wait(5,SC_NS);
		
		rst.write(false);
		wait(5,SC_NS);
		
		rst.write(false);
		wait(5,SC_NS);
		
		
		rst.write(false);
		wait(5,SC_NS);
		
		
		rst.write(false);
		wait(5,SC_NS);
		
		
		rst.write(false);
		wait(5,SC_NS);
		
	}
	SC_CTOR(driver){
		SC_THREAD(input);
		sensitive<<clk.pos();
	}
	
	

};
