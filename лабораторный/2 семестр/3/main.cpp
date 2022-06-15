#include <iostream>
#include <math.h>

using namespace std;

const double eps = 0.00001;

struct Point {
	float x;
	float y;
};

float getDistance (Point a, Point b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	
	return sqrt(dx * dx + dy * dy);
}

string getFigureType (Point points[4]) {
	float distances[6] = {
		getDistance(points[0], points[1]),
		getDistance(points[0], points[2]),
		getDistance(points[0], points[3]),
		getDistance(points[1], points[2]),
		getDistance(points[1], points[3]),
		getDistance(points[2], points[3])
	};
	
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (distances[i] > distances[j]) {
				float buff = distances[i];
				distances[i] = distances[j];
				distances[j] = buff;
			}
		}
	}
	
	if (
	abs(distances[0] - distances[1]) < eps
	&& abs(distances[0] - distances[2]) < eps
	&& abs(distances[0] - distances[3]) < eps
	&& abs(distances[4] - distances[5]) < eps) 
	{
		return "Square";
	}
	
	if (
	abs(distances[0] - distances[1]) < eps
	&& abs(distances[0] - distances[2]) < eps
	&& abs(distances[0] - distances[3]) < eps
	&& abs(distances[4] - distances[5]) > eps
	) {
		return "Rhomb";
	}
	
	if (
	abs(distances[1] - distances[2]) < eps
	&& abs(distances[1] - distances[3]) < eps
	&& abs(distances[1] - distances[4]) < eps
	&& abs(distances[0] - distances[5]) > eps
	) {
		return "Rhomb";
	}
	
	if (
	abs(distances[0] - distances[1]) < eps
	&& abs(distances[2] - distances[3]) < eps
	&& abs(distances[4] - distances[5]) < eps
	) {
		return "Rectangle";
	}
	
	if (
	abs(distances[0] - distances[1]) < eps
	&& abs(distances[2] - distances[3]) < eps
	&& abs(distances[4] - distances[5]) > eps
	) {
		return "Parallelogram";
	}
	
	if (
	abs(distances[1] - distances[2]) < eps
	&& abs(distances[3] - distances[4]) < eps
	&& abs(distances[0] - distances[5]) > eps
	) {
		return "Parallelogram";
	}
	
	float ks[6] = {
		atan2(points[0].y - points[1].y, points[0].x - points[1].x),
		atan2(points[0].y - points[2].y, points[0].x - points[2].x),
		atan2(points[0].y - points[3].y, points[0].x - points[3].x),
		atan2(points[1].y - points[2].y, points[1].x - points[2].x),
		atan2(points[1].y - points[3].y, points[1].x - points[3].x),
		atan2(points[2].y - points[3].y, points[2].x - points[3].x),
	};
	
	bool flag = false;
	
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (abs(ks[i] - ks[j]) < eps) {
				flag = true;
				break;
			}
		}
		
		if (flag) {
			return "Trapeze";
		}
	}
	
	return "General form";
}

float getSquare (Point points[4]) {
	float distances[6] = {
		getDistance(points[0], points[1]),
		getDistance(points[0], points[2]),
		getDistance(points[0], points[3]),
		getDistance(points[1], points[2]),
		getDistance(points[1], points[3]),
		getDistance(points[2], points[3])
	};
	
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (distances[i] > distances[j]) {
				float buff = distances[i];
				distances[i] = distances[j];
				distances[j] = buff;
			}
		}
	}
	
	return distances[0] * distances[0];
}

int main() {
	setlocale(LC_ALL, "rus");
	
	Point points[4];
	points[0] = {0.0, 0.0};
	points[1] = {0.0, 5.0};
	points[2] = {5.0, 0.0};
	points[3] = {5.0, 5.0};
	
	string figureType = getFigureType(points);
	
	cout << figureType;
	
	if (figureType == "Square") {
		float square = getSquare(points);
		cout << "Square = " << square;
	}
}