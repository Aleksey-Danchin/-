#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Object {
    int id;                     // порядковый номер
    string classType;           // имя класса
    vector<int> properties;     // вектор признаков
};

struct ClassType {
    string name;                // имя класса
    vector<Object> objects;     // вектор объектов
};

ClassType getFromFile (string name, string path) {
    ClassType ct;
    ct.name = name;

    ifstream file;
    file.open(path);

    if (file.is_open()) {
        string line;
        vector<int> properties;
        Object object;
        int idCounter = 1;

        while (getline(file, line)) {
            int pos = 0;

            // pos - индекс вхождения табуляции
            while ((pos = line.find('\t')) != string::npos) { // string::npos == -1
                string value = line.substr(0, pos); // копируем подстроку с числом

                if (value.length() > 0) {
                    properties.push_back(stoi(value)); // делаем подстроку числом
                }

                line.erase(0, pos + 1); // удаляем начало строки с уже обработанным числом
            }

            // оставшиуюся строчку превращаем в число
            if (line.length() > 0) {
                properties.push_back(stoi(line));
            }

            object.classType = ct.name;
            object.id = idCounter++;
            object.properties = properties;
            ct.objects.push_back(object);
        }


        file.close();
    }

    return ct;
}

ClassType merge (string name, ClassType ct1, ClassType ct2) {
    ClassType ct;
    ct.name = name;

    for (int i = 0; i < ct1.objects.size(); i++) {
        ct.objects.push_back(ct1.objects[0]);
    }

    for (int i = 0; i < ct2.objects.size(); i++) {
        ct.objects.push_back(ct2.objects[0]);
    }

    return ct;
}

int main () {
    ClassType a = getFromFile("A", "./a.txt");
    ClassType b = getFromFile("B", "./b.txt");
    ClassType c = getFromFile("C", "./c.txt");
    
    cout << a.name << endl;
    cout << a.objects.size() << endl;
    cout << a.objects[0].properties.size() << endl;

    cout << endl;
}