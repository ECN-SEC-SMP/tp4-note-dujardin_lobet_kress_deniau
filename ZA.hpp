#ifndef ZONEAGRICOLE_HPP
#define ZONEAGRICOLE_HPP

#include "ZN.hpp"
#include "Constructible.hpp"

class ZoneAgricole : public ZoneNaturelle, public Constructible {

protected:
    std::string typeCulture;
public:
    // Constructeur
    ZoneAgricole(int num, const std::string& prop, const Polygone<int, float>& forme, const std::string& typeCulture);


    // Redéfinition de setType pour définir le type sur "Zone Naturelle"
    void setType(const std::string& type) override;
    void setTypeCulture(const std::string& typeCulture);
    std::string getTypeCulture() const;

    // Redéfinition de la fonction virtuelle pure
    float surfaceConstructible() const override {
      // Calcul de la surface maximale constructible (10% de la surface de la ZA ou 200m2, le minimum des deux)
      float maxSurface = std::min(getSurface() * 0.1f, 200.0f);
      return maxSurface;
    }

    // Surcharge de l'opérateur <<
    friend std::ostream& operator << (std::ostream& os, const ZoneAgricole& za);
};
std::ostream& operator << (std::ostream& os, const ZoneAgricole& za);
#endif // ZONEAGRICOLE_HPP
