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

using namespace std;

class MPcart{
private:
    string cart_id;
    string user_id;
    string cart_detail_id;
    vector<MPorder> products;
//    string product_id;
    int quantity;
    time_t create_time;
    time_t modify_time;
    bool is_del; // true if it's deleted
    
public:
    MPcart(string cart_id, string user_id, string cart_detail_id, int quantity, time_t create_time, time_t modify_time, bool is_del) : cart_id(cart_id), user_id(user_id), cart_detail_id(cart_detail_id), quantity(quantity), create_time(create_time), modify_time(modify_time), is_del(false){}
    
    int MPcart_delete(string customer_id);
    
    double MPcart_totalPrice(string customer_id);

};

#endif /* MPcart_hpp */
