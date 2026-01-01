#include <iostream>

int main(){
  double d {0};

  while (std::cin >> d){
    int i = d; 
    char c = i;
    
    std::cout << "d == " << d << std::endl 
              << "i == " << i << std::endl 
              << "c == " << c << std::endl 
              << "char()"<< c << ")" << std::endl;
    
  }
}
