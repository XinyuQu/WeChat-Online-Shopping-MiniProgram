#include "MPcustomer.hpp"
using namespace std;



MPcustomer::MPcustomer(MyDB* db_customer, string user_id, string user_name, string phone, string email, short sex, string create_time, bool is_del)
:db_customer(db_customer), user_id(user_id), user_name(user_name), phone(phone), email(email), sex(sex), create_time(create_time), is_del(is_del){
    string cmd = "INSERT INTO user_database VALUES ('" + user_id + "','" + user_name + "','" 
    + phone + "','" + email + "'," + to_string(sex) + ",";
    
    // SELECT STR_TO_DATE("2017,8,14 10,40,10", "%Y,%m,%d %h,%i,%s");
    cmd += "STR_TO_DATE(\"" + create_time  + "\", \"%Y,%m,%d %h,%i,%s\") , ";
    // 0 = true; 1 = false
    if(is_del) cmd += "'" + to_string(1) + "');";
    else cmd += "'" + to_string(0) + "');";

    if(mysql_query(db_customer->mysql, cmd.c_str())){
        cout << "Error from MPcustomer constructor!" << endl;
        cout << "Mysql error message: " << mysql_error(db_customer->mysql) << endl;
        return;
    }
}
MPcustomer::MPcustomer(MyDB* db_customer, string user_id): db_customer(db_customer), user_id(user_id){
    string comd = "SELECT * FROM user_database WHERE user_id='" + user_id + "';"; // assume cart id is unique

    if(mysql_query(db_customer->mysql, comd.c_str())){
        cout << "Error from MPcustomer constructor!" << endl;
        cout << "Mysql error message: " << mysql_error(db_customer->mysql) << endl;
        return;
    }

    db_customer->result = mysql_store_result(db_customer->mysql);
    if(!db_customer->result){
        cout << "Error! Can't retrieve any result from database(MPcustomer)" << endl;
        return;
    }
    
    int num_rows = mysql_num_rows(db_customer->result);
    if(num_rows > 1){
        cout << "Error! More than one User have same ID!(MPcustomer)" << endl;
        return;
    }

    this->db_customer->row = mysql_fetch_row(this->db_customer->result); // assume the cart_id is unique

    this->user_name = this->db_customer->row[1];
    this->phone = this->db_customer->row[2];
    this->email = this->db_customer->row[3];
    this->sex = stoi(this->db_customer->row[4]);
    this->create_time = this->db_customer->row[5];
    this->is_del = this->db_customer->row[6];
}

