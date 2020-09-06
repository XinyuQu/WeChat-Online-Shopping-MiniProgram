#include "MPproduct.hpp"
#include <string>

using namespace std;

// setters that use product id to search in database; success returns 0, fail returns -1
int MPproduct::MPproduct_setProductID(const string& str){
    string cmd = "UPDATE product_database SET product_id = '" + str + "' WHERE product_id='" + product_id + "';";
    // cout << comd << endl;

    if(mysql_query(db_product->mysql, cmd.c_str())){
        cout << "Error from MPproduct setProductID!" << endl;
        cout << "Mysql error message: " << mysql_error(db_product->mysql) << endl;
        return -1;
    }
    this->product_id = str;
    db_product->result = mysql_store_result(db_product->mysql);
    return 0;
}
int MPproduct::MPproduct_setProductName(const string& str){
    string cmd = "UPDATE product_database SET product_name = '" + str + "' WHERE product_id='" + product_id + "';";

    if(mysql_query(db_product->mysql, cmd.c_str())){
        cout << "Error from MPproduct setProductName!" << endl;
        cout << "Mysql error message: " << mysql_error(db_product->mysql) << endl;
        return -1;
    }
    this->product_name = str;
    db_product->result = mysql_store_result(db_product->mysql);
    return 0;
}
int MPproduct::MPproduct_setDetail(const string& str){
    string cmd = "UPDATE product_database SET detail = '" + str + "' WHERE product_id='" + product_id + "';";

    if(mysql_query(db_product->mysql, cmd.c_str())){
        cout << "Error from MPproduct setDetail!" << endl;
        cout << "Mysql error message: " << mysql_error(db_product->mysql) << endl;
        return -1;
    }
    this->detail = str;
    db_product->result = mysql_store_result(db_product->mysql);
    return 0;
}
int MPproduct::MPproduct_setPrice(const int num){
    string cmd = "UPDATE product_database SET price = '" + to_string(num) + "' WHERE product_id='" + product_id + "';";
    // cout << comd << endl;

    if(mysql_query(db_product->mysql, cmd.c_str())){
        cout << "Error from MPproduct setPrice!" << endl;
        cout << "Mysql error message: " << mysql_error(db_product->mysql) << endl;
        return -1;
    }
    this->price = num;
    db_product->result = mysql_store_result(db_product->mysql);
    return 0;
}
int MPproduct::MPproduct_setThumbnail(const string& str){
    string cmd = "UPDATE product_database SET thumbnail = '" + str + "' WHERE product_id='" + product_id + "';";

    if(mysql_query(db_product->mysql, cmd.c_str())){
        cout << "Error from MPproduct setThumbnail!" << endl;
        cout << "Mysql error message: " << mysql_error(db_product->mysql) << endl;
        return -1;
    }
    this->thumbnail = str;
    db_product->result = mysql_store_result(db_product->mysql);
    return 0;
}
int MPproduct::MPproduct_setCreateTime(const string& str){// be careful with the format: 2020-08-06 00:00:00
    string cmd = "UPDATE product_database SET create_date = '" + str + "' WHERE product_id='" + product_id + "';";

    if(mysql_query(db_product->mysql, cmd.c_str())){
        cout << "Error from MPproduct setCreateTime!" << endl;
        cout << "Mysql error message: " << mysql_error(db_product->mysql) << endl;
        return -1;
    }
    this->create_time = str;
    db_product->result = mysql_store_result(db_product->mysql);
    return 0;

}
int MPproduct::MPproduct_setCreateBy(const string& str){
    string cmd = "UPDATE product_database SET create_by = '" + str + "' WHERE product_id='" + product_id + "';";

    if(mysql_query(db_product->mysql, cmd.c_str())){
        cout << "Error from MPproduct setCreateBy!" << endl;
        cout << "Mysql error message: " << mysql_error(db_product->mysql) << endl;
        return -1;
    }
    this->create_by = str;
    db_product->result = mysql_store_result(db_product->mysql);
    return 0;
}
int MPproduct::MPproduct_setModifyTime(const string& str){ // be careful with the format: 2020-08-06 00:00:00
    string cmd = "UPDATE product_database SET modify_date = '" + str + "' WHERE product_id='" + product_id + "';";
    // cout << comd << endl;

    if(mysql_query(db_product->mysql, cmd.c_str())){
        cout << "Error from MPproduct setModifyTime!" << endl;
        cout << "Mysql error message: " << mysql_error(db_product->mysql) << endl;
        return -1;
    }
    this->modify_time = str;
    db_product->result = mysql_store_result(db_product->mysql);
    return 0;

}
int MPproduct::MPproduct_setModifyBy(const string& str){
    string cmd = "UPDATE product_database SET modify_by = '" + str + "' WHERE product_id='" + product_id + "';";
    // cout << comd << endl;

    if(mysql_query(db_product->mysql, cmd.c_str())){
        cout << "Error from MPproduct setProductID!" << endl;
        cout << "Mysql error message: " << mysql_error(db_product->mysql) << endl;
        return -1;
    }
    this->modify_by = str;
    db_product->result = mysql_store_result(db_product->mysql);
    return 0;
}
int MPproduct::MPproduct_setIsDel(const bool newDel){
    string str = "1";
    if(!newDel) str = "0";
    string cmd = "UPDATE product_database SET is_del = '" + str + "' WHERE cart_id='" + product_id + "';";
    if(mysql_query(db_product->mysql, cmd.c_str())){
        cout << "Error from MPproduct setIsDel!" << endl;
        cout << "Mysql error message: " << mysql_error(db_product->mysql) << endl;
        return -1;
    }
    this->is_del = newDel;
    db_product->result = mysql_store_result(db_product->mysql);
    return 0;
}