#include <iostream>

constexpr double c_to_f_factor { 9.0 / 5.0 };
constexpr double c_to_f_constant { 32 };

constexpr double min_fahrenheit {-459.67};
constexpr double min_celsius    {-273.15};

double c_to_f(double c){
  if(c < min_celsius){
    std::cerr << "Error: celsius temperature can't be lower than " << min_celsius;
    throw std::exception();
  }

  return (c * c_to_f_factor) + c_to_f_constant;
}

double f_to_c(double f){
  if(f < min_fahrenheit){
    std::cerr << "Error: fahrenheit temperature can't be lower than " << min_fahrenheit;
    throw std::exception();
  }

  return (f - c_to_f_constant) * 5/9;
}

int main(){
  double celsius_input {0}, 
         fh_input      {0};

  std::cout << "Enter a celsius temperature: ";
  std::cin >> celsius_input;

  std::cout << celsius_input << " in " << " fahrenheit: " << c_to_f(celsius_input) << std::endl;

  std::cout << "Enter a fahrenheit temperature: ";
  std::cin >> fh_input;

  std::cout << fh_input << " in " << " celsius: " << f_to_c(fh_input) << std::endl;

  return 0;
}
