#include "PPPheaders.h"
#include <linux/limits.h>
#include <stdexcept>

constexpr int VECTOR_SIZE { 4 };
constexpr int MIN_VALUE   { 0 };
constexpr int MAX_VALUE   { 9 };

constexpr int LETTER_OFFSET_START {65};
constexpr int LETTER_OFFSET_END   {90};

char random_letter(){
  return narrow<char>(random_int(LETTER_OFFSET_START, LETTER_OFFSET_END));
}

bool check_input_range(char c){
  int converted_c = static_cast<int>(c);
  return converted_c >= LETTER_OFFSET_START && converted_c <= LETTER_OFFSET_END;
}

bool find(const char value, const vector<char> &vec){
  if(vec.size() == 0) return false; 
  
  for(auto i : vec)
    if(i == value) return true;

  return false;
}

void print_vector(const vector<char> &vec){
  for(auto i : vec)
    std::cout << i << " ";

  std::cout << std::endl;
}

vector<char> read_inputs(){
  vector<char> inputs (VECTOR_SIZE);

  for(size_t i = 0; i < inputs.size(); ++i){
    std::cin >> inputs[i];
    if(!check_input_range(inputs[i]) || !std::cin)
      throw std::out_of_range("Error: invalid input.");
  }
  
  PPP::seed(inputs[VECTOR_SIZE-1]);
  return inputs;
}

vector<char> generate_truth(){
  vector<char> answer;
  char random_c {0};

  for(size_t i = 0; i < VECTOR_SIZE; ++i){
    random_c = random_letter();
    while(find(random_c, answer)){
      random_c = random_letter();
    }
    answer.push_back(random_c);
  }

  return answer;
}

vector<char> get_bull_hits(const vector<char> &truth, const vector<char> &guess){
  vector<char> bull_hits;
  for(size_t i = 0; i < guess.size(); ++i)
    if(guess[i] == truth[i])
      bull_hits.push_back(guess[i]);
  
  return bull_hits;
}

vector<char> get_cow_hits(const vector<char> &truth, const vector<char> &guess, const vector<char> &bull_hits){
  vector<char> cow_hits;

  for(size_t i = 0; i < guess.size(); ++i){
    if(find(guess[i], bull_hits)) 
      continue;
    if(find(guess[i], truth))
      cow_hits.push_back(guess[i]);
  }

  return cow_hits;
}

pair<int, int> get_result(const vector<char> &truth, const vector<char> &guess){
  vector<char> bull_hits { get_bull_hits(truth, guess) };
  vector<char> cow_hits  { get_cow_hits (truth, guess, bull_hits)};

  return pair<int, int>(bull_hits.size(), cow_hits.size());
}

void show_result(const vector<char> &guess, const vector<char> &truth){
  pair<int,int> result = get_result(truth, guess);
  int bull_hits {result.first}, 
      cow_hits  {result.second};

  std::cout << bull_hits << " bulls and " << cow_hits << " cows." << std::endl;
}

bool play_round(vector<char> &guess){
  vector<char> truth {generate_truth()};
  bool quit = false;
  while(!quit){
    std::cout << "Try to guess our letter vector! (a - z)\n";
    std::cout << "Your input: ";

    try{
      guess = read_inputs();
      } catch (const std::exception &e){
      std::cerr << e.what() << std::endl;
      return false;
    }

    std::cout << "truth: "; 
    print_vector(truth);
    show_result(guess, truth);
    if(guess != truth){
      std::cout << "\nTry again!\n";
    } else {
      quit = true;
    }
  }

  std::cout << "You got it!" << std::endl;
  return true;
}

int main(){
  vector<char> input_guess; 
 
  std::cout << "Bulls and Cows!" << std::endl; 
  while(play_round(input_guess)){
    std::cout << "Generated new answer." << std::endl;
    input_guess = {};
  }
  return 0;
}

/*
 *  Improvements: solve o(n^2), check for input with repeated numbers
 * 
 *
 *
 * */
