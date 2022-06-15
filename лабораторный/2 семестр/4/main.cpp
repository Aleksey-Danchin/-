#include <iostream>
#include <fstream>

using namespace std;

struct Record {
    string surname;
    int grade;
};

struct Journal {
    int counter;
    Record* records;
};

struct Rogue {
    int counter;
    string* surnames;
};

Journal read (string path) {
    ifstream file;
    file.open(path);

    Journal journal;
    journal.counter = 0;
    journal.records = new Record;

    if (file.is_open()) {
        file >> journal.counter;
        journal.records = new Record[journal.counter];
        
        for (int i = 0; i < journal.counter; i++) {
            Record record;
            file >> record.surname;
            file >> record.grade;

            journal.records[i] = record;
        }

        file.close();
    }

    return journal;
}

Rogue getRogue (Journal journal) {
    Rogue rogue;
    rogue.counter = 0;

    for (int i = 0; i < journal.counter; i++) {
        if (journal.records[i].grade < 3) {
            rogue.counter += 1;
        }
    }

    rogue.surnames = new string[rogue.counter];
    
    int counter = 0;
    for (int i = 0; i < journal.counter; i++) {
        if (journal.records[i].grade < 3) {
            rogue.surnames[counter] = journal.records[i].surname;
            counter += 1;
        }
    }

    return rogue;
}

Journal exclude (Journal journal, Rogue rogue) {
    Journal nextJournal;
    nextJournal.counter = journal.counter - rogue.counter;
    nextJournal.records = new Record[nextJournal.counter];

    int counter = 0;
    for (int i = 0; i < journal.counter; i++) {
        bool flag = true;

        for (int j = 0; j < rogue.counter; j++) {
            if (journal.records[i].surname == rogue.surnames[j]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            nextJournal.records[counter] = journal.records[i];
            counter += 1;
        }
    }
    
    return nextJournal;
}

void write (Journal journal, string path) {
    ofstream file;
    file.open(path);

    if (file.is_open()) {
        file << journal.counter << endl;

        for (int i = 0; i < journal.counter; i++) {
            file << journal.records[i].surname << " " << journal.records[i].grade << endl;
        }

        file.close();
    }
}

int main () {
    Journal journal1 = read("journal1.txt");
    Journal journal2 = read("journal2.txt");

    Rogue rogue1 = getRogue(journal1);
    Rogue rogue2 = getRogue(journal2);

    Journal journal;
    if (rogue1.counter > rogue2.counter) {
        journal = exclude(journal1, rogue1);
    } else {
        journal = exclude(journal2, rogue2);
    }
    
    write(journal, "journal.txt");

    // cout << rogue1.counter << endl;
    // cout << rogue2.counter << endl;

    // cout << journal.counter << endl;
    // for (int i = 0; i < journal.counter; i++) {
    //     cout << journal.records[i].surname << " " << journal.records[i].grade << endl;
    // }
}