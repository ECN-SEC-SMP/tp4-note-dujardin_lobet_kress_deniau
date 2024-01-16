#include <iostream>
#include "Point2D.hpp"
#include "Polygone.hpp"

int main() {
    // Test de la classe Polygone avec des entiers
    Polygone<int> poly1;

    Point2D<int> point1(1, 2);
    Point2D<int> point2(4, 5);
    Point2D<int> point3(7, 8);

    poly1.addPoint(point1);
    poly1.addPoint(point2);
    poly1.addPoint(point3);

    std::cout << "Sommets du polygone1 avant translation : ";
    for (const auto& point : poly1.getSommets()) {
        std::cout << "(" << point.getX() << ", " << point.getY() << ") ";
    }
    std::cout << std::endl;

    poly1.translate(2, 3);

    std::cout << "Sommets du polygone1 apres translation : ";
    for (const auto& point : poly1.getSommets()) {
        std::cout << "(" << point.getX() << ", " << point.getY() << ") ";
    }
    std::cout << std::endl;

    return 0;
}
