#include "Constructible.hpp"

class ZAU : public Constructible
{

  public :

  int surfaceConstructible() const override;

  //surcharge de l'opérateur <<
  friend std::ostream& operator<<(std::ostream& os, const ZAU& zau) {

    os << "Type : " << typeid(*this).name() << endl;
    os << "Polygone: " << zau.proprietaire << endl;
    os << "Proprietaire : " << zau.proprietaire << endl;
    os << "Surface : " << zau.surface << endl;
    os << "% Constructible : " << zau.pConstructible << endl;
    
      return os;
  }


};