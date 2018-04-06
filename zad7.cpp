/*

Napisz program alokujący dynamicznie tablice liczb całkowitych o wczytanym
rozmiarze. Następnie program powinien wyzerować podaną liczbę elementów z
początku tablicy lub nie, w zależności od wyboru użytkownika. Po tym użyt-
kownik zdecyduje, czy zwolnić zaalokowaną pamięć i następnie kiedy zakończyć
program.

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n = 0, ile = 0;
	string yn = "";
	cout << "Podaj rozmiar tablicy: ";
	cin >> n;
	int *tab = new int[n];
	for(int i = 0; i < n; i++)
		tab[i] = 1;
		
	cout << "Zeruj elementy? (t/n) ";
	cin >> yn;
	if(yn == "t" || yn == "T"){
		cout << "Ile elementów? ";
		cin >> ile;
		for(int i = 0; i < ile; i++)
			tab[i] = 0;
		}
		
	for(int i = 0; i <= ile; i++)
		cout << tab[i] << endl;
		
	cout << "Zwolnić pamięć? (t/n) ";
	cin >> yn;
	if(yn == "t" || "T")
		delete[] tab;
	cout << tab[1] << endl;
	
	do{
		cout << "Zakończyć program? (t/n) ";
		cin >> yn;
	}
	while(yn != "t" && yn != "T");
	
	return 0;
}
