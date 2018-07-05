#include<iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "Przedmiot.h"

using namespace std;

bool komparator(Przedmiot *p, Przedmiot* p2) {
	if (p->s > p2->s) {
		return true;
	}
	else if (p->s < p2->s) {
		return false;
	}
	else {
		return false;
	}
}

int main() {

	srand(time(NULL));
	//double B = 1000000;
	double B = 5000;
	int iloscPrzedmiotow = 50;
	//int iloscPrzedmiotow = 5000;

	Przedmiot** p = new Przedmiot*[iloscPrzedmiotow];
	for (int i = 0; i < iloscPrzedmiotow; i++) {
		p[i] = new Przedmiot();
	}
	cout << "Masy przedmiotow:" << endl;
	for (int i = 0; i < iloscPrzedmiotow; i++) {
		cout << p[i]->m << " ";
	}
	cout << endl;
	sort(p,p+iloscPrzedmiotow,komparator);
	/*
	for (int i = 0; i < iloscPrzedmiotow; i++) {
		cout << p[i]->s << " ";
	}
	*/
	clock_t czas0 = clock();//CZAS//
	double plecak = 0.0;
	double plecakW = 0.0;
	cout << "Plecak przedmioty:\n";
	for (int i = 0; i < iloscPrzedmiotow; i++) {
		if ((plecak + p[i]->m) <= B) {
			plecak += p[i]->m;
			plecakW += p[i]->w;
			cout << (i + 1) << " " << p[i]->m << " " << p[i]->w << "\n";
		}
	}
	clock_t czas1 = clock();

	cout << "Masa: " << plecak;
	cout << " \n" << "Wartosc: " << plecakW;

	cout << "\n";



	for (int i = 0; i < iloscPrzedmiotow; i++) {
		delete p[i];
	}
	delete[] p;
	//---------------------------------------------------------------------------------------------------------------------------------
	cout << endl;
	cout <<"FPTAS"<< endl;
	cout << endl;
	Przedmiot** p2 = new Przedmiot*[iloscPrzedmiotow];
	for (int i = 0; i < iloscPrzedmiotow; i++) {
		p2[i] = new Przedmiot();
	}

	cout << "Wartosci przedmiotow:" << endl;
	for (int i = 0; i < iloscPrzedmiotow; i++) {
		cout << p2[i]->w << " ";
	}
	clock_t czas00 = clock();//CZAS//
	double epsilon = 0.5;
	double W = -999999;
	
	

	for (int i = 0; i < iloscPrzedmiotow; i++) {
		if (p2[i]->w > W) {
			W = p2[i]->w; 
		}
	}
	cout << endl;
	cout << "Nacenniejzy przedmiot:"<<endl;
	cout << W<<endl;

	int n = iloscPrzedmiotow;
	double K = (epsilon*W) / n;

	double* wPrim = new double[iloscPrzedmiotow];

	for (int i = 0; i < iloscPrzedmiotow; i++) {
		wPrim[i] = floor(p2[i]->w / K);
	}

	//--------------------------------------
	/*for i: = 0 to n do
		A[i, 0] : = 0
	for j : = 0 to W do
			A[0, j] : = 0

	for i : = 1 to n do           //rozwa¿anie kolejno i pierwszych przedmiotów
				for j : = 0 to W do
					if (w[i] > j) then   //sprawdzenie czy i-ty element mieœci siê w plecaku o rozmiarze j
						A[i, j] = A[i - 1, j]
					else
						A[i, j] = max(A[i - 1, j], A[i - 1, j - w[i]] + c[i])*/
	double** A = new double*[iloscPrzedmiotow];
	for (int i = 0; i < iloscPrzedmiotow; i++) {
		A[i] = new double[(int)W];
	}
	for (int i = 0; i < iloscPrzedmiotow; i++) {
		A[i][ 0] = 0;
	}
	for (int j = 0; j < (int)W; j++) {
		A[0][ j] = 0;
	}
	
	for (int i = 1; i < n; i++) {//rozwa¿anie kolejno i pierwszych przedmiotów	
		for (int j = 0; j < (int)W; j++) {
			if (wPrim[i] > j) {   //sprawdzenie czy i-ty element mieœci siê w plecaku o rozmiarze j
				A[i][ j] = A[i - 1][ j];
			}else{
				A[i][j] = max(A[i - 1][j] , (A[i - 1][j - (int)wPrim[i]] + p2[i]->w));
			}
		}
	}

	//---------------------------
	clock_t czas11 = clock();
	cout << "\n\nWyniki\n";
	cout << A[n - 1][((int)W) - 1] << endl;
	//cout << A[n][((int)W-1)];
	cout << "\n\n";
	

	cout << "\n";
	cout << "zachlanny\n";
	clock_t czas = czas1 - czas0;
	cout << czas;
	cout << "\n";

	////CZAS//////////////////////////////////////////////////////////////////////

	clock_t czass = czas11 - czas00; // CZAS OPERACJI
	cout << "\n";
	cout << "fptas\n";
	cout << czass;
	cout << "\n";


	/*cout << endl;
	for (int i = 0; i < iloscPrzedmiotow; i++) {
		cout << p2[i]->w << " ";
	}*/

	for (int i = 0; i < iloscPrzedmiotow; i++) {
		delete p2[i];
	}
	delete[] p2;
	system("pause");
	return 0;
}
