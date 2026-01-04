#include <iostream>
#include <vector>

constexpr char rock_char {'r'};
constexpr char paper_char {'p'};
constexpr char scissors_char {'s'};

enum PLAY {
  ROCK, 
  PAPER, 
  SCISSORS
};

enum RESULT{
  WIN, 
  LOSS, 
  TIE
};

std::vector<PLAY> plays{
  ROCK, 
  ROCK, 
  SCISSORS, 
  ROCK, 
  SCISSORS, 
  PAPER, 
  ROCK, 
  PAPER, 
  SCISSORS, 
  PAPER, 
  PAPER, 
  PAPER, 
  SCISSORS, 
  ROCK, 
  SCISSORS, 
  PAPER, 
  ROCK, 
  ROCK
};

unsigned int current_play {0};

RESULT get_result(PLAY p1, PLAY p2){
  if (p1==p2) return RESULT::TIE;

  switch(p1){
    case PLAY::PAPER:
      if(p2 == PLAY::ROCK) return RESULT::WIN;
      return RESULT::LOSS; 
    break;
    case PLAY::ROCK: 
      if(p2 == PLAY::PAPER) return RESULT::LOSS;
      return RESULT::WIN; 
    break;
    case PLAY::SCISSORS:
      if (p2 == PLAY::ROCK) return RESULT::LOSS;
      return RESULT::WIN;
    break;
  }
}

PLAY generate_play(){
  PLAY p = plays[current_play];

  if(current_play == plays.size()-1) 
    current_play = 0;
  
  ++current_play;
  return p;
}

std::string play_to_string(PLAY p){
  switch(p){
    case PLAY::ROCK:
      return "ROCK";
    break;
    case PLAY::PAPER:
      return "PAPER";
    break;
    case PLAY::SCISSORS:
      return "SCISSORS";
    break;
  }
}

std::string char_to_string(const char &p){
  switch(p){
    case rock_char:
      return "ROCK";
    break;
    case paper_char:
      return "PAPER";
    break;
    case scissors_char:
      return "SCISSORS";
    break;
  }
}

PLAY char_to_play(const char &c){
switch(c){
    case rock_char:
      return PLAY::ROCK;
    break;
    case paper_char:
      return PLAY::PAPER;
    break;
    case scissors_char:
      return PLAY::SCISSORS;
    break;
  }
}

void show_result(RESULT r){
  switch(r){
    case RESULT::WIN: 
      std::cout << "You win!" << std::endl;
    break;
  case RESULT::TIE: 
      std::cout << "We tie!" << std::endl;
    break;
  case RESULT::LOSS: 
      std::cout << "You lose!" << std::endl;
    break;
  }
}

bool validate_play (const char &c){
  return c == rock_char || c == paper_char || c == scissors_char;
}

int main(){
  char   user_play {'a'};
  RESULT current_result;
  PLAY   cpu_current_play;
  bool   quit {false};

  std::cout << "===== ROCK, PAPER, SCISSORS" << std::endl;

  while(!quit){
    std::cout << "Type your play: ('r', 'p', 's'): ";
    std::cin >> user_play;
    if(!validate_play(user_play)){
      std::cout << "\nInvalid Input! Program Finished." << std::endl;
      return -1;
    }

    cpu_current_play = generate_play();
    
    std::cout << "You:\t" << char_to_string(user_play) << std::endl;
    std::cout << "Me:\t"  << play_to_string(cpu_current_play) << std::endl;

    current_result = get_result(char_to_play(user_play), cpu_current_play) ;

    show_result(current_result);
  }

  return 0;
}
