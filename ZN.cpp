#include "ZN.hpp"

ZoneNaturelle::ZoneNaturelle(int num, const std::string& prop, const Polygone<int, float>& forme)
    : Parcelle(num, prop, forme) {
    // Initialisation spécifique à ZoneNaturelle si nécessaire
}

std::string ZoneNaturelle::getType() const {
    return type;
}

//surcharge de l'opérateur <<
std::ostream& operator << (std::ostream& os, const ZoneNaturelle& Zn) {
  os <<std::endl<< std::endl<<"Affichage Zone Naturelle "<< std::endl;
  os << "Parcelle n°" << Zn.getNumero() << std::endl;
  os << "Type : " << Zn.getType() << std::endl;
  os << "Polygone: " << Zn.getForme() << std::endl;
  os << "Proprietaire : " << Zn.getProprietaire() << std::endl;
  os << "Surface : " << Zn.getSurface() << std::endl;

    return os;
}