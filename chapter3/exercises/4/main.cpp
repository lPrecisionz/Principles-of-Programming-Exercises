#include <iostream>
#include <vector>

#define HIGH_NUMBER 1000000

double modular_sub(double num1, double num2){
  double sub = num1 - num2;
  if (sub < 0) return sub * (-1);

  return sub;
}

double total_distance(std::vector<double> &vec){
  double sum {0};

  for(double x: vec){
    sum+=x;
  }

  return sum;
}

double smallest_distance(std::vector<double> &vec){
  double smallest_distance {HIGH_NUMBER}, 
         curr_distance {0}; 

  for(int i = 0; i < vec.size(); i++){
    if(i != vec.size() - 1)
      curr_distance = modular_sub(vec[i], vec[i+1]);

    if (curr_distance < smallest_distance) 
      smallest_distance = curr_distance;
  } 

  return smallest_distance;
}

double largest_distance(std::vector<double> &vec){
  double largest_distance {0}, 
         curr_distance {0}; 

  for(int i = 0; i < vec.size(); i++){
    if(i != vec.size() - 1)
      curr_distance = modular_sub(vec[i], vec[i+1]);
      
    if (curr_distance > largest_distance) 
      largest_distance = curr_distance;
  } 

  return largest_distance;
}

double mean_distance(std::vector<double> &vec){
  double sum {0};

  for(double x: vec){
    sum+=x;
  }

  return sum/vec.size();
}

int main(){
  std::vector<double> city_distances; 


  for(double x; std::cin >> x;){
    city_distances.push_back(x);
  }

  std::cout << "\nTotal distance:\t"  << total_distance    (city_distances) << std::endl
            << "Smallest distance:\t" << smallest_distance (city_distances) << std::endl
            << "Largest distance:\t"  << largest_distance  (city_distances) << std::endl 
            << "Mean distance:\t"     << mean_distance     (city_distances) << std::endl;

}
