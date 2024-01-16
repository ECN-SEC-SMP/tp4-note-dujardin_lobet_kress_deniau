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
      os << "Type : " << typeid(*this).name() << endl;
      os << "Polygone : " << zn.forme << endl;
      os << "Proprietaire : " << zn.proprietaire << endl;
      os << "Surface : " << zn.surface << endl;
      return os;
  }


};