#include "PPPheaders.h"

constexpr int OFFSET_MIN {65};
constexpr int OFFSET_MAX {90};

char random_letter(){
  return narrow<char>(random_int(OFFSET_MIN, OFFSET_MAX));
}

int main(){
  PPP::seed(123);
  for(size_t i = 0; i < 10; ++i){
    std::cout << random_letter() << std::endl;
  }

  char test {0};
  std::cin >> test; 
  std::cout << "\ninput: " << test << std::endl;
  std::cout << "\ninput (int): " << static_cast<int>(test) << std::endl;

  return 0;
}
