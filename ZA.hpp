#ifndef ZA_HPP
#define ZA_HPP

#include "ZN.hpp"
#include "Constructible.hpp"
#include <iostream>
#include <string>


class ZoneAgricole : public ZoneNaturelle,  public Constructible
{
  protected:
    std::string culture; 

  public : 
    // seteur
    void setculture(std::string cult) ; 
    // constructeur
    ZoneAgricole(int SurfaceConstructible, int numero, std::string proprietaire, Polygone<int, float> forme, float surface, std::string culture);

//surcharge de l'opérateur <<
friend std::ostream& operator<<(std::ostream& os, const ZoneAgricole& za) ;


};
std::ostream& operator<<(std::ostream& os, const ZoneAgricole& za);

#endif // ZA_HPP