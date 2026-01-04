#include <iostream> 

int main(){
  std::string input; 

  std::cin >> input; 

  for (char c: input){
    std::cout << c << "\t" << static_cast<int>(c) << std::endl;
  }

  return 0; 
}
