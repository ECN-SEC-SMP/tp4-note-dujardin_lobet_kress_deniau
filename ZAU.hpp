#ifndef ZONENAURBANISER_HPP
#define ZONEAURBANISER_HPP

#include "Constructible.hpp"
#include <iostream>

class ZoneAUrbaniser : public Constructible
{

  public :

ZoneAUrbaniser(int num, const std::string& prop, const Polygone<int, float>& forme);

  //int surfaceConstructible() const override;

  //surcharge de l'opérateur <<
  friend std::ostream& operator<<(std::ostream& os, const ZoneAUrbaniser& zau);


};



std::ostream& operator << (std::ostream& os, const ZoneAUrbaniser& zau);


#endif // ZONEAURBANISER_HPP