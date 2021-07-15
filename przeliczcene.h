#ifndef przeliczceneh
#define przeliczceneh

#include <vector>
#include "Tpozycja.h"

void przeliczCene (std::vector<Tpozycja> &a, double dzielnik);
void przeliczCeneSkrypt(std::vector<Tpozycja> &a, std::string plik);
bool szukaj( std::string & tekst, std::string szukanaFraza); //szuka frazy w stringu
#endif