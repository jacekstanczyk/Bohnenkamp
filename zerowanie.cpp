#include "zerowanie.h"

void zerujIloscCeny(vector<Tpozycja> & baza)
{
    for (Tpozycja &pozycja : baza)
    {
        pozycja.ilosc = 0;
        pozycja.cena = 0;
    }
}