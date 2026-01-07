#include <cctype>
#include <iostream>
#include <vector>

constexpr int WEEK_DAY_COUNT {7};

constexpr int SUNDAY    {0};
constexpr int MONDAY    {1};
constexpr int TUESDAY   {2};
constexpr int WEDNESDAY {3};
constexpr int THURSDAY  {4};
constexpr int FRIDAY    {5};
constexpr int SATURDAY  {6};
constexpr int INVALID_WEEKDAY   {-1};

const std::vector<std::string> week_days {
  "sunday",
  "monday", 
  "tuesday", 
  "wednesday", 
  "thursday", 
  "friday", 
  "saturday"
};

std::string to_lower(const std::string &s){
  if(s.size() == 0) return "";

  std::string lowered_string;
  for(char s : s){
    lowered_string.push_back(std::tolower(s));
  }

  return lowered_string;
}

int weekday_index(const std::string &weekday){
  std::string lowered_weekday {to_lower(weekday)};
  if(lowered_weekday == "sun" || lowered_weekday == "sunday")    return SUNDAY;
  if(lowered_weekday == "mon" || lowered_weekday == "monday")    return MONDAY;
  if(lowered_weekday == "tue" || lowered_weekday == "tuesday")   return TUESDAY;
  if(lowered_weekday == "wed" || lowered_weekday == "wednesday") return WEDNESDAY;
  if(lowered_weekday == "thu" || lowered_weekday == "thursday")  return THURSDAY;
  if(lowered_weekday == "fri" || lowered_weekday == "friday")    return FRIDAY;
  if(lowered_weekday == "sat" || lowered_weekday == "saturday")  return SATURDAY;

  return INVALID_WEEKDAY;
}

bool find_weekday(const std::string &weekday){
  for(std::string s : week_days){
    if (to_lower(s) == to_lower(weekday))
      return true;
  }
  return false;
}

bool is_weekday_valid(const std::string &weekday){
  return find_weekday(weekday);
}

void read_input(std::vector<std::string> &weekdays, std::vector<int> &scores){
  std::string weekday_buffer {};
  int         score_buffer   {};

  while(std::cin >> weekday_buffer >> score_buffer){
    weekdays.push_back(weekday_buffer);
    scores.push_back  ( score_buffer );
  }
}

std::vector<int> get_weekday_scores(const std::vector<std::string> &weekday_inputs, const std::vector<int> &scores){
  std::vector<int> weekday_scores (WEEK_DAY_COUNT);
  for(size_t i = 0; i < weekday_inputs.size(); ++i){
    int curr_weekday = weekday_index(weekday_inputs[i]);
    if(curr_weekday != INVALID_WEEKDAY){
      weekday_scores[curr_weekday] += scores[i];
    }
  }
  return weekday_scores;
}

int count_invalid(std::vector<std::string> &weekday_inputs){
  int invalid {0};
  for(size_t i = 0; i < weekday_inputs.size(); ++i){
    int curr_weekday = weekday_index(weekday_inputs[i]);
    if(curr_weekday == INVALID_WEEKDAY){
      ++invalid;
    }
  }

  return invalid;
}

void show_values(const std::vector<int> &weekday_scores){
  std::cout << "Values: " << std::endl;
  for(size_t i = 0; i < WEEK_DAY_COUNT; ++i){
    std::cout << week_days[i] << ":\t" << weekday_scores[i] << std::endl;
  }
}

void show_invalid(std::vector<std::string> &weekdays_input){
  std::cout <<"\nInvalid days:" << count_invalid(weekdays_input) << std::endl;
}

int main(){
  std::vector<std::string> weekdays_input;
  std::vector<int> scores_input;

  read_input(weekdays_input, scores_input);
  std::vector<int> weekday_scores = get_weekday_scores(weekdays_input, scores_input);
  
  show_values(weekday_scores);
  show_invalid(weekdays_input);

  return 0;
}
