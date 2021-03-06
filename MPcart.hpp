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

    // assume we don't have this row in db before, we will insert all of the info into db in the constructor
    MPcart(MyDB* db_cart, string user_id, string cart_id);

    // assume we  have already had this row in db
    MPcart(MyDB* db_cart, string user_id);
    //getter
    string MPcart_getCartID() const;
    string MPcart_getUserID() const;   
    // set the new cart ID based on the original user ID 
    int MPcart_setCartID(const string& newCartId);
    int MPcart_setUserID(const string& newUserId);
};

#endif /* MPcart_hpp */
