#include <iostream>
#include <vector>

#define EXIT_NAME "NoName"
#define EXIT_SCORE 0

class Person{
  public: 
    std::string name;
    unsigned int score;
    Person(std::string n, unsigned int s) : name(n), score(s){}
};

bool validate_name(const std::string &name, const std::vector<Person> &name_list){
  if(name == "") return false;
  for(size_t i = 0; i < name_list.size(); ++i){
    if(name == name_list[i].name) return false;
  }
  
  return true;
}

bool exit_input(const std::string &name, const unsigned int &score){
  return name == EXIT_NAME && score == EXIT_SCORE;
}

bool read_input(std::string &name_input, unsigned int &score_input, std::vector<Person> &name_list){
    std::cout << "Enter a name and a score:";
    std::cin  >> name_input >> score_input;

    if(validate_name(name_input, name_list) && !exit_input(name_input, score_input)){
      Person p = Person(name_input,score_input);
      name_list.push_back(p);
    } else {
      //if(exit_input(name_input, score_input)) return false;
      std::cout << "\nName already exists. Try another one." << std::endl;
      return false;

    }

    return true;
}


void show_data(const std::vector<Person> &name_list){
  for(int i = 0; i < name_list.size(); i++){
    std::cout << name_list[i].name << ":\t" << name_list[i].score << std::endl;
  }
}

void search_by_name(const std::string &name, const std::vector<Person> &name_list){
  for(int i = 0; i < name_list.size(); ++i){
    if (name_list[i].name == name){
      std::cout << std::endl << name_list[i].score << std::endl;
      return;
    }
  }
  
  std::cout << "name not found" << std::endl;
}

void search_by_score(const unsigned int &score, const std::vector<Person> &name_list){
  for(int i = 0; i < name_list.size(); ++i){
    if (name_list[i].score == score){
      std::cout << std::endl << name_list[i].name << std::endl;
      return;
    }
  }
  
  std::cout << "name not found" << std::endl;
}

int main(){
  std::string name_input;
  unsigned int score_input {0};
  bool quit {false};
  int menu_option {1};
  
  std::vector<Person> names;
  
  std::cout << "Enter one of the options below: " << std::endl;
  
  while(menu_option >=1 && menu_option <=3){
    std::cout << "1 : new entry" << std::endl 
            << "2 : search by name" << std::endl 
            << "3 : search by score" << std::endl;

    std::cin >> menu_option;

    switch(menu_option){
      case 1:
        read_input(name_input, score_input, names);
        break;
      case 2: 
        std::cout << "search by name" << std::endl;
        std::cin  >> name_input;
        search_by_name(name_input, names);
        break;
      case 3: 
        std::cout << "search by score" << std::endl;
        std::cin >> score_input;
        search_by_score(score_input, names);
      break;
    }
  }

  show_data(names);
  return 0;
}
