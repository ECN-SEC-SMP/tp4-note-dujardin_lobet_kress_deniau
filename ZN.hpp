#ifndef ZONENATURELLE_HPP
#define ZONENATURELLE_HPP

#include "Parcelle.hpp"
#include <iostream>

class ZoneNaturelle : public virtual Parcelle {
protected: 
public:
  ZoneNaturelle(int num, const std::string& prop, const Polygone<int, float>& forme);
  // Redéfinition de setType pour définir le type sur "Zone Naturelle"
  void setType(const std::string& type) override;

  // Ajout d'un getter pour le type
  std::string getZoneType() const;
  //surcharge de l'opérateur <<
  friend std::ostream& operator << (std::ostream& os, const ZoneNaturelle& Zn);
};
std::ostream& operator << (std::ostream& os, const ZoneNaturelle& Zn);
#endif // ZONENATURELLE_HPP

