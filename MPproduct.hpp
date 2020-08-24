#ifndef MPproduct_hpp
#define MPproduct_hpp
#include <iostream>
#include <string>
#include "MyDB.hpp"
using namespace std;

class MPproduct
{
  private:
    string product_id;
    string product_name;
    string detail;
    double price; // length: 10,2
    string thumbnail;
    string create_time; // format: ""2020,8,6 12,00,00"", "%Y,%m,%d %h,%i,%s"
    string create_by;
    string modify_time; // format: ""2020,8,6 12,00,00"", "%Y,%m,%d %h,%i,%s"
    string modify_by;      
    bool is_del; // true if it's deleted (1)
    MyDB* db_product;

  public:
    // assume we don't have this row in db before
    MPproduct(MyDB* db_product, string product_id, string product_name, string detail, double price, string thumbnail, string create_time, string create_by, string modify_time, string modify_by, bool is_del);

    // assume we have already had this row in db
    MPproduct(MyDB* db_product, string product_id);

    // getters
    string MPproduct_getProductID() const {return product_id;}
    string MPproduct_getProductName() const {return product_name;}
    string MPproduct_getDetail() const {return detail;}
    double MPproduct_getPrice() const {return price;}
    string MPproduct_getThumbnail() const {return thumbnail;}
    string MPproduct_getCreateTime() const {return create_time;}
    string MPproduct_getCreateBy() const {return create_by;}
    string MPproduct_getModifyTime() const {return modify_time;}
    string MPproduct_getModifyBy() const {return modify_by;}
    bool MPproduct_getIsDel() const {return is_del;}

    //setters

  
};
#endif