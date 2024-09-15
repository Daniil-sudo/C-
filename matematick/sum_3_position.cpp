#include <iostream>
using namespace std;

int main() {
setlocale (LC_ALL, "rus"); //вывод кириллицы

int chocolate = 2; //кол-во упаковок
int milk = 3;
int coffe = 4;

float priceOfChocolate = 100; //цена за упаковку
float priceOfMilk = 200;
float priceOfCoffe = 300;
float sum = 0;

sum = (chocolate*priceOfChocolate)+(milk*priceOfMilk)+(coffe*priceOfCoffe);
cout << ("сумма продуктов = ");
cout << chocolate*priceOfChocolate<<'+'<<milk*priceOfMilk<<'+'<<coffe*priceOfCoffe;
cout << "=" << sum << endl << endl;
return  0;
}