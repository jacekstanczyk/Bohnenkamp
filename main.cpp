#include "Tpozycja.h"
#include "wczytanieBazy.h"
#include "pokazbaze.h"
#include "zapiszbaze.h"
#include "raport.h"
#include "przeliczcene.h"
#include "uaktualnijBaze.h"
#include "wczytajCeny.h"
#include "zerowanie.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<Tpozycja> lista, listaUaktualnienie, cennik;
double dzielnik;
int wybor;

int main()
{

    for (;;)
    {
        cout << endl;
        cout << "1) Wczytaj baze" << endl;
        cout << "2) Uaktualnij baze" << endl;
        cout << "3) Wczytaj ilosc i ceny" << endl;
        cout << "4) Przeliczenie cen" << endl;
        cout << "5) Zapis nowej bazy" << endl;
        cout << "6) Pokaz baze" << endl;
        cout << "7) Raport" << endl;
        cout << "8) Wyjscie" << endl << endl;

        int wej;
        string plik;

        cin >> wej;

        switch (wej)
        {
        case 1:
            cout << "Podaj nazwe bazy <ENTER - domyslna - baza.txt>";

            cin >> plik;
            if (plik == "a")
                plik = "baza.txt";
            wczytanieBazy(lista, plik);
            break;

        case 2:
            cout << "Podaj nazwe bazy <ENTER - domyslna - baza2.txt>";

            cin >> plik;
            if (plik == "a")
                plik = "baza2.txt";
            if (!wczytanieBazy(listaUaktualnienie, plik))  // jesli dostep udany
                uaktualnijBaze(lista, listaUaktualnienie); // uaktualnij baze
            break;

        case 3:
            cout << "Podaj nazwe bazy <ENTER - domyslna - cennik.txt>";

            cin >> plik;
            if (plik == "a")
                plik = "cennik.txt";
            if (!wczytajCeny(cennik, plik)) // jesli dostep udany
            {
                zerujIloscCeny(lista);
                uaktualnijBaze(lista, cennik); // uaktualnij baze
            }

            break;

        case 4:
            cout << "1 modyfikacja calosciowa" << endl;
            cout << "2 modyfikacja skrypt" << endl;
            cin >> wybor;

            if (wybor == 1)
            {
                cout << "Podaj dzielnik (nowa cena = stara cena / dzielnik)" << endl;
                cin >> dzielnik;
                przeliczCene(lista, dzielnik);
            }
            else
            {
                cout << "Tymczasowe rozwiazanie !!!";

                przeliczCeneSkrypt(lista,"Test");
            }

            break;

        case 5:
            cout << "Podaj nazwe bazy <ENTER - domyslna - nowabaza.txt>";

            cin >> plik;
            if (plik == "a")
                plik = "nowabaza.txt";
            zapiszBaze(lista, plik);
            break;

        case 6:
            pokazBaze(lista);
            break;

        case 7:
            raport(lista);
            break;

        case 8:
            break;
        default:
            break;
        }
        if (wej == 8)
            break;
    }

    return 0;
}
