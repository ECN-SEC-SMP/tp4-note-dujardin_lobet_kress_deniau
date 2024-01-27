// ZoneU.hpp
#ifndef ZU_HPP
#define ZU_HPP

#include "ZAU.hpp"

class ZoneUrbaine : public ZoneAUrbaniser {
private:
    float surfaceConstruite;

public:
    // Constructeur
    ZoneUrbaine(int num, const std::string& prop, const Polygone<int, float>& forme, float surfaceConstruite);

    // Redéfinition de la fonction virtuelle pure
    float surfaceConstructible() const;

    // Surcharge de l'opérateur <<
    friend std::ostream& operator<<(std::ostream& os, const ZoneUrbaine& zoneUrbaine);
};

std::ostream& operator<<(std::ostream& os, const ZoneUrbaine& zoneUrbaine);

#endif // ZU_HPP
