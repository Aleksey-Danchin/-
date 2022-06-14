#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book {
    // Статическое значение усреднения предложений
    private: static int AVERAGE;

    // Получить константу AVERAGE
    public: static int average ();

    // Заменить и получить AVERAGE
    public: static int average (int next_average);

    // исходный сырой текст
    public: string text = "";

    // количество предложений
    public: int counter = 0;

    // массив предложений
    public: string* sentences;
    
    // Устанавливает новый исходный текст
    public: Book (string text);

    // Возвращет среднюю длину предложений
    public: int getAverage ();

        // Усредним предложения
    public: void convert ();

    // Печатает книгу по предложениям
    public: void print ();
};

#endif