#ifndef _SygnalLoader_h_
#define _SygnalLoader_h_
/*====================*/
#include "Sygnal.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class SygnalLoader
{
public:
	SygnalLoader() {}
	Sygnal wczytajSygnal( string _nazwaPliku )
	{
		ifstream plik;
        plik.open( _nazwaPliku.c_str(), ios::in );
        string linia;
        Sygnal s;
        double liczba1, liczba2;
        char znak;
        while ( getline ( plik, linia ) )
        {
	        plik >> liczba1 >> znak >> liczba2;
        	s.dodajProbke( Probka( liczba1, liczba2 ) );
        }
        plik.close();
        return s;
	}
	void zapiszSygnal( Sygnal& _sygnal, string _nazwaPliku )
	{
		ofstream plik;
		plik.open( _nazwaPliku.c_str(), ios::out );
		for ( int i = 1; i < _sygnal.iloscProbek(); ++i )
		{
			plik << _sygnal[ i ].t << ", " << _sygnal[ i ].x << endl;
		}
		plik.close();
	}
};
#endif
