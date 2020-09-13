#ifndef MPorder_hpp
#define MPorder_hpp
#include <iostream>
#include <string>
#include "MyDB.hpp"

using namespace std;

class MPorder{
private:
    string order_id;
    string user_id; // len 10,2
    double price;
    string remark;
    string create_time;
    bool is_del; // true if it's deleted
    MyDB* db_order;
    
public:
    // assume we don't have this row in db before
    MPorder(MyDB* db_order, string order_id, string user_id, double price, string remark, string create_time, bool is_del);

    // assume we have already had this row in db
    MPorder(MyDB* db_order, string user_id);

    //getters
    string MPorder_getOrderID() const {return order_id;};
    string MPorder_getUserID() const {return user_id;};
    double MPorder_getPrice() const {return price;};
    string MPorder_remark() const {return remark;};
    string MPorder_getCreateTime() const {return create_time;};
    bool MPorder_getIsDel() const {return is_del;};

    // setters - success returns 0, fail returns -1
    //set new order_id and update new price at the same time
    int MPorder_setOrderID(const string& newOrderID);
    int MPorder_setUserID(const string& newUserID);
    int MPorder_setRemark(const string& newRemark);
    int MPcart_detail_setCreateTime(const string& newCreateTime); // be careful with the format: 2020-08-06 00:00:00
    int MPcart_detail_setIsDel(const bool newDel);
    
};

#endif /* MPorder_hpp */
