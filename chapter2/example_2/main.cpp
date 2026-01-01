#include <iostream>
#include <cmath>

int main(){
  int n;
  
  std::cout << "Please enter an integer value." << std::endl;
  std::cin >> n;

  std::cout << "n == " << n << std::endl
            << "n+1 ==" << n+1 << std::endl
            << "three times n == " << n * 3 << std::endl 
            << "twice n == " << n + n << std::endl 
            << "n squared == " << n * n << std::endl
            << "half of n ==" << n / 2 << std::endl
            << "square root of n ==" << sqrt(n) << std::endl
            << "n mod 2 ==" << n%2 << std::endl;
}
