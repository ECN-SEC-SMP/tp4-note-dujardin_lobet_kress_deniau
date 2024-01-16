#include <iostream>
#include "Point2D.hpp"
#include "Polygone.hpp"

int main() {
    // Création d'un polygone avec des points
    Polygone<int, float> poly;
    poly.addPoint(Point2D<int, float>(0, 0));
    poly.addPoint(Point2D<int, float>(1, 0));
    poly.addPoint(Point2D<int, float>(1, 1));
    poly.addPoint(Point2D<int, float>(0, 1));

    // Affichage des sommets du polygone
    std::cout << "Sommets du polygone : ";
    for (const auto& point : poly.getSommets()) {
        std::cout << "(" << point.getX() << ", " << point.getY() << ") ";
    }
    std::cout << std::endl;

    // Translation du polygone
    poly.translate(1, 1);

    // Affichage des sommets après la translation
    std::cout << "Sommets après translation : ";
    for (const auto& point : poly.getSommets()) {
        std::cout << "(" << point.getX() << ", " << point.getY() << ") ";
    }
    std::cout << std::endl;

    return 0;
}