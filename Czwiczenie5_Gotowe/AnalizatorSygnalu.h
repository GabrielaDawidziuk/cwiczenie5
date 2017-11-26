/**
 * @file AnalizatorSygnalu.h
 * @author Gabriela Dawidziuk
 * @date 26-11-2017
 * @brief Plik naglowkowy klasy AnalizatorSygnalu
 */
#ifndef _AnalizatorSygnalu_h_
#define _AnalizatorSygnalu_h_
#include "SygnalProbkowany.h"
#include <iostream>
/**
 * @class AnalizatorSygnalu
 * @brief Klasa zawierajaca funkcje obliczajace wybrane wartosci ( wlasciwosci ) sygnalu.
 */
class AnalizatorSygnalu
{
public:
    //! @brief Konstruktor bez parametrow.
	AnalizatorSygnalu() {}
    /**
     * @brief Funkcja obliczajaca najmniejsza wartosc sygnalu
     *
     * Najpierw pierwszy element x probki zostaje ustawiony jako najmniejszy, nastepnie przy uzyciu petli
     * wszystkie probki zostaja sprawdzone - czy sa mniejsze od zmiennej przechowujacej wartosc minimalna,
     * jezeli tak to zostaje zamieniona z wartoscia sprawdzana.
     * @return Zwraca najmniejsza wartosc sygnalu.
     */
	double minimum( const SygnalProbkowany& _sygnalp )
	{
		double _min = _sygnalp[ 0 ].x;
		for ( int i = 0; i < _sygnalp.iloscProbek()-1; i++ )
			if ( _sygnalp[ i ].x < _min )
				_min = _sygnalp[ i ].x;
		return _min;
	}
    /**
     * @brief Funkcja obliczajaca najwieksza wartosc sygnalu
     *
     * Najpierw pierwszy element x probki zostaje ustawiony jako najwiekszy, nastepnie przy uzyciu petli
     * wszystkie probki zostaja sprawdzone - czy sa wieksze od zmiennej przechowujacej wartosc minimalna,
     * jezeli tak to zostaje zamieniona z wartoscia sprawdzana.
     * @return Zwraca najwieksza wartosc sygnalu.
     */
	double maksimum( const SygnalProbkowany& _sygnalp )
	{
		double _max = _sygnalp[ 0 ].x;
		for ( int i = 0; i < _sygnalp.iloscProbek()-1; i++ )
			if ( _sygnalp[ i ].x > _max )
				_max = _sygnalp[ i ].x;
		return _max;
	}
    /**
     * @brief Funkcja obliczajaca dlugosc sygnalu
     *
     * Korzysta z funkcji wyznaczajacych wartosci maksymalna i minimalna. Na podstawie powyzszych wartosci
     * obliczana jest dlugosc sygnalu.
     * @return Zwraca wartosc roznicy wartosci maksymalnej z minimalna.
     */
    double dlugosc( const SygnalProbkowany& _sygnalp )
	{
		return maksimum(_sygnalp) - minimum(_sygnalp);
	}
    /**
     * @brief Funkcja obliczajaca najwieksza wartosc sygnalu
     *
     * Na poczatku ustanawiana jest maksymalna wartosc, tutaj przyjmuje pierwszy element wektora probek
     * Nastepnie przeszukujac wszystkie probki sprawdzamy czy dana probka jest wieksza od aktualnej,
     * jezeli tak to zostaje nadpisana przez aktualny element
     * @return Zwraca srednia wartosc sumy elementow.
     */
	double srednia( const SygnalProbkowany& _sygnalp )
	{
		double m = 0.0;
		for ( int i = 0; i < _sygnalp.iloscProbek()-1; i++ )
			m += _sygnalp[ i ].x;
		if ( _sygnalp.iloscProbek() > 0 )
			m /= _sygnalp.iloscProbek() - 2;
		return m;
	}
    /**
     * @brief Funkcja obliczajaca wartosc calki sygnalu
     *
     * Funkcja oblicza wartosc calki metoda trapezowa.
     * @return Zwraca wartosc calki sygnalu
     */
	double calka( const SygnalProbkowany& _sygnalp )
	{
		double calka = 0, dt = 0, dpole = 0;
	    for (int i = 0; i < _sygnalp.iloscProbek()-1; i++ )
	    {
	        dt = _sygnalp[ i + 1 ].t - _sygnalp[ i ].t;
	        dpole = ( _sygnalp[ i ].x + _sygnalp[ i + 1 ].x ) * dt / 2;
	        calka = calka + dpole;
	    }
	    return calka;
	}
    /**
     * @brief Funkcja wyznaczajaca wartosc sygnalu sinusoidalnego
     *
     * Funkcja wywoluje metode z klasy SygnalSinusoidalny ktora wyznacza wartosc owego sygnalu w podanym t
     * @return Zwraca wartosc sygnalu sinusoidalnego
     */
	double sygnalsin ( Sygnal* _sygnal, double t )
	{
	    return _sygnal->x(t);
	}
};
#endif
