#include<iostream>

int main(){
  int         number_of_words = 0;
  std::string previous;
  std::string current;

  while (std::cin >> current){
    if(current == previous){
      ++number_of_words;
      std::cout << "word number: " << number_of_words << " repeated: " << current<< std::endl;
    }
    previous = current;
  }
  return 0;
}
