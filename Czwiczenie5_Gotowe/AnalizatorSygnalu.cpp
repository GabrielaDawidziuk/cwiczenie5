#ifndef _AnalizatorSygnalu_h_
#define _AnalizatorSygnalu_h_
/*=========================*/
#include "Sygnal.h"
#include <iostream>
using namespace std;
class AnalizatorSygnalu
{
public:
	AnalizatorSygnalu() {}
	double dlugosc( const Sygnal& _sygnal )
	{
		double _min = _sygnal[ 1 ].x;
		double _max = _sygnal[ 1 ].x;
		for ( int i = 1; i < _sygnal.iloscProbek() - 2; i++ )
		{
			if ( _sygnal[ i ].x < _min )
				_min = _sygnal[ i ].x;
			if ( _sygnal[ i ].x > _max )
				_max = _sygnal[ i ].x;
		}
		return _max - _min;
	}

	double minimum( const Sygnal& _sygnal )
	{
		double _min = _sygnal[ 1 ].x;
		for ( int i = 1; i < _sygnal.iloscProbek() - 2; i++ )
			if ( _sygnal[ i ].x < _min )
				_min = _sygnal[ i ].x;
		return _min;
	}

	double maksimum( const Sygnal& _sygnal )
	{
		double _max = _sygnal[ 1 ].x;
		for ( int i = 1; i < _sygnal.iloscProbek() - 2; i++ )
			if ( _sygnal[ i ].x > _max )
				_max = _sygnal[ i ].x;
		return _max;
	}

	double srednia( const Sygnal& _sygnal )
	{
		double m = 0.0;
		for ( int i = 1; i < _sygnal.iloscProbek() - 2; i++ )
			m += _sygnal[ i ].x;
		if ( _sygnal.iloscProbek() > 0 )
			m /= _sygnal.iloscProbek() - 2;
		return m;
	}

	double calka( const Sygnal& _sygnal )
	{
		double calka = 0, dt = 0, dpole = 0;
	    for (int i = 1; i < _sygnal.iloscProbek() - 2; i++ )
	    {
	        dt = _sygnal[ i + 1 ].t - _sygnal[ i ].t;
	        dpole = ( _sygnal[ i ].x + _sygnal[ i + 1 ].x ) * dt / 2;
	        calka = calka + dpole;
	    }
	    return calka;
	}
};
#endif
