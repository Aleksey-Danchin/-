#include <fstream>
#include <iostream>

using namespace std;

struct Command {
  string type;
  int count = 0;
  string *args;
};

struct NumericFile {
  string path;
  int count = 0;
  int *numbers;
};

void inputNF(NumericFile *nf) {
  ifstream file;
  file.open(nf->path);

  nf->count = 0;

  if (file.is_open()) {
    string line;

    while (getline(file, line)) {
      int number = stoi(line);
      nf->count++;

      int *numbers = new int[nf->count];
      for (int i = 0; i < nf->count - 1; i++) {
        numbers[i] = nf->numbers[i];
      }

      numbers[nf->count - 1] = number;
      nf->numbers = numbers;
    }

    file.close();
  } else {
    cout << "File not open." << endl;
  }
}

void outputNF(NumericFile *nf) {
  ofstream file;
  file.open(nf->path);

  if (file.is_open()) {
    for (int i = 0; i < nf->count; i++) {
      file << nf->numbers[i] << endl;
    }

    file.close();
  }
}

void help() {
  cout << "mff [path] - print max number from file" << endl;
  cout << "write [path] [n1[, n2[, n3 ... ]]]" << endl;
  cout << "help" << endl;
  cout << "exit" << endl;
}

Command parseCommand(string line) {
  Command command;
  string word = "";
  string *args;

  for (int i = 0; i < line.length(); i++) {
    if (line[i] == ' ') {
      if (word.length()) {
        command.count++;

        args = new string[command.count];
        for (int i = 0; i < command.count - 1; i++) {
          args[i] = command.args[i];
        }
        args[command.count - 1] = word;
        command.args = args;
      }

      word = "";
    } else {
      word += line[i];
    }
  }

  if (word.length()) {
    command.count++;

    string *args = new string[command.count];

    for (int i = 0; i < command.count - 1; i++) {
      args[i] = command.args[i];
    }

    args[command.count - 1] = word;
    command.args = args;
  }

  command.type = command.args[0];

  return command;
}

void printMax(NumericFile *nf) {
  if (nf->count > 0) {
    int max = nf->numbers[0];
    for (int i = 1; i < nf->count; i++) {
      if (nf->numbers[i] > max) {
        max = nf->numbers[i];
      }
    }
    cout << max << endl;
  } else {
    cout << "File empty" << endl;
  }
}

int main() {
  NumericFile nf;

  bool flag = true;
  while (flag) {
    string line = "";
    getline(cin, line);

    Command command = parseCommand(line);

    if (command.type == "help") {
      help();

      cout << endl;
    }

    else if (command.type == "exit") {
      cout << "Thanks for using our commandline! Goodbye!" << endl;
      flag = false;

      cout << endl;
    }

    else if (command.type == "mff") {
      NumericFile nf;
      nf.path = command.args[1];
      inputNF(&nf);
      printMax(&nf);

      cout << endl;
    }

    else if (command.type == "write") {
      NumericFile nf;
      nf.path = command.args[1];
      nf.count = command.count - 2;
      nf.numbers = new int[nf.count];
      for (int i = 2; i < command.count; i++) {
        nf.numbers[i - 2] = stoi(command.args[i]);
      }

      outputNF(&nf);
      printMax(&nf);

      cout << endl;
    }
  }
}

char getFirstLetter(string line) { return line[0]; }

char getLastLetter(string line) { return line[line.length() - 1]; }