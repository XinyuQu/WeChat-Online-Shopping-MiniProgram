#pragma once
#include <map>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "MyDB.hpp"
#include <iostream>
#include <vector>
#include "MPcart.hpp"
#include "MPcart_detail.hpp"
#include "MPcustomer.hpp"
#include "MPproduct.hpp"
#include "MyDB.hpp"
#include "MPorder.hpp"
#include "MPorder_detail.hpp" 
int add_cart(std::map<std::string, std::string> data, int len, MyDB* db);
int cart_tota(std::map<std::string, std::string> data, int len, MyDB* db);
int merchan_info(std::map<std::string, std::string> data, int len, char* output, MyDB* db);
int nw_order(std::map<std::string, std::string> data, int len, MyDB* db);
int add_user(std::map<std::string, std::string> data, int len, MyDB* db);
