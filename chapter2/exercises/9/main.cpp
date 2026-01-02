#include <iostream>

#define INVALID_STRINGNO_INPUT -1

int get_numeric_value(std::string *s){
  
  if (*s == "zero")
    return 0;
  if (*s == "one") 
    return 1;
  if (*s == "two")
    return 2;
  if (*s == "three")
    return 3;
  if (*s == "four")
    return 4;

  return INVALID_STRINGNO_INPUT;
}


int main(){
  std::string spelled_number;
  int         numeric_value;

  std::cout << "Spell out a number: ";
  std::cin  >> spelled_number;

  numeric_value = get_numeric_value(&spelled_number);
  if (numeric_value != INVALID_STRINGNO_INPUT){
    std::cout << std::endl 
              << "The corresponding digit is "
              << numeric_value
              << std::endl;;
    return 0;
  }

  std::cout << std::endl  
            << "not a number I know..."
            << std::endl;
}
