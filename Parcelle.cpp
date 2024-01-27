#include "Parcelle.hpp"

// Constructeur

// Implémentation du constructeur par défaut
Parcelle::Parcelle() : numero(0), proprietaire(""), forme(), surface(0.0f), type("") {}
// Constructeur de la classe Parcelle
Parcelle::Parcelle(int num, const std::string& prop, const Polygone<int, float>& forme)
    : numero(num), proprietaire(prop), forme(forme), type(""), pConstructible(1) {
    // Calcul de la surface à partir du polygone lors de la construction
    surface = forme.getSurface();
    // Vérification de la surface
    if (surface <= 0.0f) {
       throw std::invalid_argument("La surface d'une parcelle doit être strictement positive.");
    }
}

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

// Modificateur pour mettre à jour la forme de la parcelle et recalculer la surface
void Parcelle::setForme(const Polygone<int, float>& f) {
    forme = f;
    // Recalcul de la surface lorsque la forme change
    surface = forme.getSurface();
}

void Parcelle::setType(const std::string& t) {
    type = t;
}
void Parcelle::setSurface(float nouvelleSurface) {
    if (nouvelleSurface <= 0) {
        throw std::invalid_argument("La surface d'une parcelle doit être positive et non nulle.");
    }

    surface = nouvelleSurface;
}

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& os, Parcelle& parcelle) {

  os << "Numéro: " << parcelle.getNumero() << "\n"
    << "Propriétaire: " << parcelle.getProprietaire() << "\n"
    << "Surface: " << parcelle.getSurface()<< "\n"
    << "Type: " << parcelle.getType() << "\n";
  os << "Informations sur la parcelle :\n";
  // Afficher les sommets du polygone (à titre d'exemple)
  os << "Sommets du polygone : ";
  for (const auto& point : parcelle.getForme().getSommets()) {
      os << "(" << point.getX() << ", " << point.getY() << ") ";
  }
  os << "\n";

  // Afficher la surface du polygone
  os << "Surface du polygone : " << parcelle.getForme().getSurface() << " m²\n";

  os << "Surface : " << parcelle.getSurface() << " m²\n";
  // Ajoutez d'autres informations si nécessaire

    return os;
}