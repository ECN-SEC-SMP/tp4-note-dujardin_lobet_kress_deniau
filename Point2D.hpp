#ifndef POINT2D_H
#define POINT2D_H

template <typename T>
class Point2D {
public:
    // Constructeurs
    Point2D(T x, T y);
    Point2D();
    Point2D(const Point2D<T>& p);

    // Accesseurs
    T getX() const;
    T getY() const;

    // Modificateurs
    void setX(T x);
    void setY(T y);

    // Autres méthodes
    void translate(T deltaX, T deltaY);

private:
    T x;
    T y;
};

// Implémentation des méthodes de la classe Point2D

template <typename T>
Point2D<T>::Point2D(T x, T y) : x(x), y(y) {}

template <typename T>
Point2D<T>::Point2D() : x(T()), y(T()) {}

template <typename T>
Point2D<T>::Point2D(const Point2D<T>& p) : x(p.x), y(p.y) {}

template <typename T>
T Point2D<T>::getX() const {
    return x;
}

template <typename T>
T Point2D<T>::getY() const {
    return y;
}

template <typename T>
void Point2D<T>::setX(T x) {
    this->x = x;
}

template <typename T>
void Point2D<T>::setY(T y) {
    this->y = y;
}

template <typename T>
void Point2D<T>::translate(T deltaX, T deltaY) {
    x += deltaX;
    y += deltaY;
}

#endif // POINT2D_H
