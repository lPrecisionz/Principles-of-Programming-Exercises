#include <iostream>
#include <ostream>

int* get_smaller(int *num1, int *num2){
  if (*num1 < *num2)
    return num1;
  return num2;
}

int* get_larger(int *num1, int *num2){
  if(*num1 > *num2)
    return num1;
  return num2;
}

int sum(int *num1, int *num2){
  return *num1 + *num2;
}

int sub(int *num1, int *num2){
  return *num1 - *num2;
}

int mul(int *num1, int *num2){
  return *num1 * *num2;
}

int div(int *num1, int *num2){
  return *num1 / *num2;
}

void show_result(int *num1, int *num2){
  std::cout << std::endl
            << "Smaller:  "      << *get_smaller(num1, num2)  << std::endl
            << "Larger:   "      << *get_larger(num1,num2)    << std::endl
            << "Sum:      "      << sum(num1, num2)          << std::endl 
            << "Sub:      "      << sub(num1, num2)          << std::endl
            << "Mul:      "      << mul(num1, num2)          << std::endl
            << "Div:      "      << div(num1, num2)          << std::endl;
}

int main(){

  int val1 {0}, val2{0};

  std::cout << "Enter 2 integers: ";
  std::cin >> val1 >> val2;

  show_result(&val1, &val2);
}
