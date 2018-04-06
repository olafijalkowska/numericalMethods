#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
 
double machineEpsilon () 
{
    double epsilon = 1.0;

    do 
    {
       epsilon /= 2.0;
    }
    while ( (1.0 + epsilon/2.0) != 1.0);

    return epsilon;
}

 
int main()
{
    cout << machineEpsilon() << endl;
    cout << numeric_limits<double>::epsilon() << endl;
    return 0;
}
