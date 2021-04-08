#include "przeliczcene.h"
#include <iostream>

using namespace std;

void przeliczCene(std::vector<Tpozycja> &a, double dzielnik)
{
    for (Tpozycja &pozycja : a)
    {
        if (pozycja.cena != 0)
            pozycja.cena /= dzielnik;
    }
}

void przeliczCeneSkrypt(std::vector<Tpozycja> &a, std::string plik)
{
    for (Tpozycja &pozycja : a)
    {
        pozycja.czy_modyfikowano_cene = false;
    }

    for (Tpozycja &pozycja : a)
    {
        if (pozycja.czy_modyfikowano_cene == false)
        {
            if (pozycja.producent == "CEAT")
            {
                pozycja.cena /= 0.87;
                pozycja.czy_modyfikowano_cene = true;
                cout << "W CEAT" << endl;
            }
        }
    }

    for (Tpozycja &pozycja : a)
    {
        if (pozycja.czy_modyfikowano_cene == false)
        {
            pozycja.cena /= 0.81;
            pozycja.czy_modyfikowano_cene = true;
            cout << "W pozostalych" << endl;
        }
    }
}