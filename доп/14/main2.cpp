#include <iostream>
#include <fstream>

using namespace std;

// Структура книги
class Book {
    public: string path; // путь до файла
    public: string raw = ""; // исходный сырой текст
    public: string* sentences; // массив предложений
    public: int counter = 0; // количество предложений

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
    Book b1; // объект класса Book (переменная типа Book)
    b1.path = "./book1.txt";
    b1.read();

    Book b2;
    b2.path = "./book2.txt";
    b2.read();

    Book b3;
    b3.path = "./book3.txt";
    b3.read();

    Book b = b1;
    int average = b1.getAverage();

    if (b2.getAverage() > average) {
        b = b2;
        average = b2.getAverage();
    }

    if (b3.getAverage() > average) {
        b = b3;
        average = b3.getAverage();
    }

    for (int i = 0; i < b.counter; i++) {
        cout << b.sentences[i] << endl;
    }

    cout << endl << b.getAverage() << endl << endl;

    b.convert(b.getAverage());
    for (int i = 0; i < b.counter; i++) {
        cout << b.sentences[i] << endl;
    }
}