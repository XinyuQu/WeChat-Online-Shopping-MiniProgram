//
//  MPorder.hpp
//  miniProgram
//
//  Created by Xinyu Qu on 6/7/20.
//  Copyright © 2020 Xinyu Qu. All rights reserved.
//

#ifndef MPorder_hpp
#define MPorder_hpp

#include <iostream>
#include <string>
#include "MyDB.hpp"

using namespace std;

class MPorder{
private:
    string order_id;
    string user_id;
    double price; // length 10,2
    string remark;
    string create_time; // format: ""2020,8,6 12,00,00"", "%Y,%m,%d %h,%i,%s"
    bool is_del; // true if it's deleted
    MyDB* db_order;
    
public:
    // assume we don't have this row in db before
    MPorder(MyDB* db_order, string order_id, string user_id, double price, string remark, string create_time, bool is_del);
    
    // assume we have already have this row in db
    MPorder(MyDB* db_order, string order_id);
    

    // getters

    // setters
};

#endif /* MPorder_hpp */
