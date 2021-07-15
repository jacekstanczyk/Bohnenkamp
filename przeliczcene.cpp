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
            if (pozycja.producent == "ALLIANCE")
            {
                if (szukaj(pozycja.rozmiar, "AGRI STAR II"))
                {
                    pozycja.cena /= 0.835;
                    pozycja.czy_modyfikowano_cene = true;
                    continue;
                }
                else if (szukaj(pozycja.rozmiar, "AGRISTAR II"))
                {
                    pozycja.cena /= 0.835;
                    pozycja.czy_modyfikowano_cene = true;
                    continue;
                }
                else if (szukaj(pozycja.rozmiar, "Agristar II"))
                {
                    pozycja.cena /= 0.835;
                    pozycja.czy_modyfikowano_cene = true;
                    continue;
                }
                else if (szukaj(pozycja.rozmiar, "FARMPRO"))
                {
                    pozycja.cena /= 0.852;
                    pozycja.czy_modyfikowano_cene = true;
                    continue;
                }

                pozycja.cena /= 0.852;
                pozycja.czy_modyfikowano_cene = true;
                continue;
            }
        }

        if (pozycja.czy_modyfikowano_cene == false)
        {
            if (pozycja.producent == "CEAT")
            {
                pozycja.cena /= 0.875;
                pozycja.czy_modyfikowano_cene = true;
                continue;
            }
        }

        if (pozycja.czy_modyfikowano_cene == false)
        {
            if (pozycja.producent == "DELI")
            {
                pozycja.cena /= 0.75;
                pozycja.czy_modyfikowano_cene = true;
                continue;
            }
        }

        if (pozycja.czy_modyfikowano_cene == false)
        {
            if (pozycja.producent == "KENDA")
            {
                pozycja.cena /= 0.75;
                pozycja.czy_modyfikowano_cene = true;
                continue;
            }
        }

        if (pozycja.czy_modyfikowano_cene == false)
        {
            if (pozycja.producent == "DONG")
            {
                pozycja.cena /= 0.745;
                pozycja.czy_modyfikowano_cene = true;
                continue;
            }
        }

        if (pozycja.czy_modyfikowano_cene == false)
        {
            if (pozycja.producent == "NEXEN")
            {
                pozycja.cena /= 0.745;
                pozycja.czy_modyfikowano_cene = true;
                continue;
            }
        }

        if (pozycja.czy_modyfikowano_cene == false)
        {
            if (pozycja.producent == "GALAXY")
            {
                pozycja.cena /= 0.84;
                pozycja.czy_modyfikowano_cene = true;
                continue;
            }
        }

        if (pozycja.czy_modyfikowano_cene == false)
        {
            if (pozycja.producent == "DEESTONE")
            {
                pozycja.cena /= 0.85;
                pozycja.czy_modyfikowano_cene = true;
                continue;
            }
        }
    }

    for (Tpozycja &pozycja : a)
    {
        if (pozycja.czy_modyfikowano_cene == false)
        {
            pozycja.cena /= 0.84;
            pozycja.czy_modyfikowano_cene = true;
            continue;
        }
    }
}

bool szukaj(std::string &tekst, std::string szukanaFraza)
{
    size_t znalezionaPozycja = tekst.find(szukanaFraza);
    if (znalezionaPozycja == std::string::npos)
        return false;
    else
        return true;
}