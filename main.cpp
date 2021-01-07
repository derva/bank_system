#include <sys/ioctl.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "functions.hpp"

int main() {
  std::vector<Account> bank_members;
  std::fstream database;

  try {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int option;
    start(option);
    do {
      switch (option) {
        case 1: {
          database.open("database.txt", std::ios::app);
          // bank_members.push_back(createAccount(database));
          createAccount(database);
          database.close();
          break;
        }
        case 2: {
          change();
          // database.open("database.txt", std::ios::in);
          // std::cin.clear();
          // std::cin.ignore();
          // std::cout << "Enter user name: ";
          // std::string user;
          // std::cin >> user;
          // std::string first_name,last_name, money, id;
          // int count{0};
          // while (database >> first_name >> last_name >> money) {
          //   if (user == first_name) {
          //     database>>money;
          //     database>>id;
          //     database>>id;
          //     std::cout <<"INFO: " << "Name: " <<  first_name << " " << last_name << " $"  << money<<" ID: " << id << std::endl;
          //     count++;
          //     if (count == 2) {
          //       throw std::string{"There is more than one users with that ID"};
          //     }
          //     database.open("database.txt", std::ios::app);
          //     std::cout << "Enter money balance: ";
          //     std::string new_money;
          //     std::cin >> new_money;
          //     database <<"Name: " << first_name << " " << last_name << "\tMoney: " << new_money <<"\tID " << id <<std::endl;
          //     database.close();
          //   }
          // }
          // if (count == 0) {
          //   throw std::string{"There is no user with that data"};
          // } 
          // // else {
          // //   with_depo_amount(database);
          // // }
          // database.close();
          break;
        }
        case 5: {
          std::ofstream database("database.txt");
          std::cout << "You are deleted all Your data" << std::endl;
          break;
        }
        case 6: {
          database.open("database.txt", std::ios::in);
          if (database.is_open()) {
            std::string temp;
            while (std::getline(database, temp)) {
              std::cout << temp << std::endl;
              usleep(24000);
            }
          }
          database.close();
          break;
        }
        case 7: {
          std::cout << "Closing program..." << std::endl;
          return 0;
          break;
        }
        default: {
          throw std::string{"Invalid input"};
          break;
        }
      }
      std::cout << "\nIf you want to continue enter Your next option <1 - 7>: ";
      std::cin >> option;
      // }while(option > 0 && option < 8);
    } while (true);
  } catch (std::string e) {
    std::cout << e << std::endl;
  } catch (...) {
    std::cout << "Error, invalid input" << std::endl;
  }
  return 0;
}
