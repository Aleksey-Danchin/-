#ifndef BROWSER_CPP
#define BROWSER_CPP

#include <iostream>
#include <string>

#include "Browser.h"
#include "Book.cpp"

using namespace std;

int Browser::length = 3;
Book* Browser::books = new Book[3]{
    Book("Laboris duis labore aliqua in ex exercitation reprehenderit non minim laborum eu."),
    Book("Ullamco consequat ullamco dolore mollit sint esse ut ea ex ut consequat et exercitation."),
    Book("Nulla exercitation nulla duis aute ea est amet non tempor labore excepteur voluptate.")
};

Book Browser::search(string word) {
    for (int i = 0; i < Browser::length; i++) {
        if (Browser::books[i].text.find(word) != string::npos) {
            return Browser::books[i];
        }
    }

    Book b("");
    return b;
}

#endif