#include <iostream>
#include <vector> 

std::vector<int> ref_vector {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3
};


int mode(const std::vector<int> &vec){
  int prev_count     {0}, 
      curr_count     {0}, 
      most_repeating {0};

  for(int i = 0; i < vec.size(); ++i){
    for(int j = i; j < vec.size(); ++j){

      if(vec[j] == vec[i])
        ++curr_count;
    }
    if(curr_count > prev_count){
      prev_count = curr_count;
      most_repeating = vec[i];
    }
    curr_count = 0;
  }

  return most_repeating;
}

int main(){
  std::cout << mode(ref_vector) << std::endl;
  return 0;
}
