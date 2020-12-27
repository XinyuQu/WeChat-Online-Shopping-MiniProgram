#include "MPproduct.hpp"
#include <string>

using namespace std;

// constructor

// assume we don't have this row in db before
MPproduct::MPproduct(MyDB* db_product, string product_id, string product_name, string detail, double price, string thumbnail, string create_time, string create_by, string modify_time, string modify_by, bool is_del)
: db_product(db_product), product_id(product_id), product_name(product_name), detail(detail), price(price), thumbnail(thumbnail), create_time(create_time), create_by(create_by), modify_time(modify_time), modify_by(modify_by), is_del(is_del){
    string cmd = "INSERT INTO product_database VALUES ('" + product_id + "','" + product_name + "','" 
    + detail + "'," + to_string(price) + ",'" + thumbnail + "',";
    
    // SELECT STR_TO_DATE("2017,8,14 10,40,10", "%Y,%m,%d %h,%i,%s");
    cmd += "STR_TO_DATE(\"" + create_time  + "\", \"%Y,%m,%d %h,%i,%s\") , ";
    
    cmd += "'" + create_by + "',";

    cmd += "STR_TO_DATE(\"" + modify_time  + "\", \"%Y,%m,%d %h,%i,%s\") , ";

    cmd += "'" + modify_by + "',";

    // 0 = true; 1 = false
    if(is_del) cmd += "'" + to_string(1) + "');";
    else cmd += "'" + to_string(0) + "');";

    if(mysql_query(db_product->mysql, cmd.c_str())){
        cout << "Error from MPproduct constructor!" << endl;
        cout << "Mysql error message: " << mysql_error(db_product->mysql) << endl;
        return;
    }

}

// assume we have already had this row in db
MPproduct::MPproduct(MyDB* db_product, string product_id) : db_product(db_product), product_id(product_id){
    // check if ID exist
    string cmd_check = "SELECT COUNT(*) FROM product_database WHERE product_id='" + product_id + "';"; // assume cart id is unique
    // db_cart_detail->exeSQL(cmd_check);
    if(!db_product->checkID(cmd_check)){
        cout << "in MPproduct constructor!" << endl;
        return;
    }
    
    string comd = "SELECT * FROM product_database WHERE product_id='" + product_id + "';"; // assume cart id is unique
    // cout << comd << endl;

    if(mysql_query(db_product->mysql, comd.c_str())){
        cout << "Error from MPproduct constructor!" << endl;
        cout << "Mysql error message: " << mysql_error(db_product->mysql) << endl;
        return;
    }
    db_product->result = mysql_store_result(db_product->mysql);
    if(!db_product->result){
        cout << "Error! Can't retrieve any result from database(MPproduct)" << endl;
        return;
    }
    
    int num_rows = mysql_num_rows(db_product->result);
    if(num_rows > 1){
        cout << "Error! More than one cart have same ID!(MPproduct)" << endl;
        return;
    }
    this->db_product->row = mysql_fetch_row(db_product->result); // assume the cart_id is unique
    
    // int num_fields = mysql_num_fields(db_cart_detail->result);
    // cout << "fields: " << num_fields << endl;
    // cout << "row[0] " << this->db_cart_detail->row[0] << endl; 
    
    this->product_name = this->db_product->row[1];
    this->detail = this->db_product->row[2];
    this->price = stoi(this->db_product->row[3]);
    this->thumbnail = this->db_product->row[4];
    this->create_time = this->db_product->row[5];
    this->create_by = this->db_product->row[6];
    this->modify_time = this->db_product->row[7];
    this->modify_by = this->db_product->row[8];
    this->is_del = this->db_product->row[9];
}


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