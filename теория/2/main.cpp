#include <iostream>

using namespace std;

void f1 (int x) {
    cout << "f1:" << endl;
    cout << "x = " << x << endl;

    x += 10;
    cout << "x = " << x << endl;
}

void f2 (int *x) {
    cout << "f2:" << endl;
    cout << "x = " << x << endl;
    cout << "*x = " << *x << endl;

    *x += 10;
}

void f3(int &x) { // по ссылке
    cout << "f3:" << endl;
    cout << "x = " << x << endl;
    cout << "&x = " << &x << endl;
    x = 1;
}

int main() {
    int a = 4;
    cout << "a = " << a << endl;
    f1(a);
    cout << "a = " << a << endl;
    f2(&a);
    cout << "a = " << a << endl;
    f3(a);
    cout << "a = " << a << endl;
    cout << "&a = " << &a << endl;
}