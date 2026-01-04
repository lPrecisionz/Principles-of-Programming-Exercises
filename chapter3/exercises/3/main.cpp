#include <iostream>
#include <vector>

double median_of_vector(std::vector<double> &vec){
  if (vec.size()%2 != 0) 
    return vec[vec.size()/2];

  return (vec[vec.size()/2] + vec[(vec.size()/2)-1])/2;
}

int main(){
  std::vector<double> vec;
  for(double temp; std::cin>>temp;){
    vec.push_back(temp);
  }
  
  std::cout << "/nVector median: " << median_of_vector(vec);
  
  return 0;
}
