#ifndef POLYGONE_HPP
#define POLYGONE_HPP

#include <vector>
#include "Point2D.hpp"

template <typename T, typename U>
class Polygone {
public:
    // Constructeurs
    Polygone();
    Polygone(const std::vector<Point2D<T, U>>& listeSommets);
    Polygone(const Polygone<T, U>& poly);

    // Accesseurs
    std::vector<Point2D<T, U>> getSommets() const;

    // Modificateurs
    void setSommets(const std::vector<Point2D<T, U>>& listeSommets);
    void addPoint(const Point2D<T, U>& point);

    // Autres méthodes
    void translate(T deltaX, U deltaY);

private:
    std::vector<Point2D<T, U>> sommets;
};

// Implémentation des méthodes de la classe Polygone

template <typename T, typename U>
Polygone<T, U>::Polygone() {}

template <typename T, typename U>
Polygone<T, U>::Polygone(const std::vector<Point2D<T, U>>& listeSommets) : sommets(listeSommets) {}

template <typename T, typename U>
Polygone<T, U>::Polygone(const Polygone<T, U>& poly) : sommets(poly.sommets) {}

template <typename T, typename U>
std::vector<Point2D<T, U>> Polygone<T, U>::getSommets() const {
    return sommets;
}

template <typename T, typename U>
void Polygone<T, U>::setSommets(const std::vector<Point2D<T, U>>& listeSommets) {
    sommets = listeSommets;
}

template <typename T, typename U>
void Polygone<T, U>::addPoint(const Point2D<T, U>& point) {
    sommets.push_back(point);
}

template <typename T, typename U>
void Polygone<T, U>::translate(T deltaX, U deltaY) {
    for (auto& point : sommets) {
        point.translate(deltaX, deltaY);
    }
}

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const Polygone<T, U>& poly) {
  os << "Polygone: ";

  for (const auto& point : poly.getSommets()) {
      os << "(" << point.getX() << ", " << point.getY() << ") ";
  }
 
    return os;
}

#endif // POLYGONE_HPP
