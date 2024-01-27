  #include "ZA.hpp"

  // Constructeur
  ZoneAgricole::ZoneAgricole(int num, const std::string& prop, const Polygone<int, float>& forme, const std::string& typeCulture)
      : Parcelle(num, prop, forme),ZoneNaturelle(num, prop, forme), Constructible(num, prop, forme) {
        setType("Zone Agricole");
        setTypeCulture(typeCulture);

        // Condition pour calculer pConstructible
        if ((getSurface() * 0.1f) < 200.0f) {
            pConstructible = 10.0f;
        } else {
            pConstructible = 200.0f * 100 / getSurface();
        }
  }

  void ZoneAgricole::setTypeCulture(const std::string& typeCulture){
    this->typeCulture = typeCulture;
  }

  std::string ZoneAgricole::getTypeCulture() const{
    return typeCulture;
  }

  void ZoneAgricole::setType(const std::string& type) {
      Parcelle::setType(type);
  }

  // Surcharge de l'opérateur <<
  std::ostream& operator << (std::ostream& os, const ZoneAgricole& za) {
      os << std::endl << std::endl << "Affichage Zone Agricole " << std::endl;
      os << "Parcelle n°" << za.getNumero() << std::endl;
      os << "Type : " << za.ZoneNaturelle::getZoneType() << std::endl;
      //os << "Polygone: " << za.Constructible::getForme() << std::endl;
      os << "Proprietaire : " << za.getProprietaire() << std::endl;
      os << "Surface : " << za.getSurface() << "m²" << std::endl;
      os << "Pourcentage constructible : " << za.pConstructible << " %" << std::endl;
      os << "Surface constructible : " << za.surfaceConstructible() << "m²"<< std::endl;
      os << "Type de Culture : " << za.typeCulture << std::endl;

      return os;
  }
