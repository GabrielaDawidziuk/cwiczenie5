#ifndef _Sygnal_h_
#define _Sygnal_h_
/*==============*/
#include "Probka.h"
#include <iostream>
#include <vector>
using namespace std;
class Sygnal
{
private:
	vector <Probka> probki;
public:
	Sygnal() {}
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
	friend ostream& operator << ( ostream& _stream, const Sygnal& _sygnal );
};
#endif
