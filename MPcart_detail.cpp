#include "MPcart_detail.hpp"

using namespace std;

// assume we don't have this row in db before
MPcart_detail::MPcart_detail(MyDB* db_cart_detail, string cart_detail_id, string cart_id, string product_id, int quantity, string create_time, string modify_time, bool is_del)
:db_cart_detail(db_cart_detail), cart_detail_id(cart_detail_id), cart_id(cart_id), product_id(product_id), quantity(quantity), create_time(create_time), modify_time(modify_time), is_del(is_del) {
    string cmd = "INSERT INTO cart_detail_database VALUES ('" + cart_detail_id + "','" + cart_id + "','" 
    + product_id + "'," + to_string(quantity) + ",";
    
    // SELECT STR_TO_DATE("2017,8,14 10,40,10", "%Y,%m,%d %h,%i,%s");
    cmd += "STR_TO_DATE(\"" + create_time  + "\", \"%Y,%m,%d %h,%i,%s\") , ";
    cmd += "STR_TO_DATE(\"" + modify_time  + "\", \"%Y,%m,%d %h,%i,%s\") , ";
    // 0 = true; 1 = false
    if(is_del) cmd += "'" + to_string(1) + "');";
    else cmd += "'" + to_string(0) + "');";

    if(mysql_query(db_cart_detail->mysql, cmd.c_str())){
        cout << "Error from MPcart_detail constructor!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart_detail->mysql) << endl;
        return;
    }
}

// assume we have already had this row in db
MPcart_detail::MPcart_detail(MyDB* db_cart_detail, string cart_id):db_cart_detail(db_cart_detail), cart_id(cart_id){
    string comd = "SELECT * FROM cart_detail_database WHERE cart_id='" + cart_id + "';"; // assume cart id is unique
    // cout << comd << endl;

    if(mysql_query(db_cart_detail->mysql, comd.c_str())){
        cout << "Error from MPcart_detail constructor!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart_detail->mysql) << endl;
        return;
    }
    db_cart_detail->result = mysql_store_result(db_cart_detail->mysql);
    if(!db_cart_detail->result){
        cout << "Error! Can't retrieve any result from database(MPcart_detail)" << endl;
        return;
    }
    
    int num_rows = mysql_num_rows(db_cart_detail->result);
    if(num_rows > 1){
        cout << "Error! More than one cart have same ID!(MPcart_detail)" << endl;
        return;
    }
    this->db_cart_detail->row = mysql_fetch_row(db_cart_detail->result); // assume the cart_id is unique
    
    // int num_fields = mysql_num_fields(db_cart_detail->result);
    // cout << "fields: " << num_fields << endl;
    // cout << "row[0] " << this->db_cart_detail->row[0] << endl; 
    
    this->cart_detail_id = this->db_cart_detail->row[0];
    this->product_id = this->db_cart_detail->row[2];
    this->quantity = stoi(this->db_cart_detail->row[3]);
    this->create_time = this->db_cart_detail->row[4];
    this->modify_time = this->db_cart_detail->row[5];
    this->is_del = this->db_cart_detail->row[6];
}


int MPcart_detail::MPcart_detail_setCartDetailID(const string& newDetailID){
    string cmd = "UPDATE cart_detail_database SET cart_detail_id = '" + newDetailID + "' WHERE cart_id='" + cart_id + "';";
    // cout << comd << endl;

    if(mysql_query(db_cart_detail->mysql, cmd.c_str())){
        cout << "Error from MPcart_detail setCartDetailID!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart_detail->mysql) << endl;
        return -1;
    }
    this->cart_detail_id = newDetailID;
    db_cart_detail->result = mysql_store_result(db_cart_detail->mysql);
    return 0;
}

int MPcart_detail::MPcart_detail_setCartID(const string& newCartID){
    string cmd = "UPDATE cart_detail_database SET cart_id = '" + newCartID + "' WHERE cart_id='" + cart_id + "';";

    if(mysql_query(db_cart_detail->mysql, cmd.c_str())){
        cout << "Error from MPcart_detail setCartID!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart_detail->mysql) << endl;
        return -1;
    }
    this->cart_id = newCartID;
    db_cart_detail->result = mysql_store_result(db_cart_detail->mysql);
    return 0;
}

int MPcart_detail::MPcart_detail_setProductID(const string& newProductID){
    string cmd = "UPDATE cart_detail_database SET product_id = '" + newProductID + "' WHERE cart_id='" + cart_id + "';";
    if(mysql_query(db_cart_detail->mysql, cmd.c_str())){
        cout << "Error from MPcart_detail setProductID!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart_detail->mysql) << endl;
        return -1;
    }
    this->product_id = newProductID;
    db_cart_detail->result = mysql_store_result(db_cart_detail->mysql);
    return 0;
}

int MPcart_detail::MPcart_detail_setQuantity(const int newQuantity){
    string cmd = "UPDATE cart_detail_database SET quantity = '" + to_string(newQuantity) + "' WHERE cart_id='" + cart_id + "';";
    if(mysql_query(db_cart_detail->mysql, cmd.c_str())){
        cout << "Error from MPcart_detail setQuantity!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart_detail->mysql) << endl;
        return -1;
    }
    this->quantity = newQuantity;
    db_cart_detail->result = mysql_store_result(db_cart_detail->mysql);
    return 0;
}

int MPcart_detail::MPcart_detail_setCreateTime(const string& newCreateTime){
    // be careful with the format: 2020-08-06 00:00:00
    string cmd = "UPDATE cart_detail_database SET create_time = '" + newCreateTime + "' WHERE cart_id='" + cart_id + "';";
    if(mysql_query(db_cart_detail->mysql, cmd.c_str())){
        cout << "Error from MPcart_detail setCreateTime!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart_detail->mysql) << endl;
        return -1;
    }
    this->create_time = newCreateTime;
    db_cart_detail->result = mysql_store_result(db_cart_detail->mysql);
    return 0;
}

int MPcart_detail::MPcart_detail_setModifyTime(const string& newModifyTime){
    // be careful with the format: 2020-08-06 00:00:00
    string cmd = "UPDATE cart_detail_database SET modify_time = '" + newModifyTime + "' WHERE cart_id='" + cart_id + "';";
    if(mysql_query(db_cart_detail->mysql, cmd.c_str())){
        cout << "Error from MPcart_detail setModifyTime!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart_detail->mysql) << endl;
        return -1;
    }
    this->modify_time = newModifyTime;
    db_cart_detail->result = mysql_store_result(db_cart_detail->mysql);
    return 0;
}

int MPcart_detail::MPcart_detail_setIsDel(const bool newDel){
    string str = "1";
    if(!newDel) str = "0";
    string cmd = "UPDATE cart_detail_database SET is_del = '" + str + "' WHERE cart_id='" + cart_id + "';";
    if(mysql_query(db_cart_detail->mysql, cmd.c_str())){
        cout << "Error from MPcart_detail setIsDel!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart_detail->mysql) << endl;
        return -1;
    }
    this->is_del = newDel;
    db_cart_detail->result = mysql_store_result(db_cart_detail->mysql);
    return 0;
}
