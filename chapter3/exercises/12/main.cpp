#include <iostream>
#include <vector>

std::vector<unsigned int> primes{
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
};

bool find(std::vector<unsigned int> &vec, unsigned int val){
  for(auto num : vec){
    if (num == val) return true;
  }

  return false;
}

std::vector<unsigned int> generate_primes(){
  std::vector<unsigned int> generated_primes;
  for(int i = 1; i < 100; i++){
    if(find(primes, i))
      generated_primes.push_back(i);
  }

  return generated_primes;
}

void print_vector(std::vector<unsigned int> &vec){
  for(auto i : vec){
    std::cout << i << std::endl;
  }
}

int main(){
  std::vector generated_vector = generate_primes();
  std::cout << "Reference vector: " << std::endl;

  print_vector(primes);
  
  std::cout << "Generated vector: " << std::endl;
  print_vector(generated_vector);

  return 0;
}
