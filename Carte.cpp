#include "Carte.hpp"


Carte::Carte(const std::string& fichier) : surfaceCarte(0.0) {
    std::ifstream file(fichier); // Ouverture du fichier
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier.");
    }

    // Lecture du fichier ligne par ligne
    std::string line;
    while (std::getline(file, line)) {
        // Création d'un flux (stream) à partir de la ligne pour faciliter la lecture
        std::istringstream iss(line);

        // Lecture du type de parcelle (ZA, ZN, ZU, ZAU)
        std::string typeParcelle;
        iss >> typeParcelle;

        // Variables temporaires pour stocker les informations de la première ligne
        int numero;
        std::string proprietaire;
        float surfaceConstruite;
        std::string typeCulture;

        // Lecture des informations communes à tous les types de parcelles
        iss >> numero >> proprietaire;

        // Lecture des informations spécifiques aux ZA
        if (typeParcelle == "ZA") {
            iss >> typeCulture;
        }
        // Lecture des informations spécifiques aux ZU
        else if (typeParcelle == "ZU") {
            iss >> surfaceConstruite;
        }
        // Lecture des informations spécifiques aux ZAU
        else if (typeParcelle == "ZAU") {
            // Aucune information spécifique pour le moment
        }
        // Lecture des informations spécifiques aux ZN
        else if (typeParcelle == "ZN") {
            // Aucune information spécifique pour le moment
        }

        // Création d'une liste pour stocker les points du polygone
        std::vector<Point2D<int, float>> pointsPolygone;

        // Lecture des points du polygone de la parcelle
        int x, y;
        while (iss >> x >> y) {
            pointsPolygone.push_back(Point2D<int, float>(x, y));
        }

        // Création du polygone
        Polygone<int, float> polygone(pointsPolygone);

        // Création de la parcelle en fonction du type
        Parcelle* nouvelleParcelle = nullptr;

        if (typeParcelle == "ZA") {
            nouvelleParcelle = new ZoneAgricole(numero, proprietaire, polygone, typeCulture);
        } else if (typeParcelle == "ZN") {
            nouvelleParcelle = new ZoneNaturelle(numero, proprietaire, polygone);
        } else if (typeParcelle == "ZU") {
            nouvelleParcelle = new ZoneUrbaine(numero, proprietaire, polygone, surfaceConstruite);
        } else if (typeParcelle == "ZAU") {
            nouvelleParcelle = new ZoneAUrbaniser(numero, proprietaire, polygone);
        } else {
            // Type de parcelle inconnu, vous pouvez gérer cela selon vos besoins
            std::cerr << "Type de parcelle inconnu : " << typeParcelle << std::endl;
            continue;  // Passe à la ligne suivante
        }

        // Ajout de la nouvelle parcelle à la liste des parcelles
        parcelles.push_back(nouvelleParcelle);
    }

    // Fermeture du fichier
    file.close();

    // Calcul de la surface totale de la carte
    calculerSurfaceCarte();
}
/*
// Définition du destructeur
Carte::~Carte() {
    // Libération de la mémoire allouée pour chaque parcelle
    for (auto& parcelle : parcelles) {
        delete parcelle;
    }
}*/

// Définition de la méthode pour calculer la surface totale de la carte
void Carte::calculerSurfaceCarte() {
    surfaceCarte = 0.0;
    for (const auto& parcelle : parcelles) {
        surfaceCarte += parcelle->getSurface();
    }
}

// Définition de la méthode pour afficher les détails de la carte
void Carte::afficherDetailsCarte() const {
    std::cout << "Détails de la carte :" << std::endl;
    for (const auto& parcelle : parcelles) {
        std::cout << *parcelle << std::endl; // Utilisation de l'opérateur de flux de sortie surchargé
    }
    std::cout << "Surface totale de la carte : " << surfaceCarte << " m²" << std::endl;
}
