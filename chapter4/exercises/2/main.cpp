#include <iostream>
double c_to_k(double c) { 
  constexpr double converting_factor {273.25};
  double k = c + converting_factor; 
  return k;
} 

int main() { 
  double c = 0; 
  std::cin >> c; 
  double k = c_to_k(c); 
  std::cout << k << std::endl; 

}
