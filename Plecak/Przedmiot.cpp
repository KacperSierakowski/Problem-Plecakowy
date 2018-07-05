#include "Przedmiot.h"



Przedmiot::Przedmiot()
{
	m = rand()%500;
	w = rand()%1000;
	s = w / m;
}


Przedmiot::~Przedmiot()
{
}
