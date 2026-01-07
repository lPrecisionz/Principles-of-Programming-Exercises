#include <iostream> 
#include <vector>

class bad_input {};
class invalid_n {};

void read_n(int &n){
  std::cin >> n;
  if(!std::cin || n <= 0){
    throw bad_input();
  }
}

void print_first_n(const std::vector<int> &vec, int n){
  for(int i = 0; i < n; ++i){
    std::cout << " " << vec[i] << " ";
  }
}

int sum_first_n(const std::vector<int> &vec, int n){
  int sum {0};
  for(int i = 0; i < n; ++i){
    sum+= vec[i];
  }
  return sum;
}

void read_vector(std::vector<int> &vec, int n){
  std::cout << "Please enter some integers (press '|' to stop): " << std::endl;
  for(int input; std::cin >> input;){
    vec.push_back(input);
  }
  if(n > vec.size()){
    throw invalid_n();
  }
}

void show_sum(const std::vector<int> &vec, int n){

  std::cout << "The sum of the first " << n << " numbers ( ";
  print_first_n(vec, n);
  std::cout << " ) is " << sum_first_n(vec, n) << std::endl;
}

int main(){
  int n {0};
  std::vector<int> vec;
  
  std::cout << "Please enter the number of values you want to sum: ";
  try{
    read_n(n);
  } catch (bad_input){
    std::cout << std::endl << "Invalid input" << std::endl;
    return -1;
  }

  try{
    read_vector(vec, n);
  } catch (invalid_n){
    std::cerr << "Error: n is larger then input count" << std::endl;
    return -1;
  }

  show_sum(vec, n);

  return 0;
}
