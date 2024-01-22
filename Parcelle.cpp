#include "Parcelle.hpp"

// Constructeur
Parcelle::Parcelle(int num, const std::string& prop, const Polygone<int, float>& forme)
    : numero(num), proprietaire(prop), forme(forme), surface(0), type(""), pConstructible(1) {}

// Constructeur de copie
Parcelle::Parcelle(const Parcelle& parc)
    : numero(parc.numero), proprietaire(parc.proprietaire), forme(parc.forme),
      surface(parc.surface), type(parc.type), pConstructible(parc.pConstructible) {}

// Accesseurs
int Parcelle::getNumero() const {
    return numero;
}

std::string Parcelle::getProprietaire() const {
    return proprietaire;
}

float Parcelle::getSurface() const {
    return surface;
}

Polygone<int, float> Parcelle::getForme() const {
    return forme;
}

std::string Parcelle::getType() const {
    return type;
}

// Modificateurs
void Parcelle::setNumero(int n) {
    numero = n;
}

void Parcelle::setProprietaire(const std::string& prop) {
    proprietaire = prop;
}

void Parcelle::setForme(const Polygone<int, float>& f) {
    forme = f;
}

void Parcelle::setType(const std::string& t) {
    type = t;
}

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& os, Parcelle& parcelle) {
  /*
    os << "Numéro: " << parcelle.numero << "\n"
       << "Propriétaire: " << parcelle.proprietaire << "\n"
       << "Surface: " << parcelle.surface << "\n"
       << "Type: " << parcelle.type << "\n"
       << "Forme: " << parcelle.forme << "\n";*/

  os << "Informations sur la parcelle :\n";
  os << "Surface : " << parcelle.getSurface() << " m²\n";
  // Ajoutez d'autres informations si nécessaire

    return os;
}