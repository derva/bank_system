#include "functions.hpp"
#include <iostream>

extern int users_id;

void start(int& o) {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  auto first_line_length = w.ws_col;
  // auto console_height = w.ws_row;
  // std::string clear_console(2, '\n');
  std::string print_line(first_line_length, '*');
  std::string print_main(first_line_length / 2 - 6, '*');
  std::string print_free_space(first_line_length / 2 - 7, '*');
  std::cout << print_free_space << " BANK  SYSTEM " << print_free_space
            << std::endl;
  std::cout << "Version 0.0.1\t |\nderva" << std::endl;
  std::cout << print_line << std::endl;
  std::cout << std::endl;
  std::cout << print_line << std::endl;
  std::cout << print_main << " MAIN  MENU " << print_main << std::endl;
  std::cout << print_line << std::endl;
  std::cout << std::endl;
  std::cout << "OPTIONS: " << std::endl;
  std::cout << "\t1. CREATE NEW ACCOUNT "
            << "\n\t2. EDIT USER INFO "
            << "\n\t3. DELETE ALL USERS"
            << "\n\t4. PRINT ALL USERS "
            << "\n\t5. CLOSE" << std::endl;
  std::cout << "Select Your option <1 - 6>: ";
  std::cin >> o;
}

void createAccount(std::fstream& database) {
  Account newAcc;
  std::string f_name;
  std::string l_name;
  std::cout << "*CREATE NEW ACCOUNT*\nEnter First Name: " << std::endl;
  std::cin.clear();
  std::cin.ignore();
  std::getline(std::cin, f_name);
  // newAcc.set_FName(f_name);
  std::cout << "Enter Last Name: " << std::endl;
  // std::cin.clear();
  // std::cin.ignore();
  std::getline(std::cin, l_name);
  // newAcc.set_LName(l_name);
  std::cout << "Enter Money Balance: " << std::endl;
  double money;
  std::cin >> money;
  if (!(std::cin) || money < 0){
    throw std::string{"Invalid input - money must be positive number"};
  }
  // newAcc.set_money(money);
  std::cout << "Enter ID for user: " << std::endl;
  int id;
  std::cin >> id;
  if (!(std::cin) || id < 0) {
    throw std::string{"Invalid input"};
  }
  newAcc.set_id(id);
  std::cin.clear();
  std::cin.ignore();
  std::cout << "You are successful enter new user in our base!" << std::endl;
  database << f_name << " " << l_name << " " << money << " " << id << std::endl;
  // return newAcc;
}

void change() {
  std::fstream temp_base, database;
  database.open("database.txt", std::ios::in);
  temp_base.open("database2.txt", std::ios::out);
  std::cout << "\n- You are now editing user info -\nName of user whose data "
               "you want to change\nName: ";
  std::string name;
  std::cin >> name;
  std::string first_name, last_name, money, id;

  while (database >> first_name >> last_name >> money >> id) {
    if (name == first_name) {
      int option;
      std::cout << "What do you want to change? " << std::endl;
      std::cout << "\t1.Name\n\t2.Last name\n\t3.Money\n\t4.ID\n\t5.Delete user" << std::endl;
      std::cout << "Enter option: ";
      std::cin >> option;
      switch (option) {
        case 1:
          std::cout << "Enter user new first name: ";
          std::cin >> first_name;
          temp_base << first_name << " " << last_name << " " << money << " "
                    << id << std::endl;
          break;
        case 2:
          std::cout << "Enter user new last name: ";
          std::cin >> last_name;
          temp_base << first_name << " " << last_name << " " << money << " "
                    << id << std::endl;
          break;
        case 3:
          std::cout << "Enter user new money balance: ";
          std::cin >> money;
          temp_base << first_name << " " << last_name << " " << money << " "
                    << id << std::endl;
          break;
        case 4:
          std::cout << "Enter user new id: ";
          std::cin >> id;
          temp_base << first_name << " " << last_name << " " << money << " "
                    << id << std::endl;
          break;
        case 5: 
          std::cout << "Deleted" << std::endl;
          break;
      }
    } else if (name != first_name) {
      temp_base << first_name << " " << last_name << " " << money << " " << id << std::endl;
    }
  }
  database.close();
  temp_base.close();
  database.open("database.txt", std::ios::out);
  temp_base.open("database2.txt", std::ios::in);
  while (temp_base >> first_name >> last_name >> money >> id) {
    database << first_name << " " << last_name << " " << money << " " << id
             << std::endl;
  }
  temp_base.close();
  database.close();
}
void print_all() {
  std::fstream database;
  database.open("database.txt", std::ios::in);
  if (database.is_open()) {
    std::string f_name,l_name,money,id;
    while (database >> f_name >> l_name >> money >> id) {
      std::cout << "Name: " << f_name << " " << l_name << " \t| Money: " << money <<"$" <<  std::endl;
      // std::cout << "Money: " << money << std::endl;
      usleep(24000);
    }
  }
  database.close();
}
// void Account::with_depo_amount(std::fstream& database){ std::cout << "Enter
// ID of Account: ";
//   std::string id;
//   std::cin >> id;
//   database.open("database.txt", std::ios::in);
//   std::string user;
//   int count{0};
//   while(database >> user){
//     if(user == id){
//       std::cout << user << std::endl;
//       count++;
//       if(count == 2){
//         throw std::string{"There is more than one users with that ID"};
//       }
//     }
//   }
//   std::cout << "Enter how much money you want to store: " << std::endl;
//   double balance;
//   std::cin >> balance;
//
// }
