#ifndef _SygnalLoader_h_
#define _SygnalLoader_h_
/*====================*/
#include "SygnalProbkowany.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
class SygnalLoader
{
public:
	SygnalLoader() {}
	SygnalProbkowany wczytajSygnal( string _nazwaPliku )
	{
		ifstream plik;
		SygnalProbkowany sp;
        plik.open( _nazwaPliku.c_str(), ios::in );
        if( plik.good() == true )
        {
            string linia;
            double liczba1, liczba2;
            char znak;
            while ( getline ( plik, linia ) )
            {
                plik >> liczba1 >> znak >> liczba2;
                sp.dodajProbke( Probka( liczba1, liczba2 ) );
            }
            plik.close();
            return sp;
        }
        else
        {
            cout << "Nie mozna otworzyc pliku - prawdopodobnie nie istenieje lub jest pusty!" << endl;
            return sp;
        }
	}
	void zapiszSygnal( SygnalProbkowany& _sygnalp, string _nazwaPliku )
	{
		ofstream plik;
		plik.open( _nazwaPliku.c_str(), ios::out );
		for ( int i = 0; i < _sygnalp.iloscProbek()-1; i++ )
		{
			plik << _sygnalp[ i ].t << ", " << _sygnalp[ i ].x << endl;
		}
		plik.close();
	}
};
#endif
