#include "uaktualnijBaze.h"

void uaktualnijBaze(vector<Tpozycja> &glowna, vector<Tpozycja> &nowe)
{
    int dodano = 0;
    int uaktualniono = 0;

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
                    dodano++;
                    //cout << "w pozycji mniejsza" << endl;
                    break;
                }

                if (pozycja.numer == glowna[indeks].numer)
                {
                    //cout << "w pozycji rowna" << endl;
                    bool czyUaktualniano = false;

                    if (glowna[indeks].ean == 0 && pozycja.ean != 0)
                    {
                        glowna[indeks].ean = pozycja.ean;
                        czyUaktualniano = true;
                    }

                    if (glowna[indeks].bieznik == "" && pozycja.bieznik != "")
                    {
                        glowna[indeks].bieznik = pozycja.bieznik;
                        czyUaktualniano = true;
                    }

                    if (glowna[indeks].rozmiar == "" && pozycja.rozmiar != "")
                    {
                        glowna[indeks].rozmiar = pozycja.rozmiar;
                        czyUaktualniano = true;
                    }

                    if (glowna[indeks].producent == "" && pozycja.producent != "")
                    {
                        glowna[indeks].producent = pozycja.producent;
                        czyUaktualniano = true;
                    }

                    if (glowna[indeks].ilosc == 0 && pozycja.ilosc != 0)
                    {
                        glowna[indeks].ilosc = pozycja.ilosc;
                        czyUaktualniano = true;
                    }

                    if (glowna[indeks].cena == 0 && pozycja.cena != 0)
                    {
                        glowna[indeks].cena = pozycja.cena;
                        czyUaktualniano = true;
                    }

                    if (indeks < glownaSize)
                        indeks++;

                    if (czyUaktualniano == true)
                        uaktualniono++;
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
                    dodano++;
                    break;
                }
            }
        }
        sort(glowna.begin(), glowna.end());
        cout << "Dodano : " << dodano << endl;
        cout << "Uaktualniono : " << uaktualniono << endl;
    }
}