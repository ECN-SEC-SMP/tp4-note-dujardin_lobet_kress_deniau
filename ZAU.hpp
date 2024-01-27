#ifndef ZAU_HPP
#define ZAU_HPP

#include "Constructible.hpp"

class ZoneAUrbaniser : public Constructible {
public:
    // Constructeur
    ZoneAUrbaniser(int num, const std::string& prop, const Polygone<int, float>& forme);

    // Redéfinition de setType pour définir le type sur "Zone à Urbaniser"
    void setType(const std::string& type) override;

    // Redéfinition de la fonction virtuelle pure
    float surfaceConstructible() const override;

    // Surcharge de l'opérateur <<
    friend std::ostream& operator<<(std::ostream& os, const ZoneAUrbaniser& zau);
};

std::ostream& operator<<(std::ostream& os, const ZoneAUrbaniser& zau);

#endif // ZAU_HPP
