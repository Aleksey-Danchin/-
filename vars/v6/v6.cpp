#include <iostream>
#include "Book.cpp"

using namespace std;

int main () {
    Book a = Book("Hello. How are you.");
    Book b = Book("What is you name. I am Max.");
    Book c = Book("Ok. You win.");

    Book b1 = a + b;
    Book b2 = a * c;

    cout << b1.text << endl;
    cout << b2.text << endl;

    Book x = a + b * c;
    Book y = (a + b) * c;

    cout << x.text << endl;
    cout << y.text << endl;
}