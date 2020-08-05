//
//  MPcart.hpp
//  miniProgram
//
//  Created by Xinyu Qu on 6/7/20.
//  Copyright © 2020 Xinyu Qu. All rights reserved.
//

#ifndef MPcart_hpp
#define MPcart_hpp

#include <iostream>
#include <string>
#include "MyDB.hpp"

using namespace std;

class MPcart{
private:
    string user_id;
    string cart_id;
    MyDB* db_cart;

public:
    // 至少要有user id
    MPcart(MyDB* db_cart, string user_id);
    //getter
    string MPcart_getCartID() const;
    string MPcart_getUserID() const;    
};

#endif /* MPcart_hpp */
