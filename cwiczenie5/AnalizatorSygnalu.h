
#ifndef _AnalizatorSygnalu_h_
#define _AnalizatorSygnalu_h_
/*=========================*/
#include "SygnalProbkowany.h"
#include <iostream>
using namespace std;
class AnalizatorSygnalu
{
public:
	AnalizatorSygnalu() {}
	double dlugosc( const SygnalProbkowany& _sygnalp )
	{
		double _min = _sygnalp[ 1 ].x;
		double _max = _sygnalp[ 1 ].x;
		for ( int i = 1; i < _sygnalp.iloscProbek() - 2; i++ )
		{
			if ( _sygnalp[ i ].x < _min )
				_min = _sygnalp[ i ].x;
			if ( _sygnalp[ i ].x > _max )
				_max = _sygnalp[ i ].x;
		}
		return _max - _min;
	}

	double minimum( const SygnalProbkowany& _sygnalp )
	{
		double _min = _sygnalp[ 1 ].x;
		for ( int i = 1; i < _sygnalp.iloscProbek() - 2; i++ )
			if ( _sygnalp[ i ].x < _min )
				_min = _sygnalp[ i ].x;
		return _min;
	}

	double maksimum( const SygnalProbkowany& _sygnalp )
	{
		double _max = _sygnalp[ 1 ].x;
		for ( int i = 1; i < _sygnalp.iloscProbek() - 2; i++ )
			if ( _sygnalp[ i ].x > _max )
				_max = _sygnalp[ i ].x;
		return _max;
	}

	double srednia( const SygnalProbkowany& _sygnalp )
	{
		double m = 0.0;
		for ( int i = 1; i < _sygnalp.iloscProbek() - 2; i++ )
			m += _sygnalp[ i ].x;
		if ( _sygnalp.iloscProbek() > 0 )
			m /= _sygnalp.iloscProbek() - 2;
		return m;
	}

	double calka( const SygnalProbkowany& _sygnalp )
	{
		double calka = 0, dt = 0, dpole = 0;
	    for (int i = 1; i < _sygnalp.iloscProbek() - 2; i++ )
	    {
	        dt = _sygnalp[ i + 1 ].t - _sygnalp[ i ].t;
	        dpole = ( _sygnalp[ i ].x + _sygnalp[ i + 1 ].x ) * dt / 2;
	        calka = calka + dpole;
	    }
	    return calka;
	}
};
#endif
