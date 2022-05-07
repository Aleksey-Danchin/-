#include <fstream>
#include <iostream>

using namespace std;

class Numbers {
    public: string path = "";
    public: int counter = 1;  // количество
    public: int *items = {0}; // сами числа

    // Возвращает максимальное число из структуры numbers
    int getMaxNumber() {
      int maxItem = this->items[0];

        for (int i = 1; i < this->counter; i++) {
            if (this->items[i] > maxItem) {
                maxItem = this->items[i];
            }
        }

        return maxItem;
    }

    // Ввода количества и самих чисел и возвращает структуру numbers
    void enter() {
        cout << "Сколько будет чисел: ";
        cin >> this->counter;
        this->items = new int[this->counter];

        for (int i = 0; i < this->counter; i++) {
            cout << i + 1 << " число: ";
            cin >> this->items[i];
        }
    }

    // Стение файла и возвращение структуры numbers
    void read() {
        cout << "Адрес файла для чтения: ";
        cin >> this->path;

        ifstream file;
        file.open(this->path);

        if (file.is_open()) {
            file >> this->counter;
            this->items = new int[this->counter];

            for (int i = 0; i < this->counter; i++) {
                file >> this->items[i];
            }

            file.close();
        }
    }

    // Записывает структуру numbers в файл
    void write() {
        ofstream file;

        if (this->path == "") {
            cout << "Enter path: ";
            cin >> this->path;
        }

        file.open(this->path);

        if (file.is_open()) {
            file << this->counter << endl;

            for (int i = 0; i < this->counter; i++) {
                file << this->items[i] << endl;
            }

            file.close();
        }
    }
};

int main() {
  bool flag = true;
  char command;

  while (flag) {
    cout << endl;
    cout << "r - Прочитать файл с числами и вывести наибольшее из чисел."
         << endl;
    cout << "e - Ввести числа и вывести наибольшее из чисел." << endl;
    cout
        << "w - Ввести числа, записать их в файл и вывести наибольшее из чисел."
        << endl;
    cout << "q - Выход из программы." << endl;
    cout << "> ";

    cin >> command;

    if (command == 'r') {
      Numbers n;
      n.read();

      int maxItem = n.getMaxNumber();
      cout << "Максимальное число = " << maxItem << endl;
    }

    else if (command == 'e') {
      Numbers n;
      n.enter();

      int maxItem = n.getMaxNumber();
      cout << "Максимальное число = " << maxItem << endl;
    }

    else if (command == 'w') {
      Numbers n;
      n.enter();
      n.write();

      int maxItem = n.getMaxNumber();
      cout << "Максимальное число = " << maxItem << endl;
    }

    else if (command == 'q') {
      cout << "Всего хорошего!" << endl;
      flag = false;
    }

    else {
      cout << "Команда не распознана." << endl;
    }
  }
}