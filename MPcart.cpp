//
//  MPcart.cpp
//  miniProgram
//
//  Created by Xinyu Qu on 6/7/20.
//  Copyright © 2020 Xinyu Qu. All rights reserved.
//

#include "MPcart.hpp"

using namespace std;

MPcart::MPcart(MyDB* db_cart, string user_id, string cart_id):db_cart(db_cart), user_id(user_id), cart_id(cart_id){
    // need to write exception case when the user_id is actually not in db
    string cmd = "INSERT INTO cart_database VALUES ('" + cart_id + "','" + user_id + "');";
    if(mysql_query(db_cart->mysql, cmd.c_str())){
        cout << "Error from MPcart constructor!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart->mysql) << endl;
        return;
    }
}


MPcart::MPcart(MyDB* db_cart, string user_id) 
: db_cart(db_cart), user_id(user_id){
    string comd = "SELECT * FROM cart_database WHERE user_id='" + user_id + "';"; // assume cart id is unique

    if(mysql_query(db_cart->mysql, comd.c_str())){
        cout << "Error from MPcart constructor!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart->mysql) << endl;
        return;
    }
    db_cart->result = mysql_store_result(db_cart->mysql);
        if(!db_cart->result){
        cout << "Error! Can't retrieve any result from database (MPcart)" << endl;
        return;
    }
    
    int num_rows = mysql_num_rows(db_cart->result);
    if(num_rows > 1){
        cout << "Error! More than one User have same ID! (MPcart)" << endl;
        return;
    }
    this->db_cart->row = mysql_fetch_row(db_cart->result); // assume user_id is unique
    this->cart_id = this->db_cart->row[0];
}


string MPcart::MPcart_getCartID() const {return cart_id;}
string MPcart::MPcart_getUserID() const {return user_id;}

int MPcart::MPcart_setCartID(const string& newCartId){
    string cmd = "UPDATE cart_database SET cart_id = '" + newCartId + "' WHERE user_id='" + user_id + "';";
    // cout << comd << endl;

    if(mysql_query(db_cart->mysql, cmd.c_str())){
        cout << "Error from MPcart setCartID!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart->mysql) << endl;
        return -1;
    }
    this->cart_id = newCartId;
    db_cart->result = mysql_store_result(db_cart->mysql);
    return 0;
    //cart_id = mysql_fetch_row(db_cart->result)[0];
}


int MPcart::MPcart_setUserID(const string& newUserId){
    string cmd = "UPDATE cart_database SET user_id = '" + newUserId + "' WHERE user_id='" + user_id + "';";
    // cout << comd << endl;

    if(mysql_query(db_cart->mysql, cmd.c_str())){
        cout << "Error from MPcart setCartID!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart->mysql) << endl;
        return -1;
    }
    this->user_id = newUserId;
    db_cart->result = mysql_store_result(db_cart->mysql);
    return 0;
}

