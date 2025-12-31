#include<iostream>
#include<vector>
int main(){
  std::cout << "========= Bathroom Instructions! =========" << std::endl << std::endl;

  std::vector<std::string> vec{
    "1. Get up from your chair",
    "2. Turn 30 degrees to your left", 
    "3. Walk torwards the direction of the stairs, if any obstruction appears, pause the walk and wait till the path is clear", 
    "4. Go up the stairs, follow the same stop and wait strategy as in step 3",
    "5. Once you've reached the second floor, walk 7 meters ahead and enter the bathroom"
  };


  for(int i = 0; i < vec.size(); i++){
    std::cout << vec[i] << std::endl;
  }

  return 0;

}
