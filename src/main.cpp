#include "uew.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <thread>
int main(int argc,char** argv){
 try{
 std::string cmd=argc>1?argv[1]:"summary";
 if(cmd=="thermal"){for(int n:{10,20,40,80}){uew::ThermalConfig c;c.elements=n;auto r=uew::solve_thermal(c);std::cout<<"N="<<n<<" midpoint_max_error_C="<<std::setprecision(12)<<r.midpoint_max_error<<"\n";std::ofstream f("results/thermal_N"+std::to_string(n)+".csv");f<<"x_m,temperature_C,exact_C\n";for(size_t i=0;i<r.x.size();i++)f<<r.x[i]<<","<<r.T[i]<<","<<uew::exact_temperature(r.x[i],c)<<"\n";}}
 else if(cmd=="geometry"&&argc>2){auto s=uew::inspect_ascii_stl(argv[2]);std::cout<<"triangles="<<s.triangles<<"\n";for(int i=0;i<3;i++)std::cout<<"axis"<<i<<" min="<<s.min[i]<<" max="<<s.max[i]<<"\n";}
 else if(cmd=="csv"&&argc>2)std::cout<<"validated_nodes="<<uew::validate_temperature_csv(argv[2])<<"\n";
 else if(cmd=="benchmark"){int cases=argc>2?std::stoi(argv[2]):2000,e=argc>3?std::stoi(argv[3]):80;std::cout<<"workers,median_ms,speedup,efficiency,max_difference_C\n";for(auto r:uew::run_benchmark(cases,e))std::cout<<r.workers<<","<<r.median_ms<<","<<r.speedup<<","<<r.efficiency<<","<<r.max_difference<<"\n";}
 else if(cmd=="backprop"){auto r=uew::backprop_one_step();std::cout<<std::setprecision(12)<<"h="<<r.h<<" yhat="<<r.yhat<<" loss="<<r.loss<<"\n"<<"dw="<<r.dw<<" db="<<r.db<<" dv="<<r.dv<<" dc="<<r.dc<<"\n"<<"updated w="<<r.w2<<" b="<<r.b2<<" v="<<r.v2<<" c="<<r.c2<<"\n";for(auto p:{"w","b","v","c"})std::cout<<"finite_difference_"<<p<<"="<<uew::finite_difference_gradient(p)<<"\n";std::ofstream f("results/backprop_loss.csv");f<<"step,loss\n";auto losses=uew::train_losses(100);for(size_t i=0;i<losses.size();i++)f<<i<<","<<losses[i]<<"\n";}
 else if(cmd=="hardware"){for(auto d:uew::mock_devices())std::cout<<d.name<<" | "<<d.type<<" | "<<d.capabilities<<"\n";std::string m;uew::mock_telemetry("STM32 Nucleo (mock)",false,m);std::cout<<m<<"\n";uew::mock_telemetry("STM32 Nucleo (mock)",true,m);std::cout<<m<<"\n";}
 else {std::cout<<"Unified Engineering Workbench C++ core\nCommands: thermal | geometry <file.stl> | csv <file.csv> | benchmark [cases] [elements] | backprop | hardware\n";std::cout<<"Logical CPUs: "<<std::thread::hardware_concurrency()<<"\n";}
 return 0;
 }catch(const std::exception& e){std::cerr<<"ERROR: "<<e.what()<<"\n";return 2;}
}
