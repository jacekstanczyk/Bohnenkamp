#include "uaktualnijBaze.h"

void uaktualnijBaze(vector<Tpozycja> &glowna, vector<Tpozycja> &nowe)
{

    if (glowna.size() > 0 && nowe.size() > 0) // sprawdza czy obie bazy nie sa puste
    {
        int indeks = 0;
        int glownaSize = glowna.size() - 1;

        for (Tpozycja &pozycja : nowe)
        {
            for (;;)
            {
                //cout << glownaSize << " index : " << indeks << endl;
                if (pozycja.numer < glowna[indeks].numer)
                {
                    glowna.push_back(pozycja);
                    //cout << "w pozycji mniejsza" << endl;
                    break;
                }

                if (pozycja.numer == glowna[indeks].numer)
                {
                    //cout << "w pozycji rowna" << endl;

                    if (glowna[indeks].ean == 0)
                        glowna[indeks].ean = pozycja.ean;
                    if (glowna[indeks].bieznik == "")
                        glowna[indeks].bieznik = pozycja.bieznik;
                    if (glowna[indeks].rozmiar == "")
                        glowna[indeks].rozmiar = pozycja.rozmiar;
                    if (glowna[indeks].producent == "")
                        glowna[indeks].producent = pozycja.producent;
                    if (glowna[indeks].ilosc == 0)
                        glowna[indeks].ilosc = pozycja.ilosc;
                    if (glowna[indeks].cena == 0)
                        glowna[indeks].cena = pozycja.cena;

                    if (indeks < glownaSize)
                        indeks++;
                    break;
                }

                if ((pozycja.numer > glowna[indeks].numer) && ((indeks < glownaSize)))
                {
                    indeks++;
                    //cout << "w pozycji wieksza zwieksz indeks" << endl;
                }

                if ((pozycja.numer > glowna[indeks].numer) && (indeks == glownaSize))
                {
                    //cout << "w pozycji wieksza" << endl;
                    glowna.push_back(pozycja);
                    break;
                }
            }
        }
        sort(glowna.begin(), glowna.end());
    }
}