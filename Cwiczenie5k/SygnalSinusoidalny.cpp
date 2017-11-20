#ifndef _SygnalSinusoidalny_h_
#define _SygnalSinusoidalny_h_
/*==========================*/
#include "Sygnal.h"
#include <math.h>
#include <iostream>
class SygnalSinusoidalny: public Sygnal
{
private:
    double a;
    double w;
    double psi;
public:
    SygnalSinusoidalny( double _a = 1.0, double _w = 1.0, double _psi = 0.0 )
    : a( _a ), w( _w * 3.14 ), psi( _psi ) {}
    virtual ~SygnalSinusoidalny() {}
    virtual double x( double t )
    {
        return a * sin( w * t + psi );
    }
    virtual void wypisz( ostream& _stream )
    {
        _stream << "Sygnal sinusoidalny [" << endl;
        _stream << "a : " << a << endl;
        _stream << "w : " << w << endl;
        _stream << "psi : " << psi << " ]" << endl;
    }
};
#endif // _SygnalSinusoidalny_h_

