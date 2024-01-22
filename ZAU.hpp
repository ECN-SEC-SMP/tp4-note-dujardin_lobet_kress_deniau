#include "Constructible.hpp"

class ZAU : public Constructible
{

  public :

  int surfaceConstructible() const override;

  //surcharge de l'opérateur <<
  friend std::ostream& operator<<(std::ostream& os, const ZAU& zau) {
  };


};


std::ostream& operator << (std::ostream& os, const ZAU& zau);