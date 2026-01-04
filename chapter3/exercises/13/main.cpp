#include <iostream>
#include <vector>
#include <cmath>

std::vector<unsigned int> get_primes(const int n){
  std::vector<bool> p_flags {false, false};
  std::vector<unsigned int> primes;
  
  //populate flags vector
  for(int i = 2; i < n; ++i){
    p_flags.push_back(true);
  }
  
  // set flags
  for(int i = 2; i*i < n; ++i){
    for(int j = i*i; j < n; j+=i){
        p_flags[j] = false;
    }
  }
  
  for(int i = 0; i < p_flags.size(); i++){
    if (p_flags[i])
      primes.push_back(i);
  }

  std::cout << "flag vector:\n";
  for(int i = 0; i < p_flags.size(); ++i){
    std::cout << i << ": " << p_flags[i] << std::endl;
  }
  
  return primes;
}

void print_vector(std::vector<unsigned int> &vec){
  for(auto i : vec){
    std::cout << i << std::endl;
  }
}

int main(){
  unsigned int n {100};
  std::vector<unsigned int> primes {get_primes(n)};

  print_vector(primes);

  return 0;
}
