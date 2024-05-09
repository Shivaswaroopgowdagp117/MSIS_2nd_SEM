#include "systemc.h"
SC_MODULE(fsm){
sc_in<bool> rst, in, clk;
sc_out<bool> out;
sc_uint<2> state,next_state;
void update_state(){
if (rst.read() == true){
	state = 0; }
else {
   state = next_state; }
}
void ns_logic(){
// Determine next state and output
switch(state) {
case 0:
	if (in.read()) {
	next_state = 1;
	out=0;}
	else {
	next_state = 0; 
	out=0;} 
break; 	
case 1:
	if (in.read()){
	next_state = 1;out=0;}
	else{
	next_state = 2;out=0;}
	break;
case 2:
	if (in.read()){
	next_state = 1;out=1;}
	else{
	next_state = 0;out=0;}
	break;
default:
	{
	next_state = 0;out=0;}
	break;
	}
}
SC_CTOR(fsm){
SC_METHOD(update_state);
sensitive << clk.pos()<<rst;
SC_METHOD(ns_logic);
sensitive <<clk.pos()<<in<<rst;
}};

