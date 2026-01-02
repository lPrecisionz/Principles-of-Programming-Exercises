#include <iostream>

void swap(int *a, int *b){
  int helper = *a;
  *a = *b;
  *b = helper;
}

void sort(int *a, int *b, int *c){

  if (*a > *b)
    swap(a, b);
 
  if (*a > *c)
    swap(a, c);

  if (*b > *c)
    swap(b, c);

}

int main(){

  int a{0}, b{0}, c{0};
  
  std::cout << "Please enter 3 numbers: ";
  std::cin >> a >> b >> c;

  sort(&a, &b, &c);
  std::cout << std::endl 
            << "Values in order: " 
            << a << ", " 
            << b << ", " 
            << c << std::endl;
}
