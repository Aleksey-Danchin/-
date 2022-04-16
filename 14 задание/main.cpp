#include <iostream>
#include <fstream>

using namespace std;

struct Book {
    char* raw = new char;
    int number = 0;
    char** sentenses = new char*;
};

int getLength (char* line) {
    int n = 0;

    while (*(line + n) != '\0') {
        n++;
    }

    return n;
}

Book getBook () {
    char* path = new char;
    cout << "Enter path to book: ";
    cin >> path;

    ifstream file;
    file.open(path);

    Book book;
    int counter = 0;

    if (file.is_open()) {
        book.raw = new char[file.tellg()];

        while (file) {
            char* word = new char;
            file >> word;

            int length = getLength(word);

            for (int i = 0; i < length; i++) {
                book.raw[counter + i] = word[i];
            }

            counter += length;
            book.raw[counter] = ' ';
            counter += 1;
        }

        book.raw[counter - 1] = '\0';

        file.close();
    }

    book.sentenses = new char*;

    if (counter > 0) {
        int size = 0;
        char* sentense = new char[counter];

        for (int i = 0; i < counter; i++) {
            if (book.raw[i] == '.') {
                sentense[size] = '.';
                sentense[size + 1] = '\0';
                cout << sentense << endl;
                book.sentenses[book.number] = sentense;
                book.number += 1;

                size = 0;
                sentense = new char[counter];
            } else if (size > 0 || book.raw[i] != ' ') {
                sentense[size] = book.raw[i];
                size += 1;
            }
        }

        if (size > 0 && sentense[size] != '\n' && sentense[size] != '\0') {
            sentense[size + 1] = '\0';
            book.sentenses[book.number] = sentense;
            book.number += 1;
        }
    }

    return book;
}

int getEverage (Book book) {
    int sum = 0;

    for (int i = 0; i < book.number; i++) {
        sum += getLength(book.sentenses[i]);
    }

    return int(float(sum) / float(book.number));
}

Book convertToLength (Book book, int length) {
    Book result;

    result.raw = book.raw;
    result.number = book.number;
    result.sentenses = new char*;

    for (int i = 0; i < book.number; i++) {
        char* sentense = book.sentenses[i];
        int size = getLength(sentense);

        char* copy = new char[length + 1];

        if (size >= length) {
            for (int i = 0; i < length; i++) {
                copy[i] = sentense[i];
            }
        } else {
            for (int i = 0; i < size; i++) {
                copy[i] = sentense[i];
            }

            for (int i = 0; i < length - size; i++) {
                copy[size + i] = '!';
            }
        }

        copy[length] = '\0';
        cout << copy << endl;
    }

    return result;
}

int main () {
    Book book = getBook();
    cout << book.raw << endl;
    cout << getLength(book.raw) << endl;
    cout << book.number << endl;
    cout << book.sentenses[0] << endl;

    int everage = getEverage(book);
    Book normal = convertToLength(book, everage);
    cout << normal.sentenses[0] << endl;
}