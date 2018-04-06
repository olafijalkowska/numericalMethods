/* WIKIPEDIA:
function kahanSum(input, n)
    var sum = input[1]
    var c = 0.0             //Poprawka zawierająca utracone niskie bity.
    for i = 2 to n
        y = input[i] - c
        t = sum + y               //Sum jest względnie duże w porównaniu z y co powoduje utratę bitów mniej znaczących liczby y.
        c = (t - sum) - y         //(t - sum) odzyskuje wyższe bity y; odjęcie y odzyskuje -(niższe bity y)
        sum = t                   
    next i                  //W następnej iteracji utracone niższe bity zostaną dodane do y
    return sum
 */   
    
    
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath> 

int main (int argc, char *argv[]) 
{
    float sum1 = 0.;
    float rest1 = 0.;
    for (float i = 0. ; i <= 10000. ; ++i)
    {
        float y = i - rest1;
        float t = sum1+y;
        rest1 = (t-sum1)-y;
        sum1 = t;
    }
        
        
    float sum2 = 0.;
    float rest2 = 0.;
    for (float i = 10000. ; i != 0. ; --i)
    {
        float y = i - rest2;
        float t = sum2+y;
        rest2 = (t-sum2)-y;
        sum2 = t;
        
        
    }
    std::cout << std::setprecision (15)   << std::setw(20)  << sum1 << " " << sum2 << std::endl;
    return 0;
}
