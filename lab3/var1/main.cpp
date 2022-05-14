#include <iostream>

using namespace std;

class Book {
    public:
        string text;
    
    Book (string arg) {
        text = arg;
    }
};

class Browser {
    private:
        static int length = 3;
        static Book books[3] = {
            Book("Laboris duis labore aliqua in ex exercitation reprehenderit non minim laborum eu."),
            Book("Ullamco consequat ullamco dolore mollit sint esse ut ea ex ut consequat et exercitation."),
            Book("Nulla exercitation nulla duis aute ea est amet non tempor labore excepteur voluptate."),
        };
    
    public:
        Book search(string word) {
            for (int i = 0; i < Browser::length; i++) {
                if (Book::books[i].text.contains(word)) {
                    return Book::books[i];
                }
            }
        }
};

int main () {}