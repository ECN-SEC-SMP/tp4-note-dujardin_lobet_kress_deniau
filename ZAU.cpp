#include "ZAU.hpp"

/*ZAU::ZAU(int num, const std::string& prop, const Polygone<int, float>& forme)
    : Parcelle(num, prop, forme) {
   
}*/

//surcharge de l'opérateur <<
std::ostream& operator << (std::ostream& os, const ZAU& zau) {

  os << "Type : " << typeid(*this).name() << endl;
  os << "Polygone: " << zau.forme << endl;
  os << "Proprietaire : " << zau.proprietaire << endl;
  os << "Surface : " << zau.surface << endl;
  os << "% Constructible : " << zau.pConstructible << endl;

    return os;
}

