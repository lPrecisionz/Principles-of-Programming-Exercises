#include <random> 
#include <utility>

namespace PPP {

inline std::default_random_engine& get_rand(){
  static std::default_random_engine eng{};
  return eng;
}

inline void seed(int s){ get_rand().seed(static_cast<unsigned>(s));}
inline void seed() {get_rand().seed();}

inline int random_int(int min, int max){
  if(min > max) std::swap(min,max);
  return std::uniform_int_distribution<int>{min, max}(get_rand());
}

inline int random_int(int max){
  return random_int(0, max);
}

} //namespace PPP
