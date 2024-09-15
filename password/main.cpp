#include<iostream>
#include<string>
#include<cstdlib>

char generateRandomChar() {
const int minChar = 33;
const int maxChar = 126;
return static_cast<char>(minChar + rand() % ( maxChar-minChar+1 ));
}
std::string generatePassword(int length) {
std::string password;
srand( static_cast<unsigned int >( time ( nullptr )));
for (int i = 0; i < length; ++i) {
password += generateRandomChar();
}
return password;
}
int main() {
int passwordLength = 20;
std :: string password = generatePassword(passwordLength) ;
std :: cout << "your password :"<< password << std::endl;
return 2;
}







































































































































































































