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
    string create_time; // format: "2017,8,14 10,40,10", "%Y,%m,%d %h,%i,%s"
    string modify_time;
    bool is_del; // true if it's deleted
    MyDB* db_cart_detail;

public:

    // assume we don't have this row in db before
    MPcart_detail(MyDB* db_cart_detail, string cart_detail_id, string cart_id, string product_id, int quantity, string create_time, string modify_time, bool is_del);

    // assume we have already had this row in db
    MPcart_detail(MyDB* db_cart_detail, string cart_id);

    string MPcart_detail_geCartDetailID() const {return cart_detail_id;};
    string MPcart_detail_getCartID() const {return cart_id;};
    string MPcart_detail_getProductID() const {return product_id;};
    int MPcart_detail_getQuantity() const {return quantity;};
    string MPcart_detail_getCreateTime() const {return create_time;};
    string MPcart_detail_getModifyTime() const {return modify_time;};
    bool MPcart_detail_getIsDel() const {return is_del;};
};





#endif /* MPcart_detail_hpp */
