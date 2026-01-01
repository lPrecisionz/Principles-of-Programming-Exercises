#include <iostream>

int main(){

  std::string name;
  double      age;

  std::cout << "Please enter your first name and age" << std::endl;

  std::cin >> name >> age;

  std::cout << "Hello, " << name << " (age " << age*12 << " months)" << std::endl;
}
