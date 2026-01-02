#include <iostream>

int main(){
  
  constexpr int last_char = 26;
  char c {'A'};


  for(int i = 0; i < last_char; i++){
    char current_char = c+i;
    std::cout << current_char << "\t" << static_cast<int>(current_char) << std::endl;
  }
  return 0;
}
