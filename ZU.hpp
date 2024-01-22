#include "ZAU.hpp"
#include <iostream>

class ZoneUrbaine : public ZoneAUrbaniser 
{

  private :

  //string surfaceConstruite;

  public :

  int surfaceConstructible()const override;

  //surcharge de l'opérateur <<
  friend std::ostream& operator<<(std::ostream& os, const ZoneUrbaine& zu);
};
std::ostream& operator<<(std::ostream& os, const ZoneUrbaine& zu);