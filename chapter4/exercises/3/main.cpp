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

int main() { 
  double c = 0; 
  std::cin >> c; 
  double k = c_to_k(c); 
  std::cout << k << std::endl; 

}
