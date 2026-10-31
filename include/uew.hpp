#pragma once
#include <cstddef>
#include <string>
#include <vector>
namespace uew {
struct ThermalConfig { double L=1.0,A=1e-4,k=10.0,q=10000.0,T0=100.0,TL=20.0; int elements=10; };
struct ThermalResult { std::vector<double> x,T; double midpoint_max_error=0; };
ThermalResult solve_thermal(const ThermalConfig&);
double exact_temperature(double x,const ThermalConfig&);
struct MeshStats { int elements; double max_midpoint_error; };
std::vector<MeshStats> convergence();
struct GeometryStats { std::size_t triangles=0; double min[3]={0,0,0},max[3]={0,0,0}; };
GeometryStats inspect_ascii_stl(const std::string&);
std::size_t validate_temperature_csv(const std::string&);
struct BenchRow { int workers; double median_ms,speedup,efficiency; double max_difference; };
std::vector<BenchRow> run_benchmark(int cases,int elements);
struct DeviceInfo { std::string name,type,capabilities; bool connected=false; };
std::vector<DeviceInfo> mock_devices();
bool mock_telemetry(const std::string& device, bool simulate_timeout, std::string& message);
struct BackpropResult { double h,yhat,loss,dw,db,dv,dc,w2,b2,v2,c2; };
BackpropResult backprop_one_step();
std::vector<double> train_losses(int steps=100);
double finite_difference_gradient(const std::string& parameter,double eps=1e-6);
}
