#ifndef POINT2D_HPP
#define POINT2D_HPP

template <typename T, typename U>
class Point2D {
public:
    Point2D(T x, U y);
    T getX() const;
    U getY() const;
    void translate(T deltaX, U deltaY);

private:
    T x;
    U y;
};

// Implémentation des méthodes de la classe Point2D

template <typename T, typename U>
Point2D<T, U>::Point2D(T x, U y) : x(x), y(y) {}

template <typename T, typename U>
T Point2D<T, U>::getX() const {
    return x;
}

template <typename T, typename U>
U Point2D<T, U>::getY() const {
    return y;
}

template <typename T, typename U>
void Point2D<T, U>::translate(T deltaX, U deltaY) {
    x += deltaX;
    y += deltaY;
}

#endif // POINT2D_HPP