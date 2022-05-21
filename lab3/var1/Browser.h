#ifndef BROWSER_H
#define BROWSER_H

#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

class Browser {
    private:
        static int length;
        static Book* books;
    
    public:
        static Book search(string word);
};

#endif