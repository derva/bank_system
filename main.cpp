#include <sys/ioctl.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "functions.hpp"

int main() {
  std::fstream database;

  try {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int option;
    // label: details;
    DETAILS:start(option);
    do {
      switch (option) {
        case 1: {
          createAccount();
          break;
        }
        case 2: {
          change();
          break;
        }
        case 3: {
          print_all();
          break;
        }
        case 4: {
          std::ofstream database("database.txt");
          std::cout << "You are deleted all Your data" << std::endl;
          break;
        }
        case 5:
          goto DETAILS;
        case 6: {
          std::cout << "Closing program..." << std::endl;
          usleep(5000);
          return 0;
          break;
        }
        default: {
          throw std::string{
              "Invalid input, please enter number between <1 - 5>"};
          break;
        }
      }
      std::cout << "\nIf you want to continue enter Your next option <1 - 6>: ";
      std::cin >> option;
    } while (true);
  } catch (std::string e) {
    std::cout << e << std::endl;
  } catch (...) {
    std::cout << "Error, invalid input" << std::endl;
  }
  return 0;
}
