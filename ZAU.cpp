#include "ZAU.hpp"

// Constructeur
ZoneAUrbaniser::ZoneAUrbaniser(int num, const std::string& prop, const Polygone<int, float>& forme)
    :Parcelle(num, prop, forme), Constructible(num, prop, forme) {
    setType("Zone à Urbaniser");
    pConstructible = 100.0f;
}

void ZoneAUrbaniser::setType(const std::string& type) {
    Constructible::setType(type);
}


float ZoneAUrbaniser::surfaceConstructible() const {
    return getSurface()*pConstructible/100.0f;
}

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& os, const ZoneAUrbaniser& zau) {
    os << std::endl << std::endl << "Affichage Zone à Urbaniser " << std::endl;
    os << "Parcelle n°" << zau.getNumero() << std::endl;
    os << "Type : " << zau.getType() << std::endl;
    os << "Proprietaire : " << zau.getProprietaire() << std::endl;
    os << "Surface : " << zau.getSurface() << "m²" << std::endl;
    os << "Surface constructible : " << zau.surfaceConstructible() << " m²"<< std::endl;
    os << "Pourcentage constructible : " << zau.pConstructible << " %" << std ::endl;
    return os;
}
