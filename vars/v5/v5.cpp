#include <iostream>
#include "Book.cpp"

using namespace std;

int main () {
    Book::average(0);

    int number = 0;
    cout << "Enter books number: ";
    cin >> number;

    // Заполняем книги
    cin.ignore();
    Book *books = new Book[number];

    // Ищем максимальную среднюю длину книг (по предложениям)
    Book* book;

    for (int i = 0; i < number; i++) {
        int bookAverage = books[i].getAverage();

        if (bookAverage > Book::average()) {
            Book::average(bookAverage);
            book = &books[i];
        }
    }

    // Выводим среднюю длину (максимальную)
    cout << endl << Book::average() << endl << endl;

    // Конвертируем и выводим предложения книги по заданию.
    book->convert();
    book->print();

    delete[] books;
}