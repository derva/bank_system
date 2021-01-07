#pragma once

#include <sys/ioctl.h>
#include <unistd.h> 
#include <iostream>
#include <string>
#include <list>
#include <fstream>

struct Account{
  private:
    std::string first_name{};
    std::string last_name{};
    double money = 0;
    long int pin = 0;
    int id;
  public:
    void search_users();
    void delete_user();
    void with_depo_amount(std::fstream&);
    void modifiy_user();
    void set_FName(std::string f_name){
      first_name = f_name;
    };
    void set_LName(std::string l_name){
      last_name = l_name;
    };
    void set_money(double balance){
      money = balance;
    }
    void set_id(int acc_id){
      id = acc_id;
    }
    void get_info(){
      std::cout << "First name: " << first_name << "\nLast name: " << last_name << "\nMoney: " << money<< std::endl;
    }
};

// FUNCTIONS DECLARATION
void start(int & o);
void createAccount(std::fstream &);
void change();

