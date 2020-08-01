//
//  MPorder.hpp
//  miniProgram
//
//  Created by Xinyu Qu on 6/7/20.
//  Copyright © 2020 Xinyu Qu. All rights reserved.
//

#ifndef MPorder_hpp
#define MPorder_hpp

#include <stdio.h>
#include <string>

using namespace std;

class MPorder{
private:
    string order_id;
    string user_id;
    double price;
    string remark;
    time_t create_time;
    bool is_del; // true if it's deleted
    
public:
    MPorder(string order_id, string user_id, double price, string remark, time_t create_time, bool is_del):
    order_id(order_id),user_id(user_id),price(price),remark(remark),create_time(create_time),is_del(false){}
    
    int MPorder_delete(string order_id);
    
    int MPorder_getPrice();
    
    
};

#endif /* MPorder_hpp */
