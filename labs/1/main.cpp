#include <iostream>
#include <fstream>
#include <cmath> 

using namespace std;

class Point {
    public:
        float x;
        float y;
    
    Point (float arg1 = 0.001, float arg2 = 0.001) {
        x = arg1;
        y = arg2;
    };

    static Point* readPoints (string path, int &number) {
        ifstream file;
        file.open(path);

        if (file.is_open()) {
            file >> number;
            Point* points = new Point[number];

            for (int i = 0; i < number; i++) {
                file >> points[i].x;
                file >> points[i].y;
            }

            file.close();
            return points;
        }

        number = 0;
        Point* points = new Point[0];
        return points;
    };
};

class Line {
    public:
        float k = 0.001;
        float b = 0.001;
    
    Line (float arg1 = 0, float arg2 = 0) {
        k = arg1;
        b = arg2;
    };

    bool contain (Point p) {
        float y = this->k * p.x + this->b;
        return abs(p.y - y) < 0.0001;
    };

    void rotate (float angle) {
        this->k = tan(atan(this->k) + angle);
    };

    static Line* readLines(string path, int &number) {
        ifstream file;
        file.open(path);

        if (file.is_open()) {
            file >> number;
            Line* lines = new Line[number];

            for (int i = 0; i < number; i++) {
                file >> lines[i].k;
                file >> lines[i].b;
            }

            file.close();
            return lines;
        }

        number = 0;
        Line *lines = new Line[0];
        return lines;
    };
};

int main () {
    int linesNumber;
    Line *lines = Line::readLines("./lines.txt", linesNumber);
    
    int pointsNumber;
    Point *points = Point::readPoints("./points.txt", pointsNumber);

    int max_counter = 0;
    Line *line;

    for (int i = 0; i < linesNumber; i++) {
        int counter = 0;

        for (int j = 0; j < pointsNumber; j++) {
            if (lines[i].contain(points[j])) {
                counter += 1;
            }
        }

        if (counter > max_counter) {
            max_counter = counter;
            line = &lines[i];
        }
    }

    if (max_counter > 0) {
        cout << line-> k << endl;
        line->rotate(1);
        cout << line-> k << endl;
    }
}