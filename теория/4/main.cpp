#include <iostream>

using namespace std;

int main () {
    char str[3] = {'h', 'i', 'l'};
    // char str[] = "hil"; // ""
    // char str[] = {'h', 'i', 'l'};
    // char str[] {'h', 'i', 'l'};

    cout << "str = " << str << endl;
    cout << "&str = " << &str << endl;
    cout << "*(&str) = " << *(&str) << endl;
    cout << "sizeof(str) = " << sizeof(str) << endl;

    cout << endl;

    char *x = new char[]{};
    cout << "x = " << x << endl;
    cout << "sizeof(x) = " << sizeof(x) << endl;
}