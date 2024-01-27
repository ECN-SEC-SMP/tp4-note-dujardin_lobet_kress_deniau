#ifndef CARTE_HPP
#define CARTE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "Point2D.hpp"
#include "Polygone.hpp"
#include "Parcelle.hpp"
#include "ZN.hpp"
#include "ZA.hpp"
#include "ZAU.hpp"
#include "ZU.hpp"

class Carte {
private:
    std::vector<Parcelle*> parcelles; // Utilisation de pointeurs pour permettre la polymorphie
    float surfaceCarte;

public:
    // Constructeur
    Carte(const std::string& fichier);

    // Destructeur
    //~Carte();

    // Méthode pour calculer la surface totale de la carte
    void calculerSurfaceCarte();

    // Méthode pour afficher les détails de la carte
    void afficherDetailsCarte() const;
};

#endif // CARTE_HPP
