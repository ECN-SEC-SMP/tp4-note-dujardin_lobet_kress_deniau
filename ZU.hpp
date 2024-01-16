#include "ZAU.hpp"

class ZU : public ZAU 
{

  private :

  string surfaceConstruite;

  public :

  int surfaceConstructible()const override;

  //surcharge de l'opérateur <<
  friend std::ostream& operator<<(std::ostream& os, const ZU& zu) {
      os << "Type : " << typeid(*this).name() << endl;
      os << "Polygone : " << zu.forme << endl;
      os << "Proprietaire : " << zu.proprietaire << endl;
      os << "Surface : " << zu.surface << endl;
      os << "% Constructible : " << zu.pConstructible << endl;
      os << "Surface construite : " << (1-zu.pConstructible)* << endl;
      return os;
  }

};
