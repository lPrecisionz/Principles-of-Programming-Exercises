#include <iostream> 
#include <limits>
#include <vector>

class bad_input {};
class invalid_n {};

void read_n(int &n){
  std::cin >> n;
  if(!std::cin || n <= 0){
    throw bad_input();
  }
}

void print_first_n(const std::vector<double> &vec, int n){
  for(int i = 0; i < n; ++i){
    std::cout << " " << vec[i] << " ";
  }
}

double sum_first_n(const std::vector<double> &vec, int n){
  double sum {0};
  for(size_t i = 0; i < n; ++i){
    sum+= vec[i];
  }
  return sum;
}
// 1  3  2  5
// 0  1  2  3
std::vector<double> first_n_differences(const std::vector<double> &nums, int n){
  if(n > nums.size()-1){
  std::cerr << "Error: Can't calculate first n differences. Vector.size()-1 is smaller than n." << std::endl;
    throw std::exception();
  }

  std::vector<double> n_diffs;

  for(size_t i = 0; i < n; ++i){
    n_diffs.push_back(nums[i+1] - nums[i]);
  }

  return n_diffs;
}

void read_vector(std::vector<double> &vec, int n){
  std::cout << "Please enter some doubles (press '|' to stop): " << std::endl;
  for(double input; std::cin >> input;){
    vec.push_back(input);
  }
  if(n > vec.size()){
    throw invalid_n();
  }
}

void show_sum(const std::vector<double> &vec, int n){

  std::cout << "The sum of the first " << n << " numbers ( ";
  print_first_n(vec, n);
  double sum = sum_first_n(vec, n);
  std::cout << " ) is " << sum << std::endl;
}

int main(){
  int n {0};
  std::vector<double> values_vec;
  std::vector<double> diffs_vec;
  
  std::cout << "Please enter the number of values you want to sum: ";
  try{
    read_n(n);
  } catch (bad_input){
    std::cout << std::endl << "Invalid input" << std::endl;
    return -1;
  }

  try{
    read_vector(values_vec, n);
  } catch (invalid_n){
    std::cerr << "Error: n is larger then input count" << std::endl;
    return -1;
  }

  show_sum(values_vec, n);

  try{
    diffs_vec = first_n_differences(values_vec, n);
    std::cout << "\nDiffs vector:" << std::endl;
    print_first_n(diffs_vec, diffs_vec.size());
  }
  catch(std::exception){}

  return 0;
}
