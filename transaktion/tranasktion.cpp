#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    setlocale (LC_ALL, "rus");
    bool variant;
    while (!(variant == 1 || variant == 0)) ;// не работает проверак

    cout << "Do you want to make a transaction?\n";
    cout << "To confirm, press 1. To cancel, press 0.\n";
    cin >> variant;

    if (variant == 1) { 
        cout << "You have confirmed\n"; 
        cout << "Loading...\n"; 
        usleep(5000000); // Задержка на 5 секунд
        cout << "The operation is completed\n"; 
    } else {
        cout << "The transaction has been canceled\n";
    }
usleep(5000000); // Задержка на 5 секунд
    return 0;
}