//
//  MPcart.hpp
//  miniProgram
//
//  Created by Xinyu Qu on 6/7/20.
//  Copyright © 2020 Xinyu Qu. All rights reserved.
//

#ifndef MPcart_hpp
#define MPcart_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "MPorder.hpp"
#include "MyDB.hpp"

using namespace std;

class MPcart{
private:
    string cart_id;
    string user_id;
    string cart_detail_id;
    vector<MPorder> products;
//    string product_id;
    int quantity;
    string create_time;
    string modify_time;
    bool is_del; // true if it's deleted
    MyDB* db_cart;


public:
    MPcart(MyDB* db_cart, string cart_id = "", string user_id = "", string cart_detail_id = "", int quantity = 0, string create_time = "", string modify_time = "", bool is_del = false) 
    : db_cart(db_cart), cart_id(cart_id), user_id(user_id), cart_detail_id(cart_detail_id), quantity(quantity), create_time(create_time), modify_time(modify_time), is_del(is_del){}
    
    string MPcart_getUserID();
    int MPcart_delete(string customer_id);
    
    // double MPcart_totalPrice(string customer_id);

};

#endif /* MPcart_hpp */
