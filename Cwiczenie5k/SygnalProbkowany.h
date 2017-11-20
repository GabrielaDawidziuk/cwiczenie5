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

		for ( unsigned int i = 0; i < probki.size()-1; i++ )
        {
            if ( t == probki[ 0 ].t )
            {
                return probki[ 0 ].x;
            }
            else if ( t == probki[ probki.size()-2 ].t )
            {
                return probki[ probki.size()- 2 ].x;
            }
			else if ( probki[ i ].t < t && probki[ i + 1 ].t == t )
            {
				xp = probki[ i ].x;
                tp = probki[ i ].t;
                xn = probki[ i + 2 ].x;
                tn = probki[ i + 2 ].t;
                return xp + (( xn - xp )/( tn - tp ))*( t - tp );
            }
        }
	}
	virtual void wypisz(ostream& _stream)
	{
	    _stream << "Ilosc Probek: " << probki.size()-1 << endl;
	}
    void dodajProbke ( const Probka& _p )
	{
		probki.push_back( _p );
	}
	int iloscProbek() const
	{
		return probki.size();
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
