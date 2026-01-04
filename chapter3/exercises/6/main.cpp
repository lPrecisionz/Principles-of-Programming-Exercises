#include <iostream> 

constexpr char ADD_OPERATOR = '+';
constexpr char SUB_OPERATOR = '-';
constexpr char MUL_OPERATOR = '*';
constexpr char DIV_OPERATOR = '/';

bool validate_operator(const char &c){
  return (
    c == ADD_OPERATOR ||
    c == SUB_OPERATOR ||
    c == MUL_OPERATOR ||
    c == DIV_OPERATOR
  );
}

double calculate(const double &num1, const double &num2, const char &c){
  switch(c){
    case ADD_OPERATOR:
      return num1+num2; 
      break;
    case SUB_OPERATOR:
      return num1-num2;
      break;
    case MUL_OPERATOR:
      return num1*num2;
      break;
    case DIV_OPERATOR:
      return num1/num2;
  }

  return -1;
}

bool read_input(double &num1, double &num2, char &c){
  std::cout << "Please enter 2 numbers and an operator (+, -, *, /)" << std::endl;
  std::cin >> num1 >> num2 >> c;

  if (!validate_operator(c)) return false;

  return true;
}

std::string get_operator_string(const char &c){
  switch(c){
    case ADD_OPERATOR:
      return "sum"; 
      break;
    case SUB_OPERATOR:
      return "subtraction";
      break;
    case MUL_OPERATOR:
      return "multiplication";
      break;
    case DIV_OPERATOR:
      return "division";
  }
  return "";
}

void show_result(const double &num1, const double &num2, const double &result, const char &op){
  std::string op_string = get_operator_string(op);
  std::cout << "\nThe " << op_string << " of " << num1 << " and " << num2 << " is " << result << "." << std::endl;
}

int main(){
  double num1    {0}, 
         num2    {0},
         result  {0};
  char op {'0'};

  std::cout << "========== CALCULATOR ==========" << std::endl;

  if(!read_input(num1, num2, op)){
    std::cout << "\nError: Invalid Input" << std::endl;
    return -1;
  }

  result = calculate(num1, num2, op);
  show_result(num1, num2, result, op);

  return 0;
}
