#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus"); 
    int arifmet_1;  // Убираем присвоение значения

    cout << "1 * 2 = ";
    cin >> arifmet_1;

    if (arifmet_1 == 2) { // Проверяем, что введено 2
        cout << "2 goood boy\n"; // Добавляем перевод строки
    } else { 
        cout << "err \n"; // Добавляем перевод строки
    }
    int arifmet_2;
    cout << "2 * 2 =";
    cin >> arifmet_2;
    if (arifmet_2 == 4) // должно бытть в ответе 4
    {
        cout << "you me lucke friend\n"; // верный ответ
    }
    else
    {
       cout << "noo you maked fackuP\n"; // когда ошибся
    }
    int arifmet_3;
    cout << "2 * 3 =";
    cin >> arifmet_3;
    if (arifmet_3 == 6)
    {
        cout << "nice\n";
    }
    else
    {
        cout << "sucked\n";
    }
    int arifmet_4;
    cout << "2 * 4 =";
    cin >> arifmet_4;
    if (arifmet_4 == 8)
    {
        cout << "some body to love\n";
    }
    else
    {
        cout << "fuck around\n";
    }
    
    
    
    cout << "loading\n";
    usleep(5000000); // Задержка на 5 секунды (5000000 микросекунд)
    cout << "END\n";


    return 0; // Завершаем программу
}