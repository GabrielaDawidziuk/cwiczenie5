#ifndef _SygnalSinusoidalny_h_
#define _SygnalSinusoidalny_h_
/*==========================*/
#include "Sygnal.h"
#include <math.h>
#include <iostream>
class SygnalSinusoidalny: public Sygnal
{
private:
    double _a;
    double _w;
    double _psi;
public:
    SygnalSinusoidalny( double a=1.0, double w=1.0, double psi=0.0 ):_a(a), _w(w), _psi(psi) {}
    virtual ~SygnalSinusoidalny() {}
    virtual double x( double t )
    {
        return _a * sin(_w * t + _psi);
    }
    virtual void wypisz( ostream& _stream )
    {
        _stream << "Sygnal sinusoidalny" << endl;
        _stream << " - a= " << _a << endl;
        _stream << " - w= " << _w << endl;
        _stream << " - psi= " << _psi << endl;
    }
};
#endif // _SygnalSinusoidalny_h_
