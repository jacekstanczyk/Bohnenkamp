#include "eanpoprawnosc.h"
#include <string>
#include <iostream>

using namespace std;

bool eanpoprawnosc(const long long ean)
{
    string napis = to_string(ean);
    int suma = 0;
    int ileCyfr = napis.length();
    int kontrolna = napis[ileCyfr - 1] - '0'; // ostatnia cyfra
    for (int i = 0; i < ileCyfr - 1; i++)
    {
        char znak = napis[i];
        int cyfra = znak - '0';
        suma = suma + (cyfra * (i % 2 ? 3 : 1)); //sprawdza czy cyfra jest na pozycji parzystej czy nieparzystej
    }

    //Następnie wynik dzielimy modulo 10, i odejmujemy go od 10. Nastepnie ten wynik dzielimy znów modulo 10.(to zabezpieczenie gdyby wyszło nam 10 - wówczas cyfra kontrolna powinna wynosić 0)
    if (kontrolna == ((10 - (suma % 10)) % 10))
        return true;

    else
        return false;
}

//**********************************************************************************
// int liczba = 1234567890;
//     string napis = to_string(liczba);
//     int suma = 0;
//     int ileCyfr = napis.length();
//     for (int i = 0; i < ileCyfr; i++) {
//             char znak = napis[i];
//             int cyfra = znak - '0';
//             suma = suma + cyfra;
//         }
//     cout << "Suma wszystkich cyfr to: " << suma<< endl;

//********************************************************************************
//Rozwiazanie matematyczne

// liczba ← wczytaj()
// suma ← 0
// powtarzaj aż liczba wynosi 0:
//     cyfra ← liczba mod 10
//     suma ← suma + cyfra
//     liczba ← liczba  div 10
//  gdzie:  mod – reszta z dzielenia a div to dzielenie całkowite (z pominięciem ułamka)