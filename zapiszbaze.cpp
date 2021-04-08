#include "zapiszbaze.h"

void zapiszBaze(vector<Tpozycja> &a, string nazwaPliku)
{
    fstream plik;
    plik.open(nazwaPliku, ios::out | ios::trunc);

    if (plik.good())
    {
        plik << "Nr.;EAN;Beschreibung;Beschreibung 2;Hersteller Kurzbeschreibung;Lagerbestand;cena" << endl; // opis pol w tabeli
        for (int i = 0; i < a.size(); i++)
            a[i].wypisz(plik);
    }
    else
    {
        cout << "Nieudany dostep do pliku : " << nazwaPliku << endl;
        return;
    }
    cout << "Zapisano baze : " << nazwaPliku << endl;

    plik.close();
}