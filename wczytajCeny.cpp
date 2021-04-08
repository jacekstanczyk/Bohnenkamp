#include "wczytajCeny.h"

int wczytajCeny(vector<Tpozycja> &cennik, string nazwaPliku)
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
        cennik.clear(); // wyczyszczenie calego vectora

        string linia;

        while (getline(plik, linia))
        {
            int dlugosc = linia.size();

            i = 0;
            numer = "";
            ean = '0';
            bieznik = "";
            rozmiar = "";
            producent = "";
            ilosc = "0";
            cena = "0";

            while (linia[i] != ';')
            {
                i++;
            }

            i++;
            if (linia[i] < '0' || linia[i] > '9') //sprawdza czy to cyfra jesli nie to nowa linia
                continue;

            while (linia[i] != ';')
            {
                numer += linia[i];
                i++;
            }

            i++;
            while (linia[i] != ';')
            {
                if ((linia[i] < '0' || linia[i] > '9') && linia[i] != ',') //sprawdza czy nie ma odstepow w cenie
                {
                    i++;
                    continue;
                }
                if (linia[i] == ',') //podmiana przecinaka na kropke
                    linia[i] = '.';  //podmiana przecinaka na kropke

                ilosc += linia[i];
                i++;
            }

            i++;
            while (linia[i] != ';')
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

            LLnumer = stoull(numer); //zamiana string na liczbe
            LLean = stoull(ean);     //zamiana string na liczbe
            Iilosc = stoul(ilosc);   //zamiana string na liczbe
            Dcena = stod(cena);      //zamiana string na liczbe

            cennik.push_back(Tpozycja(LLnumer, LLean, bieznik, rozmiar, producent, Iilosc, Dcena));
            //cout << "Dodano element: " << LLnumer << ";" << LLean << ";" << bieznik << ";" << rozmiar << ";" << producent << ";" << Iilosc << ";" << Dcena << endl;
        }
    }
    else
    {
        cout << "Nieudany dostep do pliku" << endl;
        return 1;
    }
    cout << "wczytano baze" << endl;

    plik.close();

    sort(cennik.begin(), cennik.end());
    return 0;
}