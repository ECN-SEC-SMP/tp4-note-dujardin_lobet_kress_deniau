#include "ZN.hpp"
#include "Constructible.hpp"

class ZA : public ZN, public Constructible 
{

//surcharge de l'opérateur <<
friend std::ostream& operator<<(std::ostream& os, const ZA& za) {

  os << "Type : " << typeid(*this).name() << endl;
  os << "Polygone: " << za.forme << endl;
  os << "Proprietaire : " << za.proprietaire << endl;
  os << "Surface : " << za.surface << endl;
  os << "% Constructible : " << za.pConstructible << endl;

    return os;
}

};