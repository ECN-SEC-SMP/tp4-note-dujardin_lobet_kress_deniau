#ifndef PARCELLE_HPP
#define PARCELLE_HPP

#include <string>
#include "Polygone.hpp"

class Parcelle {
public:
    // Constructeurs
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
    void setType(const std::string& type);

private:
    int numero;
    std::string proprietaire;
    Polygone<int, float> forme;
    float surface;
    std::string type;
    int pConstructible = 1; // Valeur par défaut
};

#endif // PARCELLE_HPP
