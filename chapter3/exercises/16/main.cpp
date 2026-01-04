#include <iostream>
#include <vector> 

std::vector<std::string> ref_vector {
  "a", "a", "aa", "aa", "aa", "bb"
};


std::string mode(const std::vector<std::string> &vec){
  int prev_count     {0}, 
      curr_count     {0};
  std::string most_repeating;

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

std::string max(const std::vector<std::string> &vec){
  std::string max_string;
  for(const std::string s : vec){
    if (s > max_string)
      max_string = s;
  }
  return max_string;
}

std::string min(const std::vector<std::string> &vec){
  std::string min_string = max(vec);
  for(const std::string s : vec){
    if(s < min_string)
      min_string = s;
  }
  return min_string;
}

int main(){
  std::cout << "mode:\t" << mode(ref_vector) << std::endl;
  std::cout << "min:\t" << min(ref_vector) << std::endl;
  std::cout << "max:\t" << max(ref_vector) << std::endl;
  return 0;
}
