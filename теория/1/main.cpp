#include <iostream>

using namespace std;

int main () {
    int x = 5;
    int y = 1;

    int *px = &x; // указатель
    int *py = &y; // указатель

    cout << "x = " << x << endl;
    cout << "sizeof(x) = " << sizeof(x) << endl;
    cout << "&x = " << &x << endl;
    cout << "px = " << px << endl;
    cout << "sizeof(px) = " << sizeof(px) << endl;
    cout << "*px = " << *px << endl;
    cout << "*(px+1) = " << *(px+1) << endl;
    cout << "*(px+2) = " << *(px+2) << endl;

    cout << endl;

    cout << "y = " << y << endl;
    cout << "&y = " << &y << endl;
    cout << "py = " << py << endl;
    cout << "*py = " << *py << endl;

    cout << endl;

    int arr[3] = {1, 2, 3}; 
    // int arr[3]; 
    // int arr[] = {1, 2, 3}; 
    // int arr[]{1, 2, 3}; 

    cout << "sizeof(arr) = " << sizeof(arr) << endl;
    cout << "arr[0] = " << arr[0] << endl;
    cout << "arr[1] = " << arr[1] << endl;
    cout << "arr[2] = " << arr[2] << endl;
    cout << "arr[3] = " << arr[3] << endl;

    cout << endl;

    cout << "arr = " << arr << endl;
    cout << "&arr = " << &arr << endl;
    cout << "*arr = " << *arr << endl;
    cout << "*(arr+1) = " << *(arr+1) << endl;
    cout << "*(arr+2) = " << *(arr+2) << endl;
    cout << "*(arr+3) = " << *(arr+3) << endl;

    cout << endl;

    char a = 'a';
    cout << "a = " << a << endl;
    cout << "(void *)&a = " << (void *)&a << endl;
    cout << "sizeof(a) = " << sizeof(a) << endl;

    cout << endl;
}