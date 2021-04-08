#include "raport.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void raport(std::vector<Tpozycja> &a)
{

    std::vector<Tpozycja> tymczasowaLista; // lista do zapisu niekompletnych pozycji
    tymczasowaLista.clear();               //czyszczenie zawartosci vectora
    int iloscpozycji = 0;
    int ean = 0;
    int bieznik = 0;
    int rozmiar = 0;
    int producent = 0;
    int stanZerowy = 0;
    int powtorki = 0;

    unsigned long long poprzedni = 0;

    for (Tpozycja &pozycja : a)
    {
        bool brak = false;

        if ((iloscpozycji > 0) && (pozycja.numer == poprzedni))
        {
            powtorki++;
            cout << "Powtorka : " << pozycja.numer << endl;
        }

        poprzedni = pozycja.numer;

        iloscpozycji++;

        if (pozycja.ean == 0)
        {
            ean++;
            brak = true;
        }

        if (pozycja.bieznik == "")
        {
            bieznik++;
            brak = true;
        }

        if (pozycja.rozmiar == "")
        {
            rozmiar++;
            brak = true;
        }

        if (pozycja.producent == "")
        {
            producent++;
            brak = true;
        }

        if (pozycja.ilosc == 0)
        {
            stanZerowy++;
        }

        if (brak == true)
        {
            tymczasowaLista.push_back(pozycja);
        }
    }

    cout << "Wszystkich pozycji : " << iloscpozycji << endl;
    cout << "Brak EAN : " << ean << endl;
    cout << "Brak Bieznik : " << bieznik << endl;
    cout << "Brak Rozmiar : " << rozmiar << endl;
    cout << "Brak Producent : " << producent << endl;
    cout << "Brak Produktu : " << stanZerowy << endl;
    cout << "Powtorki : " << powtorki << endl;

    fstream plik;
    plik.open("raport.txt", ios::out | ios::trunc);

    if (plik.good())
    {

        for (int i = 0; i < tymczasowaLista.size(); i++)
            tymczasowaLista[i].wypisz(plik);
    }
    else
    {
        cout << "Nieudany dostep do pliku" << endl;
        return;
    }
    cout << "Zapisano plik : raport.txt" << endl;

    plik.close();
}