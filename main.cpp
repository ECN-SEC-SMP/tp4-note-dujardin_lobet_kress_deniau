#include <iostream>
#include "Point2D.h"

int main() {
    // Test de la classe Point2D avec des entiers
    Point2D<int> point1(1, 2);
    Point2D<int> point2;
    Point2D<int> point3(point1);

    std::cout << "Coordonnees du point1 : (" << point1.getX() << ", " << point1.getY() << ")" << std::endl;
    std::cout << "Coordonnees du point2 : (" << point2.getX() << ", " << point2.getY() << ")" << std::endl;
    std::cout << "Coordonnees du point3 : (" << point3.getX() << ", " << point3.getY() << ")" << std::endl;

    point2.setX(5);
    point2.setY(8);

    std::cout << "Nouvelles coordonnees du point2 : (" << point2.getX() << ", " << point2.getY() << ")" << std::endl;

    point3.translate(2, -3);

    std::cout << "Coordonnees du point3 apres translation : (" << point3.getX() << ", " << point3.getY() << ")" << std::endl;

    return 0;
}