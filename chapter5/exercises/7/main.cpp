// I absolute despise what I've written here. 
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

std::vector<std::string> reference {
  "one", 
  "ten", 
  "hundred",
  "thousand"
};

int digit_to_num(const char c){
  int n = c - '0';
  if(n < 0 || n > 9) 
    throw std::out_of_range("Error: Invalid digit");

  return n;
}

std::string plural(const std::string &s, int count){
  if(count > 1) return s + 's';
  return s;
}

class Num{
public: 
  int digit;
  int base10_place;

public:
  Num(const char d, const int p): digit(digit_to_num(d)), base10_place(p){};
  int calculate();
  std::string get_place_name();
  void print();
};

int Num::calculate(){
  return digit * std::pow(10, base10_place);
}

std::string Num::get_place_name(){
  return plural(reference[this->base10_place], digit);
}

void read_inputs(std::vector<Num> &digits){
  char char_buffer {0};
  std::vector<char> inputs;
  while(std::cin >> char_buffer){
    if(char_buffer == ';') break;
    inputs.push_back(char_buffer);
  } 

  if(inputs.size() > 4)
    throw std::out_of_range("Only 4 digits are supported");
  
  int j=inputs.size()-1;
  for(int i = 0; i < inputs.size(); ++i){
    Num n = Num(inputs[i], j);
    digits.push_back(n);
    --j;
  }
}

int calculate_result(std::vector<Num> &digits){
  int result {0};
  for(int i = digits.size()-1; i >= 0; --i){
    result+=digits[i].calculate();
  }
  return result;
}

void print_result(std::vector<Num> &digits){
  std::cout << calculate_result(digits) << " is ";
  for(size_t i = 0; i < digits.size(); ++i){
    std::cout << digits[i].digit << " " << digits[i].get_place_name(); 
    if(i != digits.size()-1)
      std::cout << " and ";
  }
  std::cout << "." << std::endl;
}

int main(){
  std::vector<Num> digits;
  
  read_inputs (digits);
  print_result(digits);

  return 0;
}
