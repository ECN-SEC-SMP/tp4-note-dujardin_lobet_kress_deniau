#include <iostream>
#include "Point2D.hpp"
#include "Polygone.hpp"
#include "Parcelle.hpp"
#include "ZN.hpp"


int main() {
    // Test de la classe Point2D
    Point2D<int, float> point1(1, 2.5);
    std::cout << "Point 1 - X: " << point1.getX() << ", Y: " << point1.getY() << std::endl;

    // Test de la translation du point
    point1.translate(2, 3.5);
    std::cout << "Point 1 après translation - X: " << point1.getX() << ", Y: " << point1.getY() << std::endl;

    // Test de la classe Polygone
    std::vector<Point2D<int, float>> listePoints = {Point2D<int, float>(0, 0), Point2D<int, float>(1, 1), Point2D<int, float>(2, 0)};
    Polygone<int, float> polygone1(listePoints);

    // Affichage des sommets du polygone
    std::cout << "Polygone 1 - Sommets: ";
    for (const auto& point : polygone1.getSommets()) {
        std::cout << "(" << point.getX() << ", " << point.getY() << ") ";
    }
    std::cout << std::endl;

    // Translation du polygone
    polygone1.translate(1, 1);
    std::cout << "Polygone 1 après translation - Sommets: ";
    for (const auto& point : polygone1.getSommets()) {
        std::cout << "(" << point.getX() << ", " << point.getY() << ") ";
    }
    std::cout << std::endl;

    // Test de la classe Parcelle
    Parcelle parcelle1(1, "Proprietaire1", polygone1);
    std::cout << "Parcelle 1 - Numero: " << parcelle1.getNumero() << ", Proprietaire: " << parcelle1.getProprietaire()
              << ", Surface: " << parcelle1.getSurface() << ", Type: " << parcelle1.getType() << std::endl;

    // Modification de la parcelle
    parcelle1.setNumero(2);
    parcelle1.setProprietaire("NouveauProprietaire");
    parcelle1.setForme(Polygone<int, float>({Point2D<int, float>(3, 3), Point2D<int, float>(4, 4), Point2D<int, float>(5, 3)}));
    parcelle1.setType("NouveauType");

    // Affichage de la parcelle après modification
    std::cout << "Parcelle 1 après modification - Numero: " << parcelle1.getNumero() << ", Proprietaire: " << parcelle1.getProprietaire()
              << ", Surface: " << parcelle1.getSurface() << ", Type: " << parcelle1.getType() << std::endl;
  
  // Création d'un polygone pour la zone naturelle
  std::vector<Point2D<int, float>> sommets = { {0, 0}, {0, 5}, {5, 5}, {5, 0} };
  Polygone<int, float> polygone(sommets);

  // Création d'une zone naturelle
  ZoneNaturelle zoneNaturelle(1, "Proprietaire1", polygone);

  // Affichage des informations
  std::cout << zoneNaturelle << std::endl;
    return 0;
}
