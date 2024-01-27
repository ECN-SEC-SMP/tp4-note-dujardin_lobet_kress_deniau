#include "ZN.hpp"

ZoneNaturelle::ZoneNaturelle(int num, const std::string& prop, const Polygone<int, float>& forme)
    : Parcelle(num, prop, forme) {
      setType("Zone Naturelle");
    // Initialisation spécifique à ZoneNaturelle si nécessaire
}

void ZoneNaturelle::setType(const std::string& type) {
    Parcelle::setType(type);
}

std::string ZoneNaturelle::getZoneType() const {
    return Parcelle::getType();
}
//surcharge de l'opérateur <<
std::ostream& operator << (std::ostream& os, const ZoneNaturelle& Zn) {
  os <<std::endl<< std::endl<<"Affichage Zone Naturelle "<< std::endl;
  os << "Parcelle n°" << Zn.getNumero() << std::endl;
  os << "Type : " << Zn.getZoneType() << std::endl;
  os << "Proprietaire : " << Zn.getProprietaire() << std::endl;
  os << "Surface : " << Zn.getSurface() <<" m²"<< std::endl;

    return os;
}