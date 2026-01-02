#include<iostream>

constexpr double c_yen    = 0.0064;
constexpr double c_kroner = 0.0990;
constexpr double c_pound  = 1.3500;

double yen_to_dollar(double yen){
  return yen * c_yen;
}

double kroner_to_dollar(double kroner){
  return kroner * c_kroner;
}

double pound_to_dollar(double pound){
  return pound * c_pound;
}

double coin_to_dollar(char coin, double value){
  switch(coin){
    case 'y':
      return yen_to_dollar(value);
      break;
    case 'k':
      return kroner_to_dollar(value);
      break;
    case 'p':
      return pound_to_dollar(value);
      break;
    default:
      return -1;
  }
}

int main(){
  char   coin;
  double value;

  std::cout << "Enter a value followed by a coin:" << std::endl;
  std::cin >> value >> coin;

  if(coin != 'y' && coin != 'k' && coin != 'p'){
    std::cout << "This coin isn't supported.";
      return -1;
  }

  std::cout << value << coin << " is " << coin_to_dollar(coin, value) << "$" << std::endl;

  return 0;
}
