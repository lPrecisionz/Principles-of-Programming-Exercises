#include <iostream>
#include <ostream>

double* get_smaller(double *num1, double *num2){
  if (*num1 < *num2)
    return num1;
  return num2;
}

double* get_larger(double *num1, double *num2){
  if(*num1 > *num2)
    return num1;
  return num2;
}

double sum(double *num1, double *num2){
  return *num1 + *num2;
}

double sub(double *num1, double *num2){
  return *num1 - *num2;
}

double mul(double *num1, double *num2){
  return *num1 * *num2;
}

double div(double *num1, double *num2){
  return *num1 / *num2;
}

void show_result(double *num1, double *num2){
  std::cout << std::endl
            << "Smaller:  "      << *get_smaller(num1, num2)  << std::endl
            << "Larger:   "      << *get_larger(num1,num2)    << std::endl
            << "Sum:      "      << sum(num1, num2)          << std::endl 
            << "Sub:      "      << sub(num1, num2)          << std::endl
            << "Mul:      "      << mul(num1, num2)          << std::endl
            << "Div:      "      << div(num1, num2)          << std::endl;
}

int main(){

  double val1 {0}, val2{0};

  std::cout << "Enter 2 doubleegers: ";
  std::cin >> val1 >> val2;

  show_result(&val1, &val2);
}
