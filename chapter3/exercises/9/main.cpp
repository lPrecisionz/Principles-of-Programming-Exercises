#include <cstdint>
#include <iostream>

unsigned int squares(const unsigned int rice_count){
  unsigned int curr_square     {1},
      prev_rice_count {1},
      curr_rice_count {1};

  while (curr_rice_count < rice_count){
    std::cout << "Square " << curr_square << ";\tRice Count: " << curr_rice_count << std::endl;
    curr_rice_count *= 2;
    ++curr_square;
  }

  return curr_square;
}

double rices(const unsigned int square_count){
  unsigned int curr_square     {1},
      prev_rice_count {1},
      curr_rice_count {1};

  while (curr_square < square_count){
    std::cout << "Square " << curr_square << ";\tRice Count: " << curr_rice_count << std::endl;
    curr_rice_count *= 2;
    ++curr_square;
  }

  return curr_square;
}

void run_exercise_test(const unsigned int rice_count){
  unsigned int square_count = squares(rice_count);
  std::cout << "Required squares for " << rice_count << " rices: " << square_count << std::endl;
}

int main(){
  run_exercise_test(1000);
  run_exercise_test(1000000);
  run_exercise_test(1000000000);

  double test = rices(64);
  return 0;
}
