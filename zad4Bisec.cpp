#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

/*

Epsilon maszynowy jest wartością określającą precyzję obliczeń numerycznych wykonywanych na liczbach zmiennoprzecinkowych.

Jest to największa liczba nieujemna, której dodanie do jedności daje wynik równy 1. Innymi słowy, 1 + ε = 1 i żadna liczba większa od ε nie spełnia już tego warunku. (Zwróćmy uwagę, że 0.0 też jest taką liczbą, ale w realnych arytmetykach zmiennoprzecinkowych - nie jedyną)

Im mniejsza wartość epsilona maszynowego, tym większa jest względna precyzja obliczeń. Wartości tej nie należy mylić ze (zwykle dużo niższą) najmniejszą liczbą uznawaną przez maszynę za różną od zera.

Epsilon maszynowy jest zależny od implementacji. Precyzja obliczeń jest ograniczona od strony sprzętowej przez rozmiar rejestrów, na których są wykonywane obliczenia, a od strony programowej przez typ danych użyty do reprezentowania liczb zmiennoprzecinkowych.


*/

 
float machineEpsilon () 
{
    float epsilon = 1.0;

    while ( (float)(1.0 + epsilon/2.0) != (float)1.0)
    {
    
        epsilon /= 2.0;
    }
    return epsilon;
}

 
int main()
{
    cout << machineEpsilon() << endl;
    cout << numeric_limits<float>::epsilon() << endl;
    return 0;
}
