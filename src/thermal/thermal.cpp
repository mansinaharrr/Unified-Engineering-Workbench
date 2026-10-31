#include "uew.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>
namespace uew {
double exact_temperature(double x,const ThermalConfig& c) {
 return c.T0+(c.TL-c.T0)*x/c.L+(c.q/(2*c.k))*x*(c.L-x);
}
ThermalResult solve_thermal(const ThermalConfig& c) {
 if(c.L<=0||c.A<=0||c.k<=0||c.elements<1) throw std::invalid_argument("L, A, k and element count must be positive");
 int n=c.elements; double h=c.L/n;
 std::vector<double> K(n+1,0), rhs(n+1,0);
 // Tridiagonal assembly for a uniform two-node linear-element mesh.
 // ke = kA/h [[1,-1],[-1,1]], fe = qAh/2 [1,1].
 double d=c.k*c.A/h, f=c.q*c.A*h/2;
 std::vector<double> diag(n+1,0), off(n,0);
 for(int e=0;e<n;e++){diag[e]+=d;diag[e+1]+=d;off[e]-=d;rhs[e]+=f;rhs[e+1]+=f;}
 // Eliminate prescribed T(0), T(L) correctly from the interior equations.
 std::vector<double> a(n+1,0), b(n+1,0), cc(n+1,0), r=rhs;
 for(int i=0;i<=n;i++){b[i]=diag[i]; if(i>0)a[i]=off[i-1]; if(i<n)cc[i]=off[i];}
 b[0]=1; cc[0]=0; r[0]=c.T0;
 r[1]-=a[1]*c.T0; a[1]=0;
 b[n]=1; a[n]=0; r[n]=c.TL;
 r[n-1]-=cc[n-1]*c.TL; cc[n-1]=0;
 // Thomas algorithm.
 for(int i=1;i<=n;i++){double m=a[i]/b[i-1];b[i]-=m*cc[i-1];r[i]-=m*r[i-1];}
 std::vector<double> T(n+1); T[n]=r[n]/b[n];
 for(int i=n-1;i>=0;i--) T[i]=(r[i]-cc[i]*T[i+1])/b[i];
 ThermalResult out; out.T=T; out.x.resize(n+1);
 for(int i=0;i<=n;i++) out.x[i]=i*h;
 for(int e=0;e<n;e++){double xm=(e+0.5)*h;double fem=0.5*(T[e]+T[e+1]);out.midpoint_max_error=std::max(out.midpoint_max_error,std::abs(fem-exact_temperature(xm,c)));}
 return out;
}
std::vector<MeshStats> convergence(){std::vector<MeshStats> v;for(int n:{10,20,40,80}){ThermalConfig c;c.elements=n;v.push_back({n,solve_thermal(c).midpoint_max_error});}return v;}
}
