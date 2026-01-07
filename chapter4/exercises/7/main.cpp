// ax2 +bx + c = 0
// (-b - sqrt(delta))/2ac -> x1
// (-b + sqrt(delta))/2ac -> x2
// delta = b2 - 4ac 

#include <iostream>
#include <cmath>

class delta_err {};

double delta(const double &a, const double &b, const double &c){
  double result = (b*b) - 4 * a*c;
  
  if(result < 0){
    //std::cerr << "Error: Delta cannot be less than 0" << std::endl;
    throw delta_err();
  }

  return result;
}

double solve_x1(const double &a, const double &b, const double &c){
  return ((b * (-1)) + sqrt(delta(a, b, c))) / (2 * a);
}

double solve_x2(const double &a, const double &b, const double &c){
  return ((b * (-1)) - sqrt(delta(a, b, c))) / (2 * a);
}

void solve_quadratic(const double &a, const double &b, const double &c){
  double delta_result {0}, 
         x1           {0}, 
         x2           {0};
  try{
    delta_result = delta(a, b, c);
    x1 = solve_x1(a, b, c);
    x2 = solve_x1(a, b, c);
    std::cout << "Solving quadratic equation for a, b, c = {" << a << b << c << "}" << std::endl;
    std::cout << "x1 = " << x1 << std::endl << "x2 = " << x2 << std::endl;
  } catch (delta_err){
    std::cout << "No Real Solution." << std::endl;
  };
}

int main(){
  double a {0}, 
         b {0},
         c {0};

  std::cin >> a >> b >> c;
  solve_quadratic(a, b, c);

  return 0;
}
