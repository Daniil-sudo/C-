#include <iostream>
#include <string>

using namespace std;

class town {
public:
    town() : population(1000), named("gorgia") {} // Конструктор
    int population; //популяция
    string named; //наименование
};

class human {
public:
    human() : age(20), social_coat("work_man") {} // Конструктор
    int age;//года
    string social_coat;//социальный слой 
};

class job {
public:
    job() : job_Pos(100), name_job("driver") {} // Конструктор
    int job_Pos;//рабочих мест
    string name_job;//наименование работы
};

int main(){
bool continueLoop = true;
while (continueLoop) {
    string className;
    cout << "select class (town, human, job): " << endl;
    cin >> className;

    if (className == "town") {
        town t; 
        cout << "population: " << t.population << endl;
        cout << "named: " << t.named << endl;
    } else if (className == "human") {
        human h; 
        cout << "age: " << h.age << endl;
        cout << "social_coat: " << h.social_coat << endl;
    } else if (className == "job") {
        job j; 
        cout << "job_Pos: " << j.job_Pos << endl;
        cout << "name_job: " << j.name_job << endl;
    } else if (className == "exit") {
            continueLoop = false;  // Выход из цикла
        } else {
            cout << "Is not detected class" << endl;
}
}
    return 0;
}