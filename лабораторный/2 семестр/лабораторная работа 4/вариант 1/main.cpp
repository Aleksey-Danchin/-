#include <iostream>

using namespace std;

// Класс точки
class Point {
    // Статические величины координаты прямой
    public: static float pk;
    public: static float pb;

    // Статический метод для получения значение Point::pk
    public: static float k() {
        return Point::pk;
    }

    // Статический метод для присваивания значение Point::pk
    public: static float k(float new_k) {
        Point::pk = new_k;
        return new_k;
    }

    // Статический метод для получения значение Point::pb
    public: static float b() {
        return Point::pb;
    }

    // Статический метод для присваивания значение Point::pb
    public: static float b(float new_b) {
        Point::pb = new_b;
        return new_b;
    }

    // Статические метод проверки принадлежности точки прямой
    public: static bool contains (Point p) {
        float y = Point::pk * p.x + Point::pb;
        return abs(p.y - y) < 0.0001;
    }

    // Конструктор для точки
    Point (float x, float y) {
        this->x = x;
        this->y = y;
    }

    // Свойства точки (координаты)
    public: float x;
    public: float y;
};

// Инициализация координат прямой
float Point::pk = -1;
float Point::pb = -1;

int main () {
    // Проверяем возможность запросить статические координаты прямой
    cout << Point::k() << " " << Point::b() << endl;

    // Проверяем возможность изменить статические координаты прямой
    Point::k(1);
    Point::b(0);
    cout << Point::k() << " " << Point::b() << endl;
    
    // Описываем 3 точки
    Point p1(0, 0);
    Point p2(1, 1);
    Point p3(4.999999, 5.000001);

    // Проверяем принадлежность точек прямой
    cout << Point::contains(p1) << endl;
    cout << Point::contains(p2) << endl;
    cout << Point::contains(p3) << endl;
}