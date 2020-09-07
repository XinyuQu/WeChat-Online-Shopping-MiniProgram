#ifndef MPorder_detail_hpp
#define MPorder_detail_hpp
#include <iostream>
#include <string>
#include "MyDB.hpp"
//#include "MPcart_detail.hpp"
#include "MPproduct.hpp"

using namespace std;

class MPorder_detail{
private:
    string order_detail_id;
    string order_id;
    string cart_detail_id;
    double price; // length: 10,2
    MyDB* db_order_detail;

public:
    // assume we don't have this row in db before
    MPorder_detail(MyDB* db_order_detail, string order_detail_id, string order_id, string cart_detail_id, double price);

    // assume we have already had this row in db
    MPorder_detail(MyDB* db_order_detail, string order_id);

    //getters
    string MPorder_detail_getOrderDetailID() const {return order_detail_id;}
    string MPorder_detail_getOrderID() const {return order_id;}
    string MPorder_detail_getCartDetail() const {return cart_detail_id;}
    double MPorder_detail_getPrice() const {return price;}


    // setters that use cart id to search in database; success returns 0, fail returns -1
    int MPorder_detail_setOrderDetailID(const string& newDetailID);
    int MPorder_detail_setOrderID(const string& newOrderID);
    //set new cart_detail_id and update price at the same time
    int MPorder_detail_setCartDetailID(const string& newCartDetailID);

};



#endif