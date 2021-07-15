#include "wczytanieBazy.h"

using namespace std;

int wczytanieBazy(vector<Tpozycja> &a, string nazwaPliku)
{
    string numer, ean, bieznik, rozmiar, producent, ilosc, cena;
    unsigned long long LLnumer, LLean;
    unsigned int Iilosc;
    double Dcena;

    int i;

    fstream plik;
    plik.open(nazwaPliku);

    if (plik.good())
    {
        a.clear(); // wyczyszczenie calego vectora

        string linia;

        while (getline(plik, linia))
        {
            if (linia[0] < '0' || linia[0] > '9') //sprawdza czy linia to nie opis
                continue;

            int dlugosc = linia.size();

            i = 0;
            numer = "";
            ean = "";
            bieznik = "";
            rozmiar = "";
            producent = "";
            ilosc = "0";
            cena = "0";

            while (linia[i] != ';')
            {
                numer += linia[i];
                i++;
            }

            i++;
            while (linia[i] != ';')
            {
                ean += linia[i];
                i++;
            }

            i++;
            while (linia[i] != ';')
            {
                bieznik += linia[i];
                i++;
            }

            i++;
            while (linia[i] != ';')
            {
                rozmiar += linia[i];
                i++;
            }

            i++;
            while (linia[i] != ';')
            {
                producent += linia[i];
                i++;
            }

            i++;
            while (linia[i] != ';')
            {
                ilosc += linia[i];
                i++;
            }

            i++;
            while (i <= dlugosc)
            {
                if ((linia[i] < '0' || linia[i] > '9') && linia[i] != ',') //sprawdza czy nie ma odstepow w cenie
                {
                    i++;
                    continue;
                }

                if (linia[i] == ',') //podmiana przecinaka na kropke
                    linia[i] = '.';  //podmiana przecinaka na kropke
                cena += linia[i];
                i++;
            }

            LLnumer = stoull(numer);          //zamiana string na liczbe
            if (ean[0] < '0' || ean[0] > '9') // jezeli Ean rozny od liczby to wstaw 0
            {
                ean = '0';
            }
            LLean = stoull(ean);   //zamiana string na liczbe
            Iilosc = stoul(ilosc); //zamiana string na liczbe
            Dcena = stod(cena);    //zamiana string na liczbe

            a.push_back(Tpozycja(LLnumer, LLean, bieznik, rozmiar, producent, Iilosc, Dcena));

            //cout << "Dodano element: " << LLnumer << ";" << LLean << ";" << bieznik << ";" << rozmiar << ";" << producent << ";" << Iilosc << ";" << Dcena << endl;
        }
    }
    else
    {
        cout << "Nieudany dostep do pliku : " << nazwaPliku << endl;
        return 1;
    }
    cout << "Wczytano baze : " << nazwaPliku << endl;

    plik.close();

    sort(a.begin(), a.end());
    return 0;
}