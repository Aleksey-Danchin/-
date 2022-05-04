#include <iostream>

using namespace std;

struct Book {
    int number = 0; // Количество предложений
    char* raw = new char;   // Сырой текст
    char** sentenses = new char*; // Массив предложений
};

void getPath (string &x) { // ссылка
    cout << "Enter path: ";
    cin >> x;
}

void getPath2 (string *x) { // указатель
    cout << "Enter path: ";
    cin >> *x;
}

string getPath3() {
    string x;
    cout << "Enter path: ";
    cin >> x;
    return x;
}

int main () {
    // string path;
    // getPath2(&path);

    // string path = getPath3();

    // cout << path;

    cout << "sizeof(Book) = " << sizeof(Book) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(char*) = " << sizeof(char*) << endl;
    cout << "sizeof(char**) = " << sizeof(char**) << endl;
}