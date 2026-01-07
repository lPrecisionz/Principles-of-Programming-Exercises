#include <iostream>

constexpr double c_to_k_factor {273.25};
constexpr double min_celsius   {-273.15};
constexpr double min_kelvin    {0};



double c_to_k(double c) { 
  if (c < min_celsius){
    std::cerr << "error: celsius temperature can't be lower than" << min_celsius << std::endl;
    throw std::exception();
  }

  double k = c + c_to_k_factor; 

  if(k < 0){
    std::cerr << "error: Kelvin temperature can't be lower than " << min_kelvin << std::endl;
    throw std::exception();
  }
  return k;
} 

double k_to_c(double k) { 
  if (k <  min_kelvin){
    std::cerr << "error: kelvin temperature can't be lower than" << min_kelvin << std::endl;
    throw std::exception();
  }

  double c = k - c_to_k_factor; 

  if(c < min_celsius){
    std::cerr << "error: Celsius temperature can't be lower than " << min_celsius << std::endl;
    throw std::exception();
  }
  return c;
} 

int main() { 
  double k = 0; 
  std::cin >> k; 
  double c = k_to_c(k); 
  std::cout << c << std::endl; 
  
  return 0;
}
