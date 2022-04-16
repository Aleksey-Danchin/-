#include <iostream>
#include <fstream>

using namespace std;

int getLength (char* line) {
    int n = 0;

    while (*(line + n) != '\0') {
        n++;
    }

    return n;
}

char* getBook () {
    char* path = new char;
    cout << "Enter path to book: ";
    cin >> path;

    ifstream file;
    file.open(path);

    char* book;

    if (file.is_open()) {
        book = new char[file.tellg()];
        int counter = 0;

        while (file) {
            char* word = new char;
            file >> word;

            int length = getLength(word);

            for (int i = 0; i < length; i++) {
                book[counter + i] = word[i];
            }

            counter += length;
            book[counter] = ' ';
            counter += 1;
        }

        book[counter - 1] = '\0';

        file.close();
    }

    return book;
}

int main () {
    char* book = getBook();
    cout << book << endl;
    cout << getLength(book) << endl;
}