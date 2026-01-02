#include <iostream>


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

double exec_operation(std::string *operation, double *num1, double *num2){
  if (*operation == "+") return sum(num1, num2);
  if (*operation == "-") return sub(num1, num2);
  if (*operation == "*") return mul(num1, num2);
  if (*operation == "/") return div(num1, num2);

  std::cout << "Invalid Operation!" << std::endl;
  exit(1);
}

int main(){
  std::string operation;
  double      num1;
  double      num2;
  double      result;

  std::cout << "Please enter an operation and 2 numbers." << std::endl;
  std::cout << "Operations: "
            << std::endl 
            << "+,  -,  *,  /"
            <<std::endl;

  std::cin >> operation >> num1 >> num2;

  result = exec_operation(&operation, &num1, &num2);
  
  std::cout << result << std::endl;

}
