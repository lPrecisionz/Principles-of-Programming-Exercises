#include <iostream>
#include <ostream>

#define PENNY_VAL       1
#define NICKEL_VAL      5
#define DIME_VAL        10
#define QUARTER_VAL     25
#define HALFDOLLAR_VAL  50

bool ends_with_y(std::string s){
  return s.back() == 'y';
}

std::string check_plural(std::string s, int *count){
  if (*count > 1){
    if(!ends_with_y(s)){
      return s + 's';
    } else{
      s.pop_back();
      return s + "ies";
    }
  }
      return s;
}

void query_user(int *pennies    , 
                int *nickels    , 
                int *dimes      ,
                int *quarters   ,
                int *half_dollars
                ){

  std::cout << "How many pennies do you have? ";
  std::cin  >> *pennies;

  std::cout << "How many nickels do you have? ";
  std::cin  >> *nickels;

  std::cout << "How many dimes do you have? ";
  std::cin  >> *dimes;

  std::cout << "How many quarters do you have? ";
  std::cin  >> *quarters;

  std::cout << "How many half dollars do you have? ";
  std::cin  >> *half_dollars;

}

void show_user_data(int *pennies , 
                int *nickels    , 
                int *dimes      ,
                int *quarters   ,
                int *half_dollars
){
  
  std::cout << "You have " 
            << *pennies << " " << check_plural("penny", pennies) << std::endl
            << "You have " 
            << *nickels    << " " << check_plural("nickel", nickels)<< " " << std::endl
            << "You have " 
            << *dimes  << " "   << check_plural("dime", dimes) << " " << std::endl
            << "You have " 
            << *quarters << " " << check_plural("quarter", quarters) << " " << std::endl
            << "You have " 
            << *half_dollars << " " << check_plural("half dollar", half_dollars) << std::endl 
            << std::endl;

}

int get_cent_count(int *pennies , 
                int *nickels    , 
                int *dimes      ,
                int *quarters   ,
                int *half_dollars
){
  return  (*pennies      * PENNY_VAL)   +
          (*nickels      * NICKEL_VAL)  + 
          (*dimes        * DIME_VAL)    +
          (*quarters     * QUARTER_VAL) +
          (*half_dollars * HALFDOLLAR_VAL);
}



int main(){

  int pennies      {0}, 
      nickels      {0}, 
      dimes        {0}, 
      quarters     {0}, 
      half_dollars {0};

  int cent_count {0};
  double dollar_count {0};

  query_user(&pennies, 
             &nickels, 
             &dimes, 
             &quarters, 
             &half_dollars
  );

  show_user_data(&pennies, 
             &nickels, 
             &dimes, 
             &quarters, 
             &half_dollars
  );

  cent_count = get_cent_count(&pennies, 
             &nickels, 
             &dimes, 
             &quarters, 
             &half_dollars
);

  dollar_count = static_cast<double>(cent_count) / 100;

  std::cout << "The Value of all of your coins is " 
            << dollar_count 
            << " dollars."
            << std::endl;
  
  return 0;

}
