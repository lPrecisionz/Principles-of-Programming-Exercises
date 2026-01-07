#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

class bad_input {};

void read_n(int &n){
  std::cin >> n;

  if(!std::cin || n < 1){
    std::cerr << "Bad input for n" << std::endl;
    throw bad_input();
  }
}

std::vector<int> first_n_fibonacci(const int n){
  std::vector<int>fib {0, 1};

  for(size_t i = 2; i < n; ++i){
    int a = fib[i-2];
    int b = fib[i-1];
    if(b > std::numeric_limits<int>::max() - a){
      throw std::out_of_range("error: int overflow at " + std::to_string(i) + " with value  " + std::to_string(fib[i-1]));
    }
    fib.push_back(a+b);
  }

  return fib;
}

void print_vector(const std::vector<int> &vec){
  for(size_t i = 0; i < vec.size(); ++i){
    std::cout << i << " : " << vec[i] << std::endl;
  }
}

int main(){
  int n {0};
  std::vector<int> fibonacci_numbers;
  
  std::cout << "First n Fibonnaci Numbers" << std::endl << "Enter n: ";
  try{
    read_n(n);
  } catch(bad_input){
    return -1;
  }

  try{
    fibonacci_numbers = first_n_fibonacci(n);
  } catch (const std::out_of_range &oor){
    std::cerr << "Error: " << oor.what() << std::endl;
    return -1;
  }

  print_vector(fibonacci_numbers);

  return 0;
}
