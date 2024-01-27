#include "ZA.hpp"



ZoneAgricole::ZoneAgricole(int SurfaceConstructible, int numero, std::string proprietaire, Polygone<int, float> forme, float surface, std::string culture)
    : /*Parcelle(numero, proprietaire, forme, false, false)*/ZoneNaturelle(numero, proprietaire,forme), Constructible(SurfaceConstructible), culture(culture) {
    // Initialisation spécifique à ZoneNaturelle si nécessaire
}



void ZoneAgricole::setculture(std::string cult)
{
  culture = cult;
}
//constructeur:
ZoneAgricole::ZoneAgricole(int SurfaceConstructible, int numero, std::string proprietaire, Polygone<int, float> forme, float surface);


std::ostream& operator<<(std::ostream& os, const ZoneAgricole& za) {

  os << "Parcelle n°" << za.Constructible::getNumero() << std::endl;
  os << "Type : " <<  za.Constructible::getType()<< std::endl;
  //os << "Polygone: " << za.Parcelle::getForme() << std::endl;
  os << "Proprietaire : " << za.Constructible::getProprietaire() << std::endl;
  os << "Surface : " << za.Constructible::getSurface() <<std::endl;
  os << "% Constructible : " << za.Constructible::getpConstructible() << std::endl;
  //os << "Culture : " << ZoneAgricole.culture << std::endl;

    return os;
}