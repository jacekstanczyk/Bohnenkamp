#include "Tpozycja.h"
#include <iostream>

using namespace std;

Tpozycja::Tpozycja(unsigned long long n, unsigned long long e, std::string bie, std::string roz, std::string prod, unsigned int ilo, double cen)
{
    numer = n;
    ean = e;
    bieznik = bie;
    rozmiar = roz;
    producent = prod;
    ilosc = ilo;
    cena = cen;
}

std::ostream &Tpozycja::wypisz(std::ostream &strumien)
{
    string Scena;

    strumien << numer << ";";

    if (ean != 0)
        strumien << ean;
    strumien << ";";

    if (bieznik != "")
        strumien << bieznik;
    strumien << ";";

    if (rozmiar != "")
        strumien << rozmiar;
    strumien << ";";

    if (producent != "")
        strumien << producent;
    strumien << ";";

    if ((ilosc == 0) || (cena == 0))
        strumien << ";" << endl;
    else
    {
        Scena = to_string(cena);

        int dlugosc = Scena.length();
        for (int i = 0; i < dlugosc; i++)
        {
            if (Scena[i] == '.')
                Scena[i] = ',';
        }

        strumien << ilosc << ";" << Scena << endl;
    }
    return strumien;
}
