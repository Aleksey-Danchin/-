#include <iostream>

using namespace std;

// Класс точки
class Point {
    // Конструктор для точки
    public: Point (float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }

    // Свойства точки (координаты)
    public: float x;
    public: float y;

    // Лаба 5
    public: Point operator + (Point p) {
        return Point(
            this->x + p.x,
            this->y + p.y
        );
    }

    public: Point operator - (Point p) {
        return Point(
            this->x - p.x,
            this->y - p.y
        );
    }

    public: Point operator * (Point p) {
        return Point(
            this->x * p.x,
            this->y * p.y
        );
    }
};

// Лаба 6
ostream& operator << (ostream &out, Point p) {
    out << "Point(" << p.x << ", " << p.y << ");" << endl;
    return out;
}

istream& operator >>  (istream &in, Point& p) {
    cout << "x: ";
    in >> p.x;

    cout << "y: ";
    in >> p.y;

    return in;
}

int main () {
    // Описываем 3 точки
    Point a(1, 5);
    cin >> a;

    Point b(-3, 2);
    cin >> b;

    Point c = a + b;
    Point d = a * b;

    cout << a;
    cout << b;
    cout << c; 
    cout << d; 
}