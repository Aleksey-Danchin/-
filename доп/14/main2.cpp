#include <iostream>
#include <fstream>

using namespace std;

// Структура книги
class Book {
    public: string path; // путь до файла
    public: string raw = ""; // исходный сырой текст
    public: string* sentences; // массив предложений
    public: int counter = 0; // количество предложений

    Book (string arg) {
        path = arg;
        read();
    }

    // Считываем файл
    void read () {
        ifstream file;
        file.open(this->path);

        if (file.is_open()) {
            // Считываем файл в сырой текст
            getline(file, this->raw);
            file.close();
        }

        // Подсчет количества предложений
        this->counter = 0;
        for (int i = 0; i < this->raw.length(); i++) {
            if (this->raw[i] == '.') {
                this->counter += 1;
            }
        }

        // Создали массив для book.counter предложений
        this->sentences = new string[this->counter];
        int pos = 0;
        int index = 0;

        for (int i = 0; i < this->raw.length(); i++) {
            if (this->raw[i] == '.') {
                // Забираем подстроку являющееся предложением
                string sentence = this->raw.substr(index, i - index + 1);
                this->sentences[pos] = sentence;

                pos += 1;
                index = i + 2;
            }
        }
    }

    // Возвращет среднюю длину предложений
    int getAverage () {
        int length = 0;

        for (int i = 0; i < this->counter; i++) {
            length += this->sentences[i].length();
        }
        
        return length / this->counter;
    }

    // Создает копию книги с усредненной длиной предложений
    void convert (int size) {
        for (int i = 0; i < this->counter; i++) {
            string sentence = this->sentences[i];

            if (sentence.length() > size) {
                sentence = sentence.substr(0, size);
            } else {
                while (sentence.length() < size) {
                    sentence += '_';
                }
            }

            this->sentences[i] = sentence;
        }
    }
};

int main () {
    Book books[3] = {
        Book("./book1.txt"),
        Book("./book2.txt"),
        Book("./book3.txt"),
    };

    int average = 0;
    Book* book;

    for (int i = 0; i < 3; i++) {
        int bookAverage = books[i].getAverage();
        if (bookAverage > average) {
            average = bookAverage;
            book = &books[i];
        }
    }

    cout << endl <<average << endl << endl;

    book->convert(average);
    for (int i = 0; i < book->counter; i++) {
        cout << book->sentences[i] << endl;
    }
}