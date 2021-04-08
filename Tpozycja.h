#ifndef Tpozycjah
#define Tpozycjah

#include <string>

class Tpozycja
{
public:
    Tpozycja() {}
    Tpozycja(unsigned long long n, unsigned long long e, std::string bie, std::string roz, std::string prod, unsigned int ilo, double cen);
    std::ostream &wypisz(std::ostream &strumien);

    bool operator<(const Tpozycja &x) const
    {
        return this->numer < x.numer;
    }

    unsigned long long numer = 0;
    unsigned long long ean = 0;
    std::string bieznik;
    std::string rozmiar;
    std::string producent;
    unsigned int ilosc = 0;
    double cena = 0;
    bool czy_modyfikowano_cene = false;
};

#endif