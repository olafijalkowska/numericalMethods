#include <iostream>
#include <vector> 
#include <math.h>
#include "gnuplot_i.hpp"


template<typename T>
T myFun(T x)
{
    return sin(x);
}
 
template<typename T>
T derivativeCentralMeth(T x, T h)
{
    
    return (myFun<T>(x+h) - myFun<T>(x-h))/(2.*h);
}

template<typename T>
T derivative(T x)
{
    
    return cos(x);
}

template<typename T>
T getError(T argument, T h)
{
    T der = derivative<T>(argument);
    T derCentral = derivativeCentralMeth<T>(argument, h);
    T err = der - derCentral;
    if(err < 0.)
        err*=-1.;
    return err;
}

int main()
{
   float argument = 2.*M_PI/3.;

   //std::cout << der << " " << derCentral << std::endl;
   std::vector<float> hValues;
   std::vector<float> errValues; 
   for(float h = 1.e-8; h < 10; h*=10.)
   {
       hValues.push_back(h);
       float error = getError(argument, h);
       errValues.push_back(error);
      // std::cout << h << " " <<  error << std::endl;
   
   }
   

   Gnuplot g1 ("lines");
   g1.set_xlogscale();
   g1.set_ylogscale();
   g1.set_style ("points") .plot_xy (hValues, errValues, "Dane") ;

   std::cin.ignore();
  
  
    return 0;
}


