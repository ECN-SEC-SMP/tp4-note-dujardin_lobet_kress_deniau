#ifndef CONSTRUCTIBLE_HPP
#define CONSTRUCTIBLE_HPP

#include "Parcelle.hpp"

class Constructible : virtual public Parcelle {
public:
    Constructible(int num, const std::string& prop, const Polygone<int, float>& forme);

    virtual float surfaceConstructible() const = 0;
};

#endif // CONSTRUCTIBLE_HPP
