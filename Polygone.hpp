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
    float getSurface() const;  // Ajout de la méthode pour obtenir la surface

    // Modificateurs
    void setSommets(const std::vector<Point2D<T, U>>& listeSommets);
    void addPoint(const Point2D<T, U>& point);

    // Autres méthodes
    void translate(T deltaX, U deltaY);
    void calculerSurface();  // Ajout de la méthode pour calculer la surface

private:
    std::vector<Point2D<T, U>> sommets;
    float surface;  // Ajout de l'attribut surface
};

// Implémentation des méthodes de la classe Polygone

template <typename T, typename U>
Polygone<T, U>::Polygone() : surface(0.0) {}  // Initialisation de la surface à 0

template <typename T, typename U>
Polygone<T, U>::Polygone(const std::vector<Point2D<T, U>>& listeSommets) : sommets(listeSommets) {
    calculerSurface();  // Calcul de la surface lors de la construction
}

template <typename T, typename U>
Polygone<T, U>::Polygone(const Polygone<T, U>& poly) : sommets(poly.sommets), surface(poly.surface) {}

template <typename T, typename U>
std::vector<Point2D<T, U>> Polygone<T, U>::getSommets() const {
    return sommets;
}

template <typename T, typename U>
float Polygone<T, U>::getSurface() const {
    return surface;
}

template <typename T, typename U>
void Polygone<T, U>::setSommets(const std::vector<Point2D<T, U>>& listeSommets) {
    sommets = listeSommets;
    calculerSurface();  // Mettez à jour la surface lorsque les sommets changent
}

template <typename T, typename U>
void Polygone<T, U>::addPoint(const Point2D<T, U>& point) {
    sommets.push_back(point);
    calculerSurface();  // Mettez à jour la surface lorsque les sommets changent
}

template <typename T, typename U>
void Polygone<T, U>::translate(T deltaX, U deltaY) {
    for (auto& point : sommets) {
        point.translate(deltaX, deltaY);
    }
    calculerSurface();  // Mettez à jour la surface après la translation
}

template <typename T, typename U>
void Polygone<T, U>::calculerSurface() {
    int n = sommets.size();
    float surfacePolygone = 0.0;

    for (int i = 0; i < n - 1; ++i) {
        surfacePolygone += sommets[i].getX() * sommets[i + 1].getY() - sommets[i + 1].getX() * sommets[i].getY();
    }

    surfacePolygone += sommets[n - 1].getX() * sommets[0].getY() - sommets[0].getX() * sommets[n - 1].getY();

    surfacePolygone = std::abs(surfacePolygone) / 2.0;

    surface = surfacePolygone;
}

#endif // POLYGONE_HPP
