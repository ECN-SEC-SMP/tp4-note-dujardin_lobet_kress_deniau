#include <iostream>
#include "Polygone.hpp"
#include "Parcelle.hpp"
#include "ZN.hpp"
#include "ZA.hpp"
#include "ZAU.hpp"
#include "ZU.hpp"

#include <fstream>
//#include "Carte.hpp"

int main() {
  
    // Création d'une parcelle avec un polygone
    Polygone<int, float> poly;
    poly.addPoint(Point2D<int, float>(0, 0));
    poly.addPoint(Point2D<int, float>(1, 0));
    poly.addPoint(Point2D<int, float>(1, 1));
    poly.addPoint(Point2D<int, float>(0, 1));

    Parcelle parcelle(1, "Proprietaire1", poly);

    // Affichage des informations sur la parcelle en utilisant la surcharge de l'opérateur <<
    std::cout << parcelle << std::endl;

    // Modification de la parcelle
    parcelle.setNumero(2);
    parcelle.setProprietaire("Proprietaire2");

    // Affichage des informations mises à jour sur la parcelle
    std::cout << parcelle << std::endl;

    //test de la foncion translater
    poly.translate(2,3);
    Polygone<int, float> poly2(poly); //création d'un polygone par copie
  poly2.translate(1,1);
    Parcelle parcelle2(1, "Proprietaire3", poly2);
    std::cout << parcelle2 << std::endl;



  

    // Création d'un polygone pour la zone naturelle
    std::vector<Point2D<int, float>> sommets = { {0, 0}, {0, 5}, {5, 5}, {5, 0} };
  Polygone<int, float> polygone(sommets);

    // Création d'une zone naturelle
    ZoneNaturelle zoneNaturelle(1, "Proprietaire1", polygone);

    // Affichage des informations
    std::cout << zoneNaturelle << std::endl;

    // Création d'un polygone pour la zone naturelle
    std::vector<Point2D<int, float>> sommet = { {10, 11}, {20, 17}, {26, 20}, {13
  , 22} };
  Polygone<int, float> polygoneagri(sommet);
    // Création d'une instance de ZoneAgricole
    ZoneAgricole zoneAgricole(2, "Propriétaire2", polygoneagri, "Riz");

    // Affichage des détails de la ZoneAgricole
    std::cout << zoneAgricole << std::endl;

    // Création d'un polygone pour la zone naturelle
    std::vector<Point2D<int, float>> sommets2 = { {0, 0}, {0, 100}, {100, 100}, {100, 0} };
  Polygone<int, float> polygoneagri2(sommets2);
    // Création d'une instance de ZoneAgricole
    ZoneAgricole zoneAgricole2(2, "Eloi", polygoneagri2, "betrave");

    // Affichage des détails de la ZoneAgricole
    std::cout << zoneAgricole2 << std::endl;



    // Création d'un polygone pour la zone à urbaniser
    std::vector<Point2D<int, float>> sommetsUrbaniser = { {5, 5}, {5, 10}, {10, 10}, {10, 5} };
    Polygone<int, float> polygoneUrbaniser(sommetsUrbaniser);

    // Création d'une instance de ZoneAUrbaniser
    ZoneAUrbaniser zoneUrbaniser(3, "Alexandre", polygoneUrbaniser);

    // Affichage des détails de la ZoneAUrbaniser
    std::cout << zoneUrbaniser << std::endl;

    // Création d'un polygone pour la zone urbaine
    std::vector<Point2D<int, float>> sommetsUrbaniser2 = { {0, 0}, {0, 15}, {10, 15}, {10, 5}, {5, 0} };
    Polygone<int, float> polygoneUrbaniser2(sommetsUrbaniser2);

    // Création d'une zone urbaine
    ZoneUrbaine zoneUrbaine(3, "Maxime", polygoneUrbaniser2, 20.0f);

    // Affichage des détails de la ZoneUrbaine
    std::cout << zoneUrbaine << std::endl;

  // Création d'une zone urbaine
  ZoneUrbaine zoneUrbaine2(4, "Maxime", polygoneUrbaniser2, 36.0f);

  // Affichage des détails de la ZoneUrbaine
  std::cout << zoneUrbaine2 << std::endl;

  try {
      // Tentative de création d'une parcelle avec une surface négative
      Polygone<int, float> poly;
      poly.addPoint(Point2D<int, float>(0, 0));
      poly.addPoint(Point2D<int, float>(-1, 0));
      poly.addPoint(Point2D<int, float>(-1, -1));
      poly.addPoint(Point2D<int, float>(0, -1));

      // Tentative de création d'une parcelle avec une surface négative
      Parcelle parcelle(1, "Proprietaire1", poly);

      // Affichage des informations sur la parcelle
      std::cout << parcelle << std::endl;
      parcelle.setSurface(-10.0f);  // Essayez de définir une surface négative

      // Affichage des informations sur la parcelle
      std::cout << parcelle << std::endl;
  } catch (const std::invalid_argument& e) {
      std::cerr << "Exception : " << e.what() << std::endl;
  }

  
    return 0;
}