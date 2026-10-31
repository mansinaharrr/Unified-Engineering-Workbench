#include "uew.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <stdexcept>
void check(bool ok,const char* msg){if(!ok)throw std::runtime_error(msg);}
int main(){try{
 uew::ThermalConfig c;c.elements=40;auto r=uew::solve_thermal(c);
 check(std::abs(r.T.front()-100)<1e-10,"left boundary");check(std::abs(r.T.back()-20)<1e-10,"right boundary");
 check(r.midpoint_max_error<0.1,"thermal midpoint error");
 auto bp=uew::backprop_one_step();
 check(std::abs(bp.dw-uew::finite_difference_gradient("w"))<1e-5,"gradient w");
 check(std::abs(bp.db-uew::finite_difference_gradient("b"))<1e-5,"gradient b");
 check(std::abs(bp.dv-uew::finite_difference_gradient("v"))<1e-5,"gradient v");
 check(std::abs(bp.dc-uew::finite_difference_gradient("c"))<1e-5,"gradient c");
 auto dev=uew::mock_devices();check(dev.size()==3,"three mock devices");
 std::string msg;check(!uew::mock_telemetry(dev[0].name,true,msg),"timeout recovery path");
 std::ofstream stl("test_triangle.stl");stl<<"solid t\n facet normal 0 0 1\n outer loop\n vertex 0 0 0\n vertex 1 0 0\n vertex 0 1 0\n endloop\n endfacet\nendsolid\n";stl.close();
 check(uew::inspect_ascii_stl("test_triangle.stl").triangles==1,"STL parser");
 std::ofstream csv("test_nodes.csv");csv<<"node_id,x_m,y_m,z_m,temperature_C\n1,0,0,0,100\n";csv.close();check(uew::validate_temperature_csv("test_nodes.csv")==1,"CSV parser");
 auto b=uew::run_benchmark(8,10);check(b.size()==3,"benchmark worker configurations");check(b[0].max_difference<=1e-8,"parallel agreement");
 std::cout<<"ALL TESTS PASSED\n";return 0;
 }catch(const std::exception& e){std::cerr<<"TEST FAILURE: "<<e.what()<<"\n";return 1;}}
