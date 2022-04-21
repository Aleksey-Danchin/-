#include <iostream>
#include <fstream>

using namespace std;

// Структуру книги
struct Book {
    char* raw = new char;   // Сырой текст
    int number = 0; // Количество предложений
    char** sentenses = new char*; // Массив предложений
};

//  Принимает массив символов и возвращает длинну строки
int getLength (char* line) {
    int n = 0;

    while (*(line + n) != '\0') {
        n++;
    }

    return n;
}

// Читает файл и возвращает книгу
Book getBook (string path) {
    ifstream file;
    file.open(path);

    Book book;
    int counter = 0; // Длина сырого текста

    if (file.is_open()) {
        // file.tellg() узнаем размер файла заранее
        book.raw = new char[file.tellg()];

        while (file) {
            // Считываем файл по слову
            char* word = new char;
            file >> word;

            // Длинна слова
            int length = getLength(word);

            // Записывает словам в сырой текст книги
            for (int i = 0; i < length; i++) {
                book.raw[counter + i] = word[i];
            }

            counter += length;
            book.raw[counter] = ' ';
            counter += 1;
        }

        book.raw[counter - 1] = '\0'; // В конец сырого текста добавляем флаг конца текста

        file.close();
    }
    
    // Разбиваем текст на предложения
    book.sentenses = new char*;

    if (counter > 0) {
        int size = 0; // Длинна предложения
        char* sentense = new char[counter]; // Предложение

        for (int i = 0; i < counter; i++) { // Перебираем символы в сырой строке
            if (book.raw[i] == '.') { // Если точка, то значит конец предложения
                sentense[size] = '.';
                sentense[size + 1] = '\0';
                book.sentenses[book.number] = sentense;
                book.number += 1;

                size = 0;
                sentense = new char[counter];
            } else if (size > 0 || (book.raw[i] != ' ' && book.raw[i] != '\0')) { // а иначе новый символ для предложения
                sentense[size] = book.raw[i];
                size += 1;
            }
        }

        // Проверка на последнее предложение. Если оно есть, то добавляем его в список предложений.
        if (size > 0 && sentense[size] != '\n' && sentense[size] != '\0') {
            sentense[size + 1] = '\0';
            book.sentenses[book.number] = sentense;
            book.number += 1;
        }
    }

    return book;
}

// Принимает книгу и возвращает число = средняя длина предложений
int getEverage (Book book) {
    int sum = 0;

    for (int i = 0; i < book.number; i++) {
        sum += getLength(book.sentenses[i]);
    }

    return int(float(sum) / float(book.number));
}

// Принимает книгу и длинну для подгона
Book convertToLength (Book book, int length) {
    // Создаем копию книги
    Book result;
    result.raw = book.raw;
    result.number = book.number;
    result.sentenses = new char*;

    for (int i = 0; i < book.number; i++) { // Перебираем предложения оригинальные
        char* sentense = book.sentenses[i];
        int size = getLength(sentense);

        // Подгоняем копию строки под нужный размер (длинну)
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
        result.sentenses[i] = copy; // Запоминаем копию строки с нужной длинной в новой книге
    }

    return result;
}

int main () {
    // Читаем 3 книги
    Book books[3] = {getBook("book1.txt"), getBook("book2.txt"), getBook("book3.txt")};

    // Находим максимальную среднюю длину предложений в книгах
    int maxEverage = 0;
    Book book;

    for (int i = 0; i < 3; i++) {
        int everage = getEverage(books[i]);

        if (maxEverage < everage) {
            maxEverage = everage;
            book = books[i];
        }
    }
    
    // Получаем выбранную книгу с предложениями нужной длинны
    Book normal = convertToLength(book, maxEverage);

    // Выводим предложения
    for (int i = 0; i < normal.number; i++) {
        cout << normal.sentenses[i] << endl;
    }
}