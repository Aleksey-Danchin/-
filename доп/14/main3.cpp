#include <iostream>
#include <fstream>

using namespace std;

// Структура книги
class Book {
    public: string path; // путь до файла
    public: string raw = ""; // исходный сырой текст

    // Конструктор, который сразу считывает файл
    Book (string arg) {
        path = arg;

        ifstream file;
        file.open(path);

        if (file.is_open()) {
            // Считываем файл в сырой текст
            getline(file, raw);
            file.close();
        }
    }

    // Разделает текст книги на предложения
    static void sentences_split (Book &book, string* &sentences, int &length) {
        // Подсчет количества предложений
        length = 0;
        for (int i = 0; i < book.raw.length(); i++) {
            if (book.raw[i] == '.') {
                length += 1;
            }
        }

        // Создали массив для book.counter предложений
        sentences = new string[length];    
        int pos = 0;
        int index = 0;

        for (int i = 0; i < book.raw.length(); i++) {
            if (book.raw[i] == '.') {
                // Забираем подстроку являющееся предложением
                string sentence = book.raw.substr(index, i - index + 1);
                sentences[pos] = sentence;

                pos += 1;
                index = i + 2;
            }
        }
    }
};

// Возвращет среднюю длину предложений
int getAverage (string *sentences, int number) {
    int length = 0;

    for (int i = 0; i < number; i++) {
        length += sentences[i].length();
    }
    
    return length / number;
}

// Создает копию книги с усредненной длиной предложений
string* convert (string* sentences, int number, int size) {
    string* answer = new string[number];

    for (int i = 0; i < number; i++) {
        string sentence = sentences[i];

        if (sentence.length() > size) {
            sentence = sentence.substr(0, size);
        } else {
            while (sentence.length() < size) {
                sentence += '_';
            }
        }

        answer[i] = sentence;
    }

    return answer;
}

int main () {
    Book books[3] = {
        Book("./book1.txt"),
        Book("./book2.txt"),
        Book("./book3.txt")
    };

    string *sentences;
    int number = 0;
    int average = 0;

    // Поиск наибольшего среднего размера предложений
    for (int i = 0; i < 3; i++) {
        string *lines;
        int size;

        Book::sentences_split(books[i], lines, size);
        int middle = getAverage(lines, size);

        if (middle > average) {
            average = middle;
            sentences = lines;
            number = size;
        }
    }

    // Вывод исходных предложений
    for (int i = 0; i < number; i++) {
        cout << sentences[i] << endl;
    }

    cout << endl << "Average length: " << average << endl << endl;

    // Получить усредненные предложения
    string* normalize = convert(sentences, number, average);

    // Вывод усредненных предложений
    for (int i = 0; i < number; i++) {
        cout << normalize[i] << endl;
    }
}