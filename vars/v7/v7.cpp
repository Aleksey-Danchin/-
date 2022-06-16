#include <iostream>
using namespace std;

class Content {
    // исходный сырой текст
    public: string text = "";
};

class Book: public Content {
    // Статическое значение усреднения предложений
    private: static int AVERAGE;

    // Получить константу AVERAGE
    public: static int average ();

    // Заменить и получить AVERAGE
    public: static int average (int next_average);

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
};

class TitledBook: public Book {
    string title = "";
};

// -------------------------------------------------------------------------------

// Инициализация статический данных
int Book::AVERAGE = 10;

int Book::average () {
    return Book::AVERAGE;
}

int Book::average (int next_average) {
    Book:AVERAGE = next_average;
    return next_average;
}

// Устанавливает новый исходный текст
Book::Book (string text = "") {
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
};

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

Book operator + (Book b1, Book b2) {
    return Book(b1.text + " " + b2.text);
}

Book operator * (Book b1, Book b2) {
    string text = "";

    int counter = b1.counter;
    if (b2.counter < counter) {
        counter = b2.counter;
    }

    for (int i = 0; i < counter; i++) {
        text += b1.sentences[i] + " ";
        text += b2.sentences[i] + " ";
    }

    for (int i = counter; i < b1.counter; i++) {
        text += b1.sentences[i] + " ";
    }

    for (int i = counter; i < b2.counter; i++) {
        text += b2.sentences[i] + " ";
    }

    return Book(text);
}

ostream& operator << (ostream &out, Book &b) {
    for (int i = 0; i < b.counter; i++) {
        string sentence = b.sentences[i];
        out << sentence << endl;
    }

    return out;
}

istream& operator >> (istream& in, Book &b) {
    string text;
    getline(in, text);

    Book book(text);

    b.text = book.text;
    b.counter = book.counter;
    b.sentences = book.sentences;

    return in;
}

// ------------------------------------------------------------------------------

int main () {
    // "Hello. How are you.";
    Book a;
    cout << "Enter a book: ";
    cin >> a;

    // "What is you name. I am Max.";
    Book b;
    cout << "Enter b book: ";
    cin >> b;

    // "Ok. You win.";
    Book c;
    cout << "Enter c book: ";
    cin >> c;

    Book b1 = a + b;
    Book b2 = a * c;

    cout << b1 << endl;
    cout << b2 << endl;

    Book x = a + b * c;
    Book y = (a + b) * c;

    cout << x << endl;
    cout << y << endl;
}