#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>


#define OUT_MESSAGE "Enter a double number: "
#define MAX_DOUBLE std::numeric_limits<double>::max();


constexpr double MIN_DIFFERENCE = 1.0/100;
constexpr double CM_IN_M        = 0.01000;
constexpr double IN_IN_M        = 0.25400;
constexpr double FT_IN_M        = 0.54800;

double sub_module(double &num1, double &num2){
  double diff = num1 - num2;
  if(diff > 0) return diff;

  return diff*=-1;
}

double &get_smaller(double &num1, double &num2){
  if(num1 < num2) return num1;
  return num2;
}

double &get_larger(double &num1, double &num2){
  if(num1 > num2) return num1;
  return num2;
}

void print_equality_status(double &num1, double &num2){
  if(num1==num2){
    std::cout << "the numbers are equal" << std::endl;
    return;
  }

  double diff = sub_module(num1, num2) ;

  if(diff < MIN_DIFFERENCE)
    std::cout << "the numbers are almost equal" << std::endl;
}

void update_if_smaller(double &base, double &comparison){
  if (comparison < base) {
    base = comparison;
    std::cout << "the smallest so far" << std::endl;
  }
}

void update_if_larger(double &base, double &comparison){
  if (comparison > base) {
    base = comparison;
    std::cout << "the largest so far" << std::endl;
  }
}

bool check_valid_unit(std::string &unit){
  if (unit == "cm" || 
      unit == "in" ||
      unit == "ft" ||
      unit == "m"
  ) return true;

  return false;
}

double unit_to_m(double &value, std::string &unit){
  if (unit == "cm") return value * CM_IN_M;
  if (unit == "in") return value * IN_IN_M;
  if (unit == "ft") return value * FT_IN_M;
  if (unit == "m")  return value * 1      ;
  exit(1);
}

void print_vector(std::vector<double> v){
  for(double i: v){
    std::cout << i << std::endl; 
  }
}

int main(){
  double num1          {0}, 
         num2          {0}, 
         curr_smallest {std::numeric_limits<double>::max()}, 
         curr_largest  {0}, 
         sum_in_m      {0}; 

  std::vector<double> inputs {0};

  int input_count {0};
  std::string unit;
  std::cout << OUT_MESSAGE;

  while (std::cin >> num1 >> unit){
    std::cout << num1 << unit << std::endl;

    if(!check_valid_unit(unit)){
      std::cout << "Invalid unit!" << std::endl;
      return -1;
    } 
    inputs.push_back(unit_to_m(num1, unit));
    sum_in_m += inputs.back();
    input_count+=1;
    
    update_if_smaller(curr_smallest, num1);
    update_if_larger(curr_largest, num1);
    std::cout << OUT_MESSAGE;
  }
  
  std::ranges::sort(inputs);
  
  std::cout << "\nProgram Finished!" << std::endl;
  std::cout << "Smallest number:\t" << curr_smallest << std::endl 
            << "Largest number:\t"  << curr_largest  << std::endl 
            << "Input count:\t"     << input_count   << std::endl 
            << "Sum of Values:\t"   << sum_in_m <<"m"<< std::endl;

  std::cout << "\nInputs vector (sorted): " << std::endl;
  print_vector(inputs);

  return 0;
}
