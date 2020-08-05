//
//  MPcart.cpp
//  miniProgram
//
//  Created by Xinyu Qu on 6/7/20.
//  Copyright © 2020 Xinyu Qu. All rights reserved.
//

#include "MPcart.hpp"

using namespace std;


//     // assume we have private member for cart_id
// string MPcart::MPcart_getCartID() const{
//     // string comd = "SELECT * FROM cart_database WHERE user_id='" + user_id + "';"; // assume cart id is unique
//     // // cout << comd << endl;

//     // if(mysql_query(db_cart->mysql, comd.c_str())){
//     //     cout << "Error from MPcart_getCartID!" << endl;
//     //     return "";
//     // }
//     // db_cart->result = mysql_store_result(db_cart->mysql);
//     // return mysql_fetch_row(db_cart->result)[0];
// }

MPcart::MPcart(MyDB* db_cart, string user_id) 
: db_cart(db_cart), user_id(user_id){
    string comd = "SELECT * FROM cart_database WHERE user_id='" + user_id + "';"; // assume cart id is unique
    // cout << comd << endl;

    if(mysql_query(db_cart->mysql, comd.c_str())){
        cout << "Error from MPcart constructor!" << endl;
        return;
    }
    db_cart->result = mysql_store_result(db_cart->mysql);
    cart_id = mysql_fetch_row(db_cart->result)[0];
}


string MPcart::MPcart_getCartID() const {return cart_id;}
string MPcart::MPcart_getUserID() const {return user_id;}
