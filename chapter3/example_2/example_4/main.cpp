#include <iostream>

double square(double num){
  double temp {0};
  for(int i = 0; i < num; i++){
   temp+=num;
  }
  return temp;
}

int main(){
  double num {0};
  std::cout << "Enter a number: ";
  std::cin  >> num;

  std::cout << "Square root of " << num << " is " << square(num) << std::endl;
  return 0;
}
