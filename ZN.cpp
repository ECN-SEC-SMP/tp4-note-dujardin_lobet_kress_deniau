#include "ZN.hpp"

ZoneNaturelle::ZoneNaturelle(int num, const std::string& prop, const Polygone<int, float>& forme)
    : Parcelle(num, prop, forme) {
    // Initialisation spécifique à ZoneNaturelle si nécessaire
}

//surcharge de l'opérateur <<
std::ostream& operator << (std::ostream& os, const ZoneNaturelle& Za) {

  os << "parcelle numero : " << Za.getNumero() << std::endl;
  os << "Type : " << Za.getType() << std::endl;
  os << "Polygone: " << Za.getForme() << std::endl;
  os << "Proprietaire : " << Za.getProprietaire() << std::endl;
  os << "Surface : " << Za.getSurface() << std::endl;

    return os;
}