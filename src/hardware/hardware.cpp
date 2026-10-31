#include "uew.hpp"
#include <stdexcept>
namespace uew {
std::vector<DeviceInfo> mock_devices(){return {
 {"STM32 Nucleo (mock)","Microcontroller","USB CDC telemetry; 3.3 V GPIO; simulated"},
 {"Basys 3 (mock)","FPGA","JTAG configuration/debug; 3.3 V I/O; simulated"},
 {"USB-JTAG adapter (mock)","Debug adapter","TCK/TMS/TDI/TDO; host USB; simulated"}
};}
bool mock_telemetry(const std::string& device,bool timeout,std::string& message){
 if(timeout){message="Recoverable timeout: no telemetry received; device remains disconnected.";return false;}
 if(device!="STM32 Nucleo (mock)"&&device!="Basys 3 (mock)"&&device!="USB-JTAG adapter (mock)")throw std::invalid_argument("Unknown mock device");
 message="SIMULATED telemetry from "+device+": status=OK, sequence=1";return true;
}
}
