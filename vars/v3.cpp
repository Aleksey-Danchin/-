#include <iostream>

using namespace std;

class Book {
    private: string text = ""; // исходный сырой текст
    private: int counter = 0; // количество предложений
    private: string* sentences; // массив предложений

    public: Book () {};

    public: Book (string text) {
        this->text = text;

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
    }

        // Возвращет среднюю длину предложений
    public: int getAverage () {
        int length = 0;

        for (int i = 0; i < this->counter; i++) {
            length += this->sentences[i].length();
        }
        
        return length / this->counter;
    }

        // Усредним предложения
    public: void convert (int size) {
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

    // Печатает книгу по предложениям
    public: void print () {
            for (int i = 0; i < this->counter; i++) {
            string sentence = this->sentences[i];
            cout << sentence << endl;
        }
    }
};

int main () {
    int number = 0;
    cout << "Enter books number: ";
    cin >> number;

    Book *books = new Book[number];

    // Заполняем книги
    cin.ignore();
    for (int i = 0; i < number; i++) {
        string text = "";
        cout << "Enter " << i + 1 << " book: ";

        getline(cin, text);
        books[i] = Book(text);
    }

    // Ищем максимальную среднюю длину книг (по предложениям)
    int average = 0;
    Book* book;

    for (int i = 0; i < number; i++) {
        int bookAverage = books[i].getAverage();

        if (bookAverage > average) {
            average = bookAverage;
            book = &books[i];
        }
    }

    // Выводим среднюю длину (максимальную)
    cout << endl << average << endl << endl;

    // Конвертируем и выводим предложения книги по заданию.
    book->convert(average);
    book->print();
}