#pragma once
#include <map>
#include <string>
#include <string.h>
#include "MyDB.hpp"
int add_cart(std::map<std::string, std::string> data, int len, MyDB* db);
int cart_tota(std::map<std::string, std::string> data, int len, MyDB* db);
int merchan_info(std::map<std::string, std::string> data, int len, char* output, MyDB* db);
int nw_order(std::map<std::string, std::string> data, int len, MyDB* db);
int add_user(std::map<std::string, std::string> data, int len, MyDB* db);