#include "PPPheaders.h"
#include <stdexcept>

constexpr int VECTOR_SIZE { 4 };
constexpr int MIN_VALUE   { 0 };
constexpr int MAX_VALUE   { 9 };

bool find(const int value, const vector<int> &vec){
  if(vec.size() == 0) return false; 
  
  for(auto i : vec)
    if(i == value) return true;

  return false;
}

void print_vector(const vector<int> &vec){
  for(auto i : vec)
    std::cout << i << " ";

  std::cout << std::endl;
}

vector<int> read_inputs(){
  int curr_input {0};
  vector<int> inputs;

  while(std::cin >> curr_input)
    inputs.push_back(curr_input);

  if(inputs.size() != VECTOR_SIZE)
    throw std::runtime_error("Error: You must guess 4 integer numbers.");

  return inputs;
}

vector<int> generate_truth(){
  vector<int> answer;
  int random_number {0};

  for(size_t i = 0; i < VECTOR_SIZE; ++i){
    random_number = PPP::random_int(MIN_VALUE, MAX_VALUE);
    while(find(random_number, answer)){
      random_number = PPP::random_int(MIN_VALUE, MAX_VALUE); 
    }
    answer.push_back(random_number);
  }

  return answer;
}

vector<int> get_bull_hits(const vector<int> &truth, const vector<int> &guess){
  vector<int> bull_hits;
  for(size_t i = 0; i < guess.size(); ++i)
    if(guess[i] == truth[i])
      bull_hits.push_back(guess[i]);
  
  return bull_hits;
}

vector<int> get_cow_hits(const vector<int> &truth, const vector<int> &guess, const vector<int> &bull_hits){
  vector<int> cow_hits;

  for(size_t i = 0; i < guess.size(); ++i){
    if(find(guess[i], bull_hits)) 
      continue;
    if(find(guess[i], truth))
      cow_hits.push_back(guess[i]);
  }

  return cow_hits;
}

pair<int, int> get_result(const vector<int> &truth, const vector<int> &guess){
  vector<int> bull_hits { get_bull_hits(truth, guess) };
  vector<int> cow_hits  { get_cow_hits (truth, guess, bull_hits)};

  return pair<int, int>(bull_hits.size(), cow_hits.size());
}

void show_result(const vector<int> &guess, const vector<int> &truth){
  pair<int,int> result = get_result(truth, guess);
  int bull_hits {result.first}, 
      cow_hits  {result.second};

  std::cout << bull_hits << " bulls and " << cow_hits << " cows." << std::endl;
}

int main(){
  PPP::seed();

  vector<int> input_guess, 
              truth {generate_truth()};

  try{
      input_guess = read_inputs();
    } catch (const std::exception &e){
    std::cerr << e.what() << std::endl;
    return -1;
  }

  std::cout << "truth: "; 
  print_vector(truth);
  
  show_result(input_guess, truth);
  return 0;
}

/*
 *  Improvements: solve o(n^2), check for input with repeated numbers
 * 
 *
 *
 * */
