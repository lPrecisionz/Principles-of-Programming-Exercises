#include <iostream>

#define MILE_1KM 1609

double mile_to_km(double m){
  return m * MILE_1KM;
}

int main(){
  double mile;

  std::cout << "===== Mile to KM Converter" << std::endl;
  std::cout << "Enter a mile value:";

  std::cin >> mile;
  std::cout << mile << " miles is " << mile_to_km(mile) << " kilometers" <<std::endl;
}
