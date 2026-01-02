#include <iostream>

int main(){
  
  constexpr int last_char = 26;
  int  i {0};
  char c {'a'};


  while(i < last_char){
    char current_char = c+i;
    std::cout << current_char << "\t" << static_cast<int>(current_char) << std::endl;
    ++i;
  }
  return 0;
}
