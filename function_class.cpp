#include <cmath>
#include <functional>
#include <iostream>


struct Linear{
    Linear(float k,float b):k_(k),b_(b){}
    float f(float x){return k_*x+b_;}
    float k_, b_;
};

int main(){
    std::function<float(Linear&,float)> mf = &Linear::f;
    Linear l(1.2,2.3);
    float res = mf(l,5);
    std::cout<<res<<std::endl;

    std::function<float(Linear&)> k = &Linear::k_;
    std::cout<<k(l)<<std::endl;

    return 0;
}