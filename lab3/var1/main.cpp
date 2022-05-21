#include <iostream>
#include "Book.cpp"
#include "Browser.cpp"

using namespace std;

int main () {
    Book book = Browser::search("in");
    cout << book.text << endl;
}