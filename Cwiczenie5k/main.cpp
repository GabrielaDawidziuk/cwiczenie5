#include "AnalizatorSygnalu.h"
#include "Sygnal.h"
#include "Probka.h"
#include "SygnalLoader.h"
#include "SygnalSinusoidalny.h"
#include "SygnalProbkowany.h"
#include <iostream>
#include "math.h"
using namespace std;
int main()
{
	string ZnazwaPliku, OnazwaPliku, Z2nazwaPliku;
	cout << "Podaj nazwe pliku odczytu: "; cin >> OnazwaPliku;
	cout << "Podaj nazwe pliku zapisu: "; cin >> ZnazwaPliku;
	cout << "Podaj nazwe pliku zapisu roznicy: "; cin >> Z2nazwaPliku;
	SygnalLoader sl;
	AnalizatorSygnalu as;
	Sygnal* syg_sin = new SygnalSinusoidalny(1.0, 2.0, 0.0);
	SygnalProbkowany sp = sl.wczytajSygnal( OnazwaPliku );
	if ( sp.iloscProbek() > 0)
    {
        sp.wypisz( cout );
        cout << "maksimum: " << as.maksimum( sp ) << endl;
        cout << "minimum: " << as.minimum( sp ) << endl;
        cout << "srednia: " << as.srednia( sp ) << endl;
        cout << "dlugosc: " << as.dlugosc( sp ) << endl;
        cout << "calka: " << as.calka( sp ) << endl;
        cout << "sygnalsin: " << as.sygnalsin( syg_sin, 0.30) << endl;
        SygnalProbkowany sr;
        for ( int i = 0; i < sp.iloscProbek(); i++ )
        {
            sr.dodajProbke( Probka( sp[ i ].t, sp.x( sp[ i ].t ) - as.sygnalsin( syg_sin, sp[ i ].t)));
        }
        cout << "calka z roznicy: " << as.calka( sr ) << endl;
        cout << "srednia z roznicy: " << as.srednia( sr ) << endl;
        sl.zapiszSygnal( sp, ZnazwaPliku );
        sl.zapiszSygnal( sr, Z2nazwaPliku);
        return 0;
    }
}
