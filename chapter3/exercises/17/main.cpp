// ax2 +bx + c = 0
// (-b - sqrt(delta))/2ac -> x1
// (-b + sqrt(delta))/2ac -> x2
// delta = b2 - 4ac 

#include <iostream>
#include <cmath>

double delta(const double &a, const double &b, const double &c){
  return (b*b) - 4 * a*c;
}

double solve_x1(const double &a, const double &b, const double &c){
  return ((b * (-1)) + sqrt(delta(a, b, c))) / (2 * a);
}

double solve_x2(const double &a, const double &b, const double &c){
  return ((b * (-1)) - sqrt(delta(a, b, c))) / (2 * a);
}

int main(){
  double a {0}, 
         b {0},
         c {0};

  std::cout << "Enter a, b and c: ";
  std::cin >> a >> b >> c;

  std::cout << "x1 = " << solve_x1(a, b, c) << std::endl 
            << "x2 = " << solve_x2(a, b, c) << std::endl;

  return 0;
}
