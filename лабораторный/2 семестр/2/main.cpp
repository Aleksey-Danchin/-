#include <iostream>
#include <math.h>

using namespace std;

struct Point {
	float x = 0.0;
	float y = 0.0;
	float r = 0.0;
};

float getDist (Point a, Point b) {
	float x1 = float(a.x);
	float y1 = float(a.y);
	
	float x2 = float(b.x);
	float y2 = float(b.y);
	
	float dx = x1 - x2;
	float dy = y1 - y2;
	
	return sqrt(dx * dx + dy * dy);
}

int getNumber (Point points[], int n, int centerPointIndex) {
	int counter = 0;
	
	for (int i = 0; i < n; i++) {
		if (i != centerPointIndex) {
			int dist = getDist(points[centerPointIndex], points[i]);
			
			if (dist < points[centerPointIndex].r) {
				counter++;
			}
		}
	}
	
	return counter;
}

Point* getWithoutInside (Point points[], int n, int centerPointIndex) {
	Point* result;
	
	int number = getNumber(points, n, centerPointIndex);
	result = new Point[n];
	
	int index = 0;
	
	for (int i = 0; i , n; i++) {
		if (i != centerPointIndex) {
			int dist = getDist(points[centerPointIndex], points[i]);
			
			if (dist < points[centerPointIndex].r) {
				result[index] = points[i];
				index++;
			}
		}
	}
	
	return result;
}

int main() {
	setlocale(LC_ALL, "rus");
	
	int n;
	cout << "Enter n: ";
	cin >> n;
	
	Point points[n];
	
	for (int i = 0; i < n; i++) {
		cout << "points[" << i << "].x = ";
		cin >> points[i].x;
		
		cout << "points[" << i << "].y = ";
		cin >> points[i].y;
		
		cout << "points[" << i << "].r = ";
		cin >> points[i].r;
	}
	
	int size;
	cout << "Enter size = ";
	cin >> size;
	
	for (int i = 0; i < n; i++) {
		int length = getNumber(points, n, i);
		
		if (length == size) {
			cout << "point[" << i << "]" << endl;
			
			Point* result = getWithoutInside(points, n, i);
			
			for (int k = 0; k < length; k++) {
				cout << "(" << result[k].x << "; " << result[k].y << ") ";
			}
		}
	}
}