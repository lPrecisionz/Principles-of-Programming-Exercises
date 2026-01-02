#include <iostream>

void swap(std::string *a, std::string *b){
  std::string helper = *a;
  *a = *b;
  *b = helper;
}

void sort(std::string *a, std::string *b, std::string *c){

  if (*a > *b)
    swap(a, b);
 
  if (*a > *c)
    swap(a, c);

  if (*b > *c)
    swap(b, c);

}

int main(){

  std::string a, b, c;
  
  std::cout << "Please enter 3 strings: ";
  std::cin >> a >> b >> c;

  sort(&a, &b, &c);
  std::cout << std::endl 
            << "Values in order: " 
            << a << ", " 
            << b << ", " 
            << c << std::endl;
}
