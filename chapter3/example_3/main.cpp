#include <iostream>
#include<vector>
#include <algorithm>

int main(){
  std::vector<std::string> words;
  std::string disliked_word = "women";
  
  std::cout << "Enter n words: " << std::endl;
  for(std::string temp; std::cin >> temp;){
    words.push_back(temp);
  }
  
  std::ranges::sort(words);
  
  std::cout << "Word list: " << std::endl;
  for(int i = 0; i < words.size(); ++i){
    if(i == 0 || words[i] != words[i-1]){
      if(words[i] != disliked_word)
        std::cout << words[i] << std::endl;
      else 
        std::cout << "BLEEP";
    }
  }

}
