#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <windows.h>

using namespace std;

int main() {
    srand(time(0));

    while (true) {
        int randnamber = rand() % 100 + 1; // Исправленное объявление
        int user;

        cout << "remember number: ";
        cout << randnamber << endl; // Добавлено endl для переноса строки
        Sleep(1500); // Пауза на 1.5 
        system("cls"); // чистка консоли
        cout << "insert: ";

        cin >> user;

        if (user == randnamber) {
            cout << "true!" << endl;
        }
        else {
            cout << "err: " << randnamber << endl; // Исправленное else
        }
        cout << "resume" << endl;
        char resume;
        cin >> resume;

            if (resume == '\r')
            {
                break;
            }

       
    }
    cout << "bye!" << endl;
    return 0;
}