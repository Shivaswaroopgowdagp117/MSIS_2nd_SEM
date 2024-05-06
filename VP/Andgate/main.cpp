#include "systemc.h"
#include "andgate.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]) {
    sc_clock clk("clk", 10, SC_NS);

    AndGate a1("a1"), a2("a2"), a3("a3");
    Driver driver("driver", 20);
    Monitor monitor("monitor");

    // Create trace signals for visualization
    sc_trace sig_en("en", driver.en);
    sc_trace sig_sel("sel", driver.sel);
    sc_trace sig_z("z", a3.y);

    sc_start(100, SC_NS);

    // Simulate and display waveforms
    sc_start(0, SC_NS);
    sc_trace_file *wf = sc_create_ waveform_trace_file("decoder_waveform.vcd");
    wf->set_time_unit(1, SC_NS);
    wf->add_signal(sig_en);
    wf->add_signal(sig_sel);
    wf->add_signal(sig_z);
    sc_trace(sc_end_of_simulation, wf->close_file);
    sc_stop();

    return 0;
}
