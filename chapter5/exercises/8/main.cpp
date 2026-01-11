#include <iostream>
#include <limits>

class Solver{
public: 
  int a, b;
  char op; 

public: 
  Solver() : a(0), b(0), op('0'){};
  void read_op();
  void read_values();
  void show_result();

private:
  int solve(); 
  int permutation(); 
  int combination();
  int factorial(int n);
};

void Solver::read_op(){
  std::cin >> this->op;
  if(op != 'p' && op != 'c' && op != 'q'){
    throw std::out_of_range("Invalid Input.\n");
  }
}

void Solver::read_values(){
  std::cin >> a >> b;
  if((a < 0 || b < 0) || b > a){
    throw std::out_of_range("Error: values can't be negative.");
  }
}

int Solver::factorial(int n){
  if(n==0) return 1;
  // if next fatorial > limit 32 bit -> erro 
  int result = n * factorial(n-1);
  if(result > std::numeric_limits<int>::max() / n)
    throw std::out_of_range("Error: factorial number surpassed int limit");

  return result;
}
    
int Solver::permutation(){
  return (factorial(a)) / (factorial(a-b));
}

int Solver::combination(){
  return (permutation()) / (factorial(b));
}

int Solver::solve(){
  if(this->op == 'p') return permutation();
  if(this->op == 'c') return combination();

  throw std::out_of_range("Error: operation not found");
}

void Solver::show_result(){
  std::cout << op << "("  << a << ","      << b << ")" 
            << " = " << this->solve() << std::endl;
}

void greet(){
  std::cout << "======== Welcome! ========" << std::endl;
}

void prompt_op(){
  std::cout << "What would you like to solve?" << std::endl 
            << "'p' for permutation" << std::endl 
            << "'c' for combination" << std::endl 
            << "'q' for quit" << std::endl 
            << "Your input: ";
}

void prompt_values(){
  std::cout << "Enter a and b (separated by whitespaces): ";
}

int main(){
  Solver solver;
  greet();

  while(true){
    prompt_op();
    try{
      solver.read_op();
      if(solver.op == 'q') 
        return 0;
      prompt_values();
      solver.read_values();
    } catch (const std::exception &e){
      std::cerr << e.what();
      return -1;
    }
    solver.show_result();
  }
}
