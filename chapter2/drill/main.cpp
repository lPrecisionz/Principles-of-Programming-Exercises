#include "PPPheaders.h"
inline void simple_error(std::string s)	{// write ``error: s and exit program
  std::cerr << "error: " << s << '\n';
	exit(1);
}

int main(){
  int         recipient_age; 
  std::string recipient_name;
  std::string friend_name;
  std::string age_message;
  std::cout << "Enter the name of the person you want to write to: ";
  std::cin >> recipient_name; 
  
  std::cout << std::endl << "Dear " << recipient_name << "," << std::endl 
            << "  How are you? I am fine. I miss you." << std::endl 
            << "  I'm doing this c++ course from scratch, it reminds me of us." << std::endl;

  std::cout << "Now enter the name of your other friend: ";
  std::cin >> friend_name;

  std::cout << std::endl << "   Have you seen " << friend_name << " lately?" << std::endl;

  std::cout << std::endl << "Enter the age of the recipient: ";
  std::cin >> recipient_age;

  if(recipient_age <= 0 || recipient_age >= 110){
    simple_error("you're kidding!");
  }

  std::cout << "  I hear you've just had a birthday and you are " << recipient_age << " years old" << std::endl;

  if(recipient_age < 12){
    std::cout << "  Next year you will be " << recipient_age + 1 << std::endl;
  } else if(recipient_age == 17){
    std::cout << "  Next year you will be able to vote." << std::endl;
  } else if(recipient_age >70 ){
    std::cout << "  Are you retired?" << std::endl;
  }

  std::cout << "  Yours sincerely, " << std::endl << std::endl << "   Pedro" << std::endl;
}
