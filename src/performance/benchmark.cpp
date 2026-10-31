#include "uew.hpp"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <future>
#include <random>
#include <thread>
namespace uew {
std::vector<BenchRow> run_benchmark(int cases,int elements){
 if(cases<1||elements<1) throw std::invalid_argument("Case count and mesh size must be positive");
 struct Case{double k,q;};std::mt19937 gen(20261031);std::uniform_real_distribution<double> kd(5,25),qd(1000,20000);
 std::vector<Case> batch(cases);for(auto& c:batch)c={kd(gen),qd(gen)};
 auto solve=[&](const Case& x){ThermalConfig c;c.k=x.k;c.q=x.q;c.elements=elements;return solve_thermal(c).T;};
 std::vector<std::vector<double>> reference(cases);for(int i=0;i<cases;i++)reference[i]=solve(batch[i]);
 std::vector<BenchRow> rows;double t1=0;
 for(int p:{1,2,4}){unsigned logical=std::max(1u,std::thread::hardware_concurrency());int workers=std::min<int>(p,logical);
 std::vector<double> times;double diff=0;
 for(int rep=0;rep<5;rep++){auto start=std::chrono::steady_clock::now();std::vector<std::vector<double>> out(cases);
 if(workers==1){for(int i=0;i<cases;i++)out[i]=solve(batch[i]);}
 else {std::atomic<int> next{0};std::vector<std::thread> pool;
 for(int w=0;w<workers;w++)pool.emplace_back([&]{for(;;){int i=next.fetch_add(1);if(i>=cases)break;out[i]=solve(batch[i]);}});
 for(auto& th:pool)th.join();}
 auto end=std::chrono::steady_clock::now();times.push_back(std::chrono::duration<double,std::milli>(end-start).count());
 for(int i=0;i<cases;i++)for(std::size_t j=0;j<out[i].size();j++)diff=std::max(diff,std::abs(out[i][j]-reference[i][j]));
 }
 std::sort(times.begin(),times.end());double med=times[2];if(workers==1)t1=med;rows.push_back({workers,med,0,0,diff});
 }
 for(auto& r:rows){r.speedup=t1/r.median_ms;r.efficiency=r.speedup/r.workers;}return rows;
}
}
