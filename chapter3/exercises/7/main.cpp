#include <iostream> 
#include <vector>

constexpr int MIN_VALUE = 0;
constexpr int MAX_VALUE = 9;

std::vector<std::string>spelled_numbers {
  "zero",
  "one", 
  "two", 
  "three", 
  "four", 
  "five",
  "six", 
  "seven", 
  "eight", 
  "nine"
};

int char_to_int(const char c){
  return static_cast<int>(c) - '0';
}

bool validate_digit(const std::string &s){
  if(s.size() > 1) return false;

  int converted_char = char_to_int(s.at(0));

  return converted_char >= MIN_VALUE && converted_char <= MAX_VALUE;
}

bool validate_string(const std::string &input){
  for(std::string s : spelled_numbers){
    if (s == input) return true;
  }

  return false;
}

bool validate_input(const std::string &s){
  return validate_digit(s) || validate_string(s);
}

bool read_input(std::string &s){
  std::cout << "Enter a digit between 0 and 9: ";
  std::cin >> s;
  
  return validate_input(s);
}

std::string get_spelled_number(const char digit){
  int num = char_to_int(digit);
  return spelled_numbers[num];
}

int get_number(const std::string &s){
  for(int i = 0; i < spelled_numbers.size(); i++){
    if (spelled_numbers[i] == s) return i;
  }

  return -1;
}

void show_result(const std::string &input){
  if(validate_digit(input)){
    std::cout << get_spelled_number(input.at(0)) << std::endl;
    return;
  }

  if(validate_string(input)){
    std::cout << get_number(input) << std::endl;
    return;
  }

  exit(1);
}

int main(){
  std::string input;

  if(!read_input(input)){
    std::cout << "\nInvalid Input! Program finished." << std::endl;
    return -1;
  }
  
  show_result(input);
  return 0;
}
