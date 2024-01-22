#ifndef ZONENATURELLE_HPP
#define ZONENATURELLE_HPP

#include "Parcelle.hpp"
#include <iostream>

class ZoneNaturelle : public Parcelle {
private: 
std::string type = "Zone Naturelle";// Valeur par défaut
public:
    ZoneNaturelle(int num, const std::string& prop, const Polygone<int, float>& forme);

//surcharge de l'opérateur <<
friend std::ostream& operator << (std::ostream& os, const ZoneNaturelle& Zn);
};
std::ostream& operator << (std::ostream& os, const ZoneNaturelle& Zn);
#endif // ZONENATURELLE_HPP

