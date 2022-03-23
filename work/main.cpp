#include <iostream>

#define P1 0
#define P2 1
#define P3 2
#define P4 3
#define P5 4
#define P6 5
#define P7 6

using namespace std;

int main () {
    int properties[7];

    cout << "Enter properties: ";
    
    for (int i = 0; i < 7; i++) {
        cin >> properties[i];
    }
    
    float f = -19.0 * (float)properties[P3] - 6.0 * (float)properties[P6] + 496.0;
    float y = 26.0 - 0.3 * (float)properties[P6];

    if (y < f) {
        cout << "class A" << endl;
    } else {
        f = -37.0 * (float)properties[P6] - 73.0 * (float)properties[P7] + 4947.0;
        y = 260.4 - 2.0 * (float)properties[P7];

        if (y < f) {
            cout << "class B" << endl;
        } else {
            cout << "class C" << endl;
        }
    }
}