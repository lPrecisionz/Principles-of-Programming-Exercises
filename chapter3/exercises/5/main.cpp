#include <iostream>

constexpr int max_value = 100;
constexpr int lowest_value = 1;
constexpr int max_attempts = 7;

constexpr char response_yes = 'y';
constexpr char response_no  = 'n';

bool validate_number_input(int &num){
  return num >= lowest_value && num <= max_value;
}

bool validate_char_input(char &c){
  return c == response_yes || c == response_no;
}

void read_number_input(int &guess_input){
  while(!validate_number_input(guess_input)){
    std::cin >> guess_input;
    if(!validate_number_input(guess_input))
      std::cout << "\nInvalid Number! Try again." << std::endl;
  }
}

void read_char_input(char &c){
  while(!validate_char_input(c)){
    std::cin >> c;
    if(!validate_char_input(c))
      std::cout << "\nInvalid input! Type 'y' or 'n'" << std::endl;
  }
}

int guess(int &lower_bound, int &upper_bound){
  int guess_number  {0}, 
      attempt_count {0};
  char response {'a'};

  while(attempt_count < max_attempts){
    guess_number = (lower_bound + upper_bound)/2;
    std::cout << "\nCurrent lower bound = " << lower_bound;
    std::cout << "\nCurrent upper bound = " << upper_bound << std::endl;
    std::cout << "Is your number greater then " << guess_number << "? ('y' or 'n')" << std::endl;
    read_char_input(response);
    
    switch(response){
      case 'y':
        lower_bound = guess_number+1;
        break;
      case 'n':
        upper_bound = guess_number;
        break; 
    }
    response = 'a';
    ++attempt_count;

    if(lower_bound == upper_bound) return upper_bound;
  }

  return guess_number; 
}

int main(){

  int guess_input {0}, 
      lower_bound {lowest_value}, 
      upper_bound {max_value},
      answer      {0};
  
  std::cout << "========== GUESSING GAME ==========" << std::endl 
            << "Please enter a number between 1 and 100: ";
  
  read_number_input(guess_input);
  answer = guess(lower_bound, upper_bound);

  std::cout << "Your number is " << answer << std::endl;
  
  return 0;
}
