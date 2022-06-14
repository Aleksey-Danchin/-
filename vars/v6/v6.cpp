#include <iostream>
#include "Book.cpp"

using namespace std;

int main () {
    // "Hello. How are you.";
    Book a;
    cout << "Enter a book: ";
    cin >> a;

    // "What is you name. I am Max.";
    Book b;
    cout << "Enter b book: ";
    cin >> b;

    // "Ok. You win.";
    Book c;
    cout << "Enter c book: ";
    cin >> c;

    Book b1 = a + b;
    Book b2 = a * c;

    cout << b1 << endl;
    cout << b2 << endl;

    Book x = a + b * c;
    Book y = (a + b) * c;

    cout << x << endl;
    cout << y << endl;
}