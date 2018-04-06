#include <iostream>
#include <string.h>
#include <sstream>
/*
Napisz procedurę wczytującą liczby typu float z wejścia standardowego. Po wpi-
saniu pustej linii procedura powininna wyświetlić wczytane liczby na ekran w
odwrotnej kolejności.
*/

using namespace std; 

template<typename T>
T* doubleArraySize(T* arrayIn, int size)
{
    T *arrayOut = new T[2*size];
    memcpy (arrayOut, arrayIn, size*sizeof(arrayIn));
    delete arrayIn;
    arrayIn = arrayOut;
    return arrayIn;
}

template<typename T>
T stringToNum(std::string& s, std::ios_base& (*f)(std::ios_base&))
{
        T t;
        std::istringstream iss(s);
        if (!(iss >> f >> t).fail())
                return t;
}





template<typename T>
void FillArray(T* data, int size)
{
    int givenDataNr = 0;
    while(true)
    {
       string stringData;
       getline(std::cin, stringData);
       if (stringData.empty())
           break;
       data[givenDataNr] = stringToNum<T> (stringData, std::dec);
       givenDataNr++;
       if(givenDataNr >= size) 
       {
           data = doubleArraySize(data, size);
           size *=2;
       }      
    }

    for(int i = givenDataNr-1; i >= 0; --i)
    {
        cout << data[i] << " ";
    }
   cout << endl;
}


int main (int argc, char *argv[]) 
{
    int size = 1;
    float* data = new float [size];
    FillArray(data, size);
   return 0;
}


