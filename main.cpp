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
/*
  // Création d'une carte
  Carte maCarte;

  // Lecture du fichier Parcelle_short.txt
  std::ifstream fichierEntree("Parcelle_short.txt");
  if (!fichierEntree.is_open()) {
      std::cerr << "Erreur lors de l'ouverture du fichier Parcelle_short.txt" << std::endl;
      return 1;
  }

  // Lecture des informations du fichier
  while (!fichierEntree.eof()) {
      // Lecture du type de parcelle
      std::string typeParcelle;
      fichierEntree >> typeParcelle;
    // Création d'une parcelle en fonction du type
    if (typeParcelle == "ZU") {
        int numero, pConstructible, surfaceConstruite;
        std::string proprietaire;

        // Lecture des informations spécifiques à ZU
        fichierEntree >> numero >> proprietaire >> pConstructible >> surfaceConstruite;

        // Lecture des points du polygone
        Polygone<int, float> polygone;
        lirePolygone(fichierEntree, polygone);

        // Création de la parcelle ZU
        ZoneUrbaine maParcelleZU(numero, proprietaire, polygone, pConstructible, surfaceConstruite);

        // Ajout de la parcelle à la carte
        maCarte.ajouterParcelle(maParcelleZU);
    } 
    else if (typeParcelle == "ZAU") {
        int numero, pConstructible;
        std::string proprietaire;

        // Lecture des informations spécifiques à ZAU
        fichierEntree >> numero >> proprietaire >> pConstructible;

        // Lecture des points du polygone
        Polygone<int, float> polygone;
        lirePolygone(fichierEntree, polygone);

        // Création de la parcelle ZAU
        ZoneAUrbaniser maParcelleZAU(numero, proprietaire, polygone, pConstructible);

        // Ajout de la parcelle à la carte
        maCarte.ajouterParcelle(maParcelleZAU);
    }
    else if (typeParcelle == "ZA") {
        int numero;
        std::string proprietaire, typeCulture;

        // Lecture des informations spécifiques à ZA
        fichierEntree >> numero >> proprietaire >> typeCulture;

        // Lecture des points du polygone
        Polygone<int, float> polygone;
        lirePolygone(fichierEntree, polygone);

        // Création de la parcelle ZA
        ZoneAgricole maParcelleZA(numero, proprietaire, polygone, typeCulture);

        // Ajout de la parcelle à la carte
        maCarte.ajouterParcelle(maParcelleZA);
    } 
    else if (typeParcelle == "ZN") {
        int numero;
        std::string proprietaire;

        // Lecture des informations spécifiques à ZN
        fichierEntree >> numero >> proprietaire;

        // Lecture des points du polygone
        Polygone<int, float> polygone;
        lirePolygone(fichierEntree, polygone);

        // Création de la parcelle ZN
        ZoneNaturelle maParcelleZN(numero, proprietaire, polygone);

        // Ajout de la parcelle à la carte
        maCarte.ajouterParcelle(maParcelleZN);
    } 
    else {
        // Type de parcelle inconnu
        std::cerr << "Type de parcelle inconnu : " << typeParcelle << std::endl;
        return 1;
    }
  }

  // Fermeture du fichier
  fichierEntree.close();

  // Affichage des informations de la carte
  maCarte.afficherCarte();

*/
    return 0;
}