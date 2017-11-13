#include "AnalizatorSygnalu.h"
#include "Sygnal.h"
#include "Probka.h"
#include "SygnalLoader.h"
#include "SygnalSinusoidalny.h"
#include "SygnalProbkowany.h"
#include <iostream>
using namespace std;
int main()
{
	string ZnazwaPliku="out.csv", OnazwaPliku="sygnal.csv";
	cout << "Podaj nazwe pliku odczytu: "; cin >> OnazwaPliku;
	cout << "Podaj nazwe pliku zapisu: "; cin >> ZnazwaPliku;
	SygnalLoader sl;
	AnalizatorSygnalu as;
	Sygnal* syg_sin = new SygnalSinusoidalny (1.0, 6.28, 0.0);
	SygnalProbkowany sp = sl.wczytajSygnal( OnazwaPliku );
	cout << "iloscProbek: " << sp.iloscProbek() << endl;
	cout << "maksimum: " << as.maksimum( sp ) << endl;
	cout << "minimum: " << as.minimum( sp ) << endl;
	cout << "srednia: " << as.srednia( sp ) << endl;
	cout << "dlugosc: " << as.dlugosc( sp ) << endl;
	cout << "calka: " << as.calka( sp ) << endl;
	sl.zapiszSygnal( sp, ZnazwaPliku );
	return 0;
}
