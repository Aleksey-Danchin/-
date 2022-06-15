#ifndef BOOK_CPP
#define BOOK_CPP

#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

// Инициализация статический данных
int Book::AVERAGE = 10;

int Book::average () {
    return Book::AVERAGE;
}

int Book::average (int next_average) {
    Book::AVERAGE = next_average;
    return next_average;
}

// Устанавливает новый исходный текст
Book::Book () {
    cout << "Enter book content: ";

    getline(cin, this->text);

    // Подсчет количества предложений
    this->counter = 0;
    for (int i = 0; i < this->text.length(); i++) {
        if (this->text[i] == '.') {
            this->counter += 1;
        }
    }

    // Создали массив для book.counter предложений
    this->sentences = new string[this->counter];
    int pos = 0;
    int index = 0;

    for (int i = 0; i < this->text.length(); i++) {
        if (this->text[i] == '.') {
            // Забираем подстроку являющееся предложением
            string sentence = this->text.substr(index, i - index + 1);
            this->sentences[pos] = sentence;

            pos += 1;
            index = i + 2;
        }
    }
};

// Деструктор
Book::~Book () {
    // исходный сырой текст
    text = "";

    // количество предложений
    counter = 0;

    // массив предложений
    delete[] sentences;

    cout << "Book descructor fired. All cleaned." << endl;
}

// Возвращет среднюю длину предложений
int Book::getAverage () {
    int length = 0;

    for (int i = 0; i < this->counter; i++) {
        length += this->sentences[i].length();
    }
    
    return length / this->counter;
}

// Усредним предложения
void Book::convert () {
    for (int i = 0; i < this->counter; i++) {
        string sentence = this->sentences[i];

        if (sentence.length() > Book::AVERAGE) {
            sentence = sentence.substr(0, Book::AVERAGE);
        } else {
            while (sentence.length() < Book::AVERAGE) {
                sentence += '_';
            }
        }

        this->sentences[i] = sentence;
    }
}

// Печатает книгу по предложениям
void Book::print () {
        for (int i = 0; i < this->counter; i++) {
        string sentence = this->sentences[i];
        cout << sentence << endl;
    }
}

#endif