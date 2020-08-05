#ifndef MPcart_detail_hpp
#define MPcart_detail_hpp
#include <string>
#include "MyDB.hpp"

using namespace std;


class MPcart_detail{
private:
    string cart_detail_id;
    string cart_id;
    string product_id;
    int quantity;
    string create_time;
    string modify_time;
    bool is_del; // true if it's deleted
    MyDB* db_cart_detail;

public:
    MPcart_detail(MyDB* db_cart_detail, string cart_id, string cart_detail_id = "", int quantity = 0, string create_time = "", string modify_time = "", bool is_del = false) 
    : db_cart_detail(db_cart_detail), cart_id(cart_id), cart_detail_id(cart_detail_id), quantity(quantity), create_time(create_time), modify_time(modify_time), is_del(is_del){
        string insert_cmd = "INSERT INTO cart_database"
    }


};





#endif /* MPcart_detail_hpp */
