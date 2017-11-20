#ifndef _Sygnal_h_
#define _Sygnal_h_
/*==============*/
#include "Probka.h"
#include <iostream>
using namespace std;
class Sygnal
{
public:
    virtual ~Sygnal() {}
	virtual double x( double t) = 0;
	virtual void wypisz(ostream& _stream) = 0;
	friend ostream& operator << ( ostream& _stream, Sygnal& _sygnal )
	{
	    _sygnal.wypisz(_stream);
	    return _stream;
	}
};
#endif
