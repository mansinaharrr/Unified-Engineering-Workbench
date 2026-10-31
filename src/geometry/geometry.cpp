#include "uew.hpp"
#include <fstream>
#include <regex>
#include <stdexcept>
#include <sstream>
#include <limits>
#include <cmath>
namespace uew {
GeometryStats inspect_ascii_stl(const std::string& path){
 std::ifstream in(path); if(!in) throw std::runtime_error("Cannot open STL file: "+path);
 GeometryStats s; for(int i=0;i<3;i++){s.min[i]=std::numeric_limits<double>::max();s.max[i]=std::numeric_limits<double>::lowest();}
 std::string line; const std::regex re(R"(^\s*vertex\s+([-+0-9.eE]+)\s+([-+0-9.eE]+)\s+([-+0-9.eE]+))");
 std::smatch m; std::size_t vertices=0;
 while(std::getline(in,line)){if(std::regex_search(line,m,re)){for(int i=0;i<3;i++){double v=std::stod(m[i+1]);if(!std::isfinite(v))throw std::runtime_error("STL contains non-finite vertex");s.min[i]=std::min(s.min[i],v);s.max[i]=std::max(s.max[i],v);}vertices++;}}
 if(vertices==0) throw std::runtime_error("STL is empty or is not supported ASCII STL");
 if(vertices%3) throw std::runtime_error("STL vertex count is not divisible by three");
 s.triangles=vertices/3; return s;
}
std::size_t validate_temperature_csv(const std::string& path){
 std::ifstream in(path);if(!in)throw std::runtime_error("Cannot open CSV file: "+path);
 std::string line;if(!std::getline(in,line)||line!="node_id,x_m,y_m,z_m,temperature_C")throw std::runtime_error("CSV header must be node_id,x_m,y_m,z_m,temperature_C");
 std::size_t count=0;while(std::getline(in,line)){if(line.empty())continue;std::stringstream ss(line);std::string cell;double vals[5];int j=0;while(std::getline(ss,cell,',')){if(j>=5)throw std::runtime_error("Too many CSV columns");std::size_t used=0;vals[j]=std::stod(cell,&used);if(used!=cell.size()||!std::isfinite(vals[j]))throw std::runtime_error("Malformed or non-finite CSV value");j++;}if(j!=5)throw std::runtime_error("Each CSV row must contain five columns");count++;}
 if(!count)throw std::runtime_error("CSV contains a header but no nodes");return count;
}
}
