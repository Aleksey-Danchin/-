#include <fstream>
#include <iostream>

using namespace std;

// Структура массива чисел
struct numbers {
  int counter = 1;  // количество
  int *items = {0}; // сами числа
};

// Возвращает максимальное число из структуры numbers
int getMaxNumber(numbers n) {
  int maxItem = n.items[0];

  for (int i = 1; i < n.counter; i++) {
    if (n.items[i] > maxItem) {
      maxItem = n.items[i];
    }
  }

  return maxItem;
}

// Ввода количества и самих чисел и возвращает структуру numbers
numbers enterNumbers() {
  numbers n;

  cout << "Сколько будет чисел: ";
  cin >> n.counter;
  n.items = new int[n.counter];

  for (int i = 0; i < n.counter; i++) {
    cout << i + 1 << " число: ";
    cin >> n.items[i];
  }

  return n;
}

// Стение файла и возвращение структуры numbers
numbers readNumbers() {
  numbers n;

  char *path = new char;
  cout << "Адрес файла для чтения: ";
  cin >> path;

  ifstream file;
  file.open(path);

  if (file.is_open()) {
    file >> n.counter;
    n.items = new int[n.counter];

    for (int i = 0; i < n.counter; i++) {
      file >> n.items[i];
    }

    file.close();
  }

  return n;
}

// Записывает структуру numbers в файл
void writeNumbers(numbers n) {
  char *path = new char;
  cout << "Адрес файла для записи: ";
  cin >> path;

  ofstream file;
  file.open(path);

  if (file.is_open()) {
    file << n.counter << endl;

    for (int i = 0; i < n.counter; i++) {
      file << n.items[i] << endl;
    }

    file.close();
  }
}

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
      numbers n = readNumbers();
      int maxItem = getMaxNumber(n);
      cout << "Максимальное число = " << maxItem << endl;
    }

    else if (command == 'e') {
      numbers n = enterNumbers();
      int maxItem = getMaxNumber(n);
      cout << "Максимальное число = " << maxItem << endl;
    }

    else if (command == 'w') {
      numbers n = enterNumbers();
      writeNumbers(n);
      int maxItem = getMaxNumber(n);
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