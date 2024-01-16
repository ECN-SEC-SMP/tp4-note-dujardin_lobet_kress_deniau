#ifndef POLYGONE_HPP
#define POLYGONE_HPP

#include <vector>
#include "Point2D.hpp"

template <typename T>
class Polygone {
public:
    // Constructeurs
    Polygone();
    Polygone(const std::vector<Point2D<T>>& listeSommets);
    Polygone(const Polygone<T>& poly);

    // Accesseurs
    std::vector<Point2D<T>> getSommets() const;

    // Modificateurs
    void setSommets(const std::vector<Point2D<T>>& listeSommets);
    void addPoint(const Point2D<T>& point);

    // Autres méthodes
    void translate(T deltaX, T deltaY);

private:
    std::vector<Point2D<T>> sommets;
};

// Implémentation des méthodes de la classe Polygone

template <typename T>
Polygone<T>::Polygone() {}

template <typename T>
Polygone<T>::Polygone(const std::vector<Point2D<T>>& listeSommets) : sommets(listeSommets) {}

template <typename T>
Polygone<T>::Polygone(const Polygone<T>& poly) : sommets(poly.sommets) {}

template <typename T>
std::vector<Point2D<T>> Polygone<T>::getSommets() const {
    return sommets;
}

template <typename T>
void Polygone<T>::setSommets(const std::vector<Point2D<T>>& listeSommets) {
    sommets = listeSommets;
}

template <typename T>
void Polygone<T>::addPoint(const Point2D<T>& point) {
    sommets.push_back(point);
}

template <typename T>
void Polygone<T>::translate(T deltaX, T deltaY) {
    for (auto& point : sommets) {
        point.translate(deltaX, deltaY);
    }
}

#endif // POLYGONE_HPP
