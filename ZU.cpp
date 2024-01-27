// ZU.cpp
#include "ZU.hpp"

// Constructeur
ZoneUrbaine::ZoneUrbaine(int num, const std::string& prop, const Polygone<int, float>& forme, float surfaceConstruite)
    : Parcelle(num, prop, forme),ZoneAUrbaniser(num, prop, forme), surfaceConstruite(surfaceConstruite) {
    setType("Zone Urbaine");
    pConstructible = ((Parcelle::getSurface() - surfaceConstruite)*100.0f)/Parcelle::getSurface();
}

float ZoneUrbaine::surfaceConstructible() const {
   return (Parcelle::getSurface() - surfaceConstruite);
}


// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& os, const ZoneUrbaine& zoneUrbaine) {
    os << std::endl << std::endl << "Affichage Zone Urbaine " << std::endl;
    os << "Parcelle n°" << zoneUrbaine.getNumero() << std::endl;
    os << "Type : " << zoneUrbaine.getType() << std::endl;
    os << "Proprietaire : " << zoneUrbaine.getProprietaire() << std::endl;
    os << "Surface : " << zoneUrbaine.getSurface() << "m²" << std::endl;
    os << "Surface constructible : " << zoneUrbaine.surfaceConstructible() << " m²" << std::endl;
    os << "Pourcentage constructible : " << zoneUrbaine.pConstructible << " %" << std::endl;
    os << "Surface construite : " << zoneUrbaine.surfaceConstruite << " m²" << std::endl;

    return os;
}

