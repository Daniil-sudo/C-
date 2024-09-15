#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    char cifra1 = 0;
    char cifra2 = 0;
    char cifra3 = 0;
    char cifra4 = 0;
    char cifra5 = 0;

    cout << "Введите 5 чисел: " << endl;
    cin >> cifra1 >> cifra2 >> cifra3 >> cifra4 >> cifra5;

    // Вывод введенных символов на экран
    cout << "Вы ввели: ";
    cout << cifra1 << cifra2 << cifra3 << cifra4 << cifra5;
    cout << endl;

    return 0;
}