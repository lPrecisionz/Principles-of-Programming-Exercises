#include <iostream>
#include <ostream>

bool is_even(int *num){
  return *num%2 == 0;
}

std::string get_number_parity(int *num){
  if(is_even(num))
    return "even";
  return "odd";
}

int main(){
  int num;

  std::cout << "Please enter a number: ";
  std::cin  >> num;

  std::cout << std::endl
            << "The number " 
            << num 
            << " is " 
            << get_number_parity(&num)
            << std::endl;
}
