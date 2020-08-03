//
//  MPcart.cpp
//  miniProgram
//
//  Created by Xinyu Qu on 6/7/20.
//  Copyright © 2020 Xinyu Qu. All rights reserved.
//

#include "MPcart.hpp"

using namespace std;

int MPcart::MPcart_delete(string customer_id){
    if(!is_del){
        is_del = true;
        return 0;
    }else return -1;
}

// double MPcart::MPcart_totalPrice(string customer_id){
//     double totalPrice = 0;
//     for(MPorder order : products) totalPrice += order.MPorder_getPrice();
    
//     return totalPrice;
    
// }


string MPcart::MPcart_getUserID(){
    // string comd = "SELECT user_id from cart_database where cart_id=" + cart_id;
    string comd = "SELECT user_id from cart_database;";
    if(mysql_query(db_cart.mysql, comd.c_str())){
        cout << "Error!" << endl;
        return "";
    }
    db_cart.result = mysql_store_result(db_cart.mysql);
    return mysql_fetch_row(db_cart.result)[0];
    // cout << "Success" << endl;
    // cout << "Hello" << endl;
    // return "Y";
}

