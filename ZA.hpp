#include "ZN.hpp"
#include "Constructible.hpp"
#include <iostream>

class ZoneAgricole : public ZoneNaturelle, public Constructible 
{
  protected:

  public : 
    string ZoneAgricole::setculture(string cult) const; 
    ZoneAgricole(int SurfaceConstructible, int numero, string proprietaire, Polygone<int, float> forme, float surface);

//surcharge de l'opérateur <<
friend std::ostream& operator<<(std::ostream& os, const ZA& za) {

  //os << "Type : " << typeid(*this).name() << endl;
  //os << "Polygone: " << za.forme << endl;
  os << "Proprietaire : " << za.proprietaire << std::endl;
  os << "Surface : " << za.surface <<std::endl;
  os << "% Constructible : " << za.pConstructible << std::endl;
  os << "Culture : " << za.culture << std::endl;

    return os;
}
std::ostream& operator<<(std::ostream& os, const ZA& za);

};