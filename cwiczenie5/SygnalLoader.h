#ifndef _SygnalLoader_h_
#define _SygnalLoader_h_
/*====================*/
#include "SygnalProbkowany.h"
#include <iostream>
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
        plik.open( _nazwaPliku.c_str(), ios::in );
        string linia;
        SygnalProbkowany sp;
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
	void zapiszSygnal( SygnalProbkowany& _sygnalp, string _nazwaPliku )
	{
		ofstream plik;
		plik.open( _nazwaPliku.c_str(), ios::out );
		for ( int i = 1; i < _sygnalp.iloscProbek(); ++i )
		{
			plik << _sygnalp[ i ].t << ", " << _sygnalp[ i ].x << endl;
		}
		plik.close();
	}
};
#endif
