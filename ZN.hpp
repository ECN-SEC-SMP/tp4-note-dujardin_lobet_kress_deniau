#include "Parcelle.hpp"

class ZN : public Parcelle
{
  public :

  int surfaceConstructible() const override;


};

#include "Constructible.hpp"

class ZAU : public Constructible
{

  public :

  int surfaceConstructible() const override;

  //surcharge de l'opérateur <<
  friend std::ostream& operator<<(std::ostream& os, const ZN& zn) {
      os << "Type : " << zn.type << endl;
      os << "Polygone : " << zau.proprietaire << endl;
      os << "Proprietaire : " << zau.proprietaire << endl;
      os << "Surface : " << zau.surface << endl;
      return os;
  }


};