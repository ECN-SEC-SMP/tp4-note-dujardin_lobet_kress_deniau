#ifndef PARCELLE_HPP
#define PARCELLE_HPP

#include <iostream>
#include <string>
#include "Polygone.hpp"

class Parcelle {
public:
    // Constructeurs
    Parcelle();  // Déclaration du constructeur par défaut
    Parcelle(int num, const std::string& prop, const Polygone<int, float>& forme);
    Parcelle(const Parcelle& parc);

    // Accesseurs
    int getNumero() const;
    std::string getProprietaire() const;
    float getSurface() const;
    Polygone<int, float> getForme() const;
    std::string getType() const;

    // Modificateurs
    void setNumero(int n);
    void setProprietaire(const std::string& prop);
    void setForme(const Polygone<int, float>& forme);
    virtual void setType(const std::string& type);
    void setSurface(float nouvelleSurface);

    // Surcharge de l'opérateur <<
    friend std::ostream& operator<<(std::ostream& os, Parcelle& parcelle);

protected:
    int numero;
    std::string proprietaire;
    Polygone<int, float> forme;
    float surface;
    std::string type;
    int pConstructible; // Valeur par défaut
};

// Déclaration de la surcharge de l'opérateur de flux << en dehors de la classe
std::ostream& operator<<(std::ostream& os, Parcelle& parcelle);


#endif // PARCELLE_HPP