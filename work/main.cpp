#include <iostream>

using namespace std;

#define P1 0
#define P2 1
#define P3 2
#define P4 3
#define P5 4
#define P6 5
#define P7 6

int work() {
  int properties[7];
  cout << "\tВвод признаков: " << endl;
  cout << "\t----------------------------------------" << endl;
  cout << "\t> ";

  for (int i = 0; i < 7; i++) {
    cin >> properties[i];
  }

  if (!cin) {
    cout << "\tОшибка! Необходимо ввести число! ";
    return 4;
  }

  float f = -19.0 * (float)properties[P3] - 6.0 * (float)properties[P6] + 496.0;
  float y = 26.0 - 0.3 * (float)properties[P6];

  if (y < f) {
    cout << "\tКласс A" << endl;
  }

  else {
    f = 4.4 * (float)properties[P3] - 36.6 * (float)properties[P6] + 863.7;
    y = 8.3 - 196.3 * (float)properties[P6];

    if (y < f) {
      cout << "\tКласс B" << endl;
    }

    else {
      cout << "\tКласс C" << endl;
    }
  }

  cout << "\t----------------------------------------" << endl;

  return 0;
}

int main() {
  setlocale(LC_ALL, "rus");
  string command;

  cout << "\tВведите help для вызова меню информации " << endl;
  while (true) {
    cout << "\t> ";
    cin >> command;

    if (command == "help") {
      cout << endl << "\t> Меню информации:" << endl;
      cout << "\t----------------------------------------" << endl;
      cout << "\t> Команда work - Запуск программы." << endl;
      cout << endl << "\t> Команда help - Вызов меню информации." << endl;
      cout << endl << "\t> Команда quit - Выход." << endl;
      cout << "\t----------------------------------------" << endl;
      cout << endl;
    }

    else if (command == "work") {
      if (work() == 4) {
        return 4;
      }
    }

    else if (command == "quit") {
      break;
    }

    else {
      cout << "\tКоманда не опознана!" << endl;
    }
  }

  cout << "\tДо встречи!" << endl;
}