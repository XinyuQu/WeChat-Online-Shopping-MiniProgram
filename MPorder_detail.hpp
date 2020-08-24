#ifndef MPorder_detail_hpp
#define MPorder_detail_hpp
#include <iostream>
#include <string>
#include "MyDB.hpp"

using namespace std;

class MPorder_detail{
private:
    string order_detail_id;
    string order_id;
    string cart_detail;
    double price; // length: 10,2
    MyDB* db_order_detail;

public:
    // assume we don't have this row in db before
    MPorder_detail(MyDB* db_order_detail, string order_detail_id, string order_id, string cart_detail, double price);

    // assume we have already had this row in db
    MPorder_detail(MyDB* db_order_detail, string order_detail_id);


    // getters


    // setters

    

};



#endif