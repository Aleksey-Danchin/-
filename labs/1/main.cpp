#include <iostream>

using namespace std;

class Point {
    public:
        float x;
        float y;
    
    Point (float arg1, float arg2) {
        x = arg1;
        y = arg2;
    }
};

class Line {
    public:
        float k;
        float b;
    
    Line (float arg1, float arg2) {
        k = arg1;
        b = arg2;
    };

    bool contain (Point p) {
        float y = this->k * p.x + this->b;
        return abs(p.y - y) < 0.0001;
    };
};

int main () {
    Line line(2, -1);
    Point point1(0, -1);
    Point point2(0, 1);

    cout << line.contain(point1) << endl;
    cout << line.contain(point2) << endl;
}