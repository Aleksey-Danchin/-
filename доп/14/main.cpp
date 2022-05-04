#include <iostream>
#include <fstream>

using namespace std;

// Структура книги
struct Book {
    string path; // путь до файла
    string raw = ""; // исходный сырой текст
    string* sentences; // массив предложений
    int counter = 0; // количество предложений
};

// Считываем файл
Book read (string path) {
    Book book;
    book.path = path;

    ifstream file;
    file.open(path);

    if (file.is_open()) {
        // Считываем файл в сырой текст
        getline(file, book.raw);
        file.close();
    }

    // Подсчет количества предложений
    book.counter = 0;
    for (int i = 0; i < book.raw.length(); i++) {
        if (book.raw[i] == '.') {
            book.counter += 1;
        }
    }

    // Создали массив для book.counter предложений
    book.sentences = new string[book.counter];
    int pos = 0;
    int index = 0;

    for (int i = 0; i < book.raw.length(); i++) {
        if (book.raw[i] == '.') {
            // Забираем подстроку являющееся предложением
            string sentence = book.raw.substr(index, i - index + 1);
            book.sentences[pos] = sentence;

            pos += 1;
            index = i + 2;
        }
    }

    return book;
}

// Возвращет среднюю длину предложений
int getAverage (Book book) {
    int length = 0;

    for (int i = 0; i < book.counter; i++) {
        length += book.sentences[i].length();
    }
    
    return length / book.counter;
}

// Создает копию книги с усредненной длиной предложений
Book convert (Book original, int size) {
    Book book;
    book.counter = original.counter;
    book.sentences = new string[book.counter];

    for (int i = 0; i < book.counter; i++) {
        string sentence = original.sentences[i];

        if (sentence.length() > size) {
            sentence = sentence.substr(0, size);
        } else {
            while (sentence.length() < size) {
                sentence += '_';
            }
        }

        book.sentences[i] = sentence;
    }

    return book;
}

int main () {
    Book b1 = read("./book1.txt");
    Book b2 = read("./book2.txt");
    Book b3 = read("./book3.txt");

    Book b = b1;
    int average = getAverage(b1);

    if (getAverage(b2) > average) {
        b = b2;
        average = getAverage(b2);
    }

    if (getAverage(b3) > average) {
        b = b3;
        average = getAverage(b3);
    }


    // cout << b.raw << endl;
    // cout << b.counter << endl;

    for (int i = 0; i < b.counter; i++) {
        cout << b.sentences[i] << endl;
    }

    cout << endl << getAverage(b) << endl << endl;

    Book c = convert(b, getAverage(b));
    for (int i = 0; i < c.counter; i++) {
        cout << c.sentences[i] << endl;
    }
}