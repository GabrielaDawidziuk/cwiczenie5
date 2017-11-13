#ifndef _SygnalProbkowany_h_
#define _SygnalProbkowany_h_
/*==============*/
#include "Sygnal.h"
#include <iostream>
#include <vector>
using namespace std;
class SygnalProbkowany: public Sygnal
{
private:
	vector <Probka> probki;
public:
	SygnalProbkowany() {}
	virtual double x( double t)
	{
        double xp, tp, xn, tn;

		for ( int i = 1; i < probki.size() - 2; i++ )
			if ( probki[ i ].t < t && probki[ i + 1 ].t == t )
            {
				xp = probki[ i ].x;
                tp = probki[ i ].t;
                xn = probki[ i + 2 ].x;
                tn = probki[ i + 2 ].t;
            }

		return xp + ((xn - xp)/(tn-tp))*(t-tp);
	}
	virtual void wypisz(ostream& _stream)
	{
	    _stream << "wypisz";
	}
    void dodajProbke ( const Probka& _p )
	{
		probki.push_back( _p );
	}
	int iloscProbek() const
	{
		return probki.size() - 2;
	}
    Probka& operator []( int i )
	{
		return probki[ i ];
	}
	const Probka& operator []( int i ) const
	{
		return probki[ i ];
	}
	friend ostream& operator << ( ostream& _stream, const SygnalProbkowany& _sygnal );
};
#endif

