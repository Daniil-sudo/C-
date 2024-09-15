#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int numberfinger = 0;

    cout << "number finger: ";
    cin >> numberfinger;

    if (numberfinger == 1) {
        cout << "big finger";
    } else if (numberfinger == 2) {
        cout << "cursor finger";
    } else if (numberfinger == 3) {
        cout << "midle finger";
    } else if (numberfinger == 4) {
        cout << "no name finger";
    } else if (numberfinger == 5) {
        cout << "smoal finger";
    } else {
        cout << "Ха-ха, у вас нет столько пальцев";
    }

    return 0;
}