#include "uew.hpp"
#include <cmath>
#include <stdexcept>
namespace uew {
namespace {struct P{double w=.5,b=0,v=1,c=0;};double loss(P p){double h=std::tanh(p.w+p.b), y=p.v*h+p.c;return .5*(y-2)*(y-2);}
}
BackpropResult backprop_one_step(){
 P p;double h=std::tanh(p.w+p.b),yh=p.v*h+p.c,e=yh-2,dl=e;
 double dv=dl*h,dc=dl,dh=dl*p.v,dz=dh*(1-h*h),dw=dz,db=dz,lr=.1;
 return {h,yh,.5*e*e,dw,db,dv,dc,p.w-lr*dw,p.b-lr*db,p.v-lr*dv,p.c-lr*dc};
}
std::vector<double> train_losses(int steps){P p;std::vector<double> out;for(int i=0;i<steps;i++){out.push_back(loss(p));double h=std::tanh(p.w+p.b),e=p.v*h+p.c-2;double dv=e*h,dc=e,dz=e*p.v*(1-h*h);p.w-=.1*dz;p.b-=.1*dz;p.v-=.1*dv;p.c-=.1*dc;}return out;}
double finite_difference_gradient(const std::string& name,double eps){P p;double* v=nullptr;if(name=="w")v=&p.w;else if(name=="b")v=&p.b;else if(name=="v")v=&p.v;else if(name=="c")v=&p.c;else throw std::invalid_argument("Parameter must be w, b, v or c");double orig=*v;*v=orig+eps;double plus=loss(p);*v=orig-eps;double minus=loss(p);return (plus-minus)/(2*eps);}
}
