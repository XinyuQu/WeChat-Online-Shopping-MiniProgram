#include "MPorder.hpp"
#include <string>

using namespace std;//

// assume we don't have this row in db before
MPorder::MPorder(MyDB* db_order, string order_id, string user_id, double price, string remark, string create_time, bool is_del)
:db_order(db_order), order_id(order_id), user_id(user_id), price(price), create_time(create_time), is_del(is_del) {
    string cmd = "INSERT INTO order_database VALUES ('" + order_id + "','" + user_id + "','" + to_string(price) + ",";
    
    // SELECT STR_TO_DATE("2017,8,14 10,40,10", "%Y,%m,%d %h,%i,%s");
    cmd += "STR_TO_DATE(\"" + create_time  + "\", \"%Y,%m,%d %h,%i,%s\") , ";
    // 0 = true; 1 = false
    if(is_del) cmd += "'" + to_string(1) + "');";
    else cmd += "'" + to_string(0) + "');";

    if(mysql_query(db_order->mysql, cmd.c_str())){
        cout << "Error from MPorder constructor!" << endl;
        cout << "Mysql error message: " << mysql_error(db_order->mysql) << endl;
        return;
    }
}

// assume we have already had this row in db
MPorder::MPorder(MyDB* db_order, string user_id):db_order(db_order), user_id(user_id){
    string comd = "SELECT * FROM order_database WHERE user_id='" + user_id + "';"; // assume user id is unique

    if(mysql_query(db_order->mysql, comd.c_str())){
        cout << "Error from MPorder constructor!" << endl;
        cout << "Mysql error message: " << mysql_error(db_order->mysql) << endl;
        return;
    }
    db_order->result = mysql_store_result(db_order->mysql);
    if(!db_order->result){
        cout << "Error! Can't retrieve any result from database(MPorder)" << endl;
        return;
    }
    
    int num_rows = mysql_num_rows(db_order->result);
    if(num_rows > 1){
        cout << "Error! More than one user have same ID!(MPorder)" << endl;
        return;
    }
    this->db_order->row = mysql_fetch_row(db_order->result); // assume the user_id is unique
    this->order_id = this->db_order->row[0];
    this->price = stod(this->db_order->row[2]);
    this->remark = this->db_order->row[3];
    this->create_time = this->db_order->row[4];
    this->is_del = this->db_order->row[5];
}

int MPorder::MPorder_setOrderID(const string& newOrderID){
    //get each single price from order_detail to sum up for new total price with the new orderid accordingly 
    string comd = "SELECT * FROM order_detail_database WHERE order_id='" + newOrderID + "';";
    double totalprice = 0;
    if(mysql_query(db_order->mysql, comd.c_str())){
        cout << "Error from MPorder setOrderID getting price with order_id from order_detail_databse!" << endl;
        cout << "Mysql error message: " << mysql_error(db_order->mysql) << endl;
        return -1;
    }
    db_order->result = mysql_store_result(db_order->mysql);
    if(!db_order->result){
        cout << "Error! Can't retrieve any result from order_detail_database(MPorder setOrderID)" << endl;
        return;
    }
    int num_rows=mysql_num_rows(db_order->result);
    for(int i=0;i<num_rows;i++)
        {
            db_order->row=mysql_fetch_row(db_order->result);
            if(db_order->row == NULL) break;
            totalprice += db_order->row[3]
        }
    this->price = totalprice;

    //set order_id in order_database
    string cmd = "UPDATE order_database SET order_id = '" + newOrderID + "' WHERE user_id='" + user_id + "';";
    if(mysql_query(db_order->mysql, cmd.c_str())){
        cout << "Error from MPorder setOrderID!" << endl;
        cout << "Mysql error message: " << mysql_error(db_order->mysql) << endl;
        return -1;
    }
    this->order_id = newOrderID;
   
    db_order->result = mysql_store_result(db_order->mysql);
    return 0;
}


int MPorder::MPorder_setUserID(const string& newUserID){
    string cmd = "UPDATE order_database SET user_id = '" + newUserID + "' WHERE user_id='" + user_id + "';";

    if(mysql_query(db_order->mysql, cmd.c_str())){
        cout << "Error from MPorder setUserID!" << endl;
        cout << "Mysql error message: " << mysql_error(db_order->mysql) << endl;
        return -1;
    }
    this->user_id = newUserID;
    db_order->result = mysql_store_result(db_order->mysql);
    return 0;
}

int MPorder::MPorder_setRemark(const string& newRemark){
    string cmd = "UPDATE order_database SET remark = '" + newRemark + "' WHERE user_id='" + user_id + "';";

    if(mysql_query(db_order->mysql, cmd.c_str())){
        cout << "Error from MPorder setRemark!" << endl;
        cout << "Mysql error message: " << mysql_error(db_order->mysql) << endl;
        return -1;
    }
    this->remark = newRemark;
    db_order->result = mysql_store_result(db_order->mysql);
    return 0;
}

int MPorder::MPorder_setCreateTime(const string& newCreateTime){
    // be careful with the format: 2020-08-06 00:00:00
    string cmd = "UPDATE order_database SET create_time = '" + newCreateTime + "' WHERE user_id='" + user_id + "';";
    if(mysql_query(db_order->mysql, cmd.c_str())){
        cout << "Error from MPorder setCreateTime!" << endl;
        cout << "Mysql error message: " << mysql_error(db_order->mysql) << endl;
        return -1;
    }
    this->create_time = newCreateTime;
    db_order->result = mysql_store_result(db_order->mysql);
    return 0;
}

int MPorder::MPorder_setIsDel(const bool newDel){
    string str = "1";
    if(!newDel) str = "0";
    string cmd = "UPDATE order_database SET is_del = '" + str + "' WHERE user_id='" + user_id + "';";
    if(mysql_query(db_order->mysql, cmd.c_str())){
        cout << "Error from MPorder setIsDel!" << endl;
        cout << "Mysql error message: " << mysql_error(db_order->mysql) << endl;
        return -1;
    }
    this->is_del = newDel;
    db_order->result = mysql_store_result(db_order->mysql);
    return 0;
}
