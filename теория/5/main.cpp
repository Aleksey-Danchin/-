#include <iostream>

using namespace std;

struct Person {
    string name;
    string surname;
};

void printPerson1 (Person p) {
    cout << "Name: " << p.name << endl;
    cout << "Surname: " << p.surname << endl;
}

void printPerson2 (Person *p) {
    cout << "Name: " << (*p).name << endl;
    cout << "Surname: " << (*p).surname << endl;

    // cout << "Name: " << p->name << endl;
    // cout << "Surname: " << p->surname << endl;
}

class User {
    private: int age;
    public: string name;
    public: string surname;

    void print () {
        cout << "Name: " << this->name << endl;
        cout << "Surname: " << this->surname << endl;
    }

    int getAge () {
        return this->age;
    }

    int setAge(int age) {
        return this->age = age;
    }
};

int main () {
    Person person;
    person.name = "Алексей";
    person.surname = "Данчин";

    User u;
    u.name = "Алексей";
    u.surname = "Данчин";
    u.setAge(29);
    u.getAge();

    printPerson1(person);
    printPerson2(&person);

    u.print();
}