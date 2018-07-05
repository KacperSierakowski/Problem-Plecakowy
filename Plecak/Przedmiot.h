#ifndef PRZEDMIOT_H
#define PRZEDMIOT_H

#include<iostream>
#include <cstdlib>
#include <ctime>

class Przedmiot
{
public:
	//masa
	double m;
	//wartosc
	double w;
	//stosunek wartosci do masy
	double s;
public:
	Przedmiot();
	~Przedmiot();
};

#endif
