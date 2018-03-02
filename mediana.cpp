#include <iostream>
#include <iomanip>
#include <vector>
#include "studentas.h"
#include "mediana.h"

using std::cout; using std::endl; using std::vector; using std:: swap; using std::setw;
double mediana(vector<int>& M, int kiek, int c){
    int j;
	for (int i = 1; i < kiek; i++)
	{
		j = i;
		while (j > 0 && M[j] < M[j - 1])
		{
			swap (M[j], M[j - 1]); //rikiuojame pazymius
			j--;
		}
	}

    if (j%2==0)
    {
        auto galBalas=0.4*M[j / 2]+0.6*c;
        cout.precision (3);
        cout<<"Galutinis balas: ";              //greiciausiai reikia isvesti galutini bala ir plius returnin gal bala
        return galBalas;
    }
    else
    {
        auto galBalas=0.4*(M[j / 2] + M[j / 2 +1])/2+0.6*c;
        cout.precision (3);
        cout<<"Galutinis balas: ";
        return galBalas;
    }
}
void mediana(studentas &S){
    int j;
    auto kiek=S.pazymiai.size()-1;
	for (int i = 1; i < kiek; i++)
	{
		j = i;
		while (j > 0 && S.pazymiai[j] < S.pazymiai[j - 1])
		{
			std::swap(S.pazymiai[j], S.pazymiai[j - 1]); //rikiuojame pazymius
			j--;
		}
	}

    if (j%2==0)
    {
        auto galBalas=0.4*S.pazymiai[j / 2]+0.6*S.egzaminas;
        cout.precision (3);
        cout<<setw(20)<<galBalas;
    }
    else
    {
        auto galBalas=0.4*(S.pazymiai[j / 2] + S.pazymiai[j / 2 +1])/2+0.6*S.egzaminas;
        cout.precision (3);
        cout<<setw(20)<<galBalas;
    }
}
