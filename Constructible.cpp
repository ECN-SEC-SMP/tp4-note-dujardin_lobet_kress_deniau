#include "Constructible.hpp"

Constructible::Constructible(int num, const std::string& prop, const Polygone<int, float>& forme)
    : Parcelle(num, prop, forme) {
    // Initialisation spécifique à Constructible si nécessaire
}
