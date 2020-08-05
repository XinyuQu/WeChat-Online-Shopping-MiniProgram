#include "MPcart_detail.hpp"

using namespace std;

// assume we don't have this row in db before
MPcart_detail::MPcart_detail(MyDB* db_cart_detail, string cart_detail_id, string cart_id, string product_id, int quantity, string create_time, string modify_time, bool is_del)
:db_cart_detail(db_cart_detail), cart_detail_id(cart_detail_id), cart_id(cart_id), product_id(product_id), quantity(quantity), create_time(create_time), modify_time(modify_time), is_del(is_del) {
    string cmd = "INSERT INTO cart_detail_database VALUES ('" + cart_detail_id + "','" + cart_id + "','" 
    + product_id + "','" + quantity + "','" + create_time + "','" + modify_time + "','" + is_del "');";
    if(mysql_query(db_cart_detail->mysql, cmd.c_str())){
        cout << "Error from MPcart_detail constructor!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart_detail->mysql) << endl;
        return;
    }
}

// assume we have already had this row in db
MPcart_detail::MPcart_detail(MyDB* db_cart_detail, string cart_id):db_cart_detail(db_cart_detail), cart_id(cart_id){
    string comd = "SELECT * FROM cart_database WHERE cart_id='" + cart_id + "';"; // assume cart id is unique
    // cout << comd << endl;

    if(mysql_query(db_cart_detail->mysql, comd.c_str())){
        cout << "Error from MPcart_detail constructor!" << endl;
        cout << "Mysql error message: " << mysql_error(db_cart_detail->mysql) << endl;
        return;
    }
    db_cart_detail->result = mysql_store_result(db_cart_detail->mysql);
    this->db_cart_detail->row = mysql_fetch_row(db_cart_detail->result); // assume the cart_id is unique
    this->cart_detail_id = this->db_cart_detail->row[0];
    this->product_id = this->db_cart_detail->row[2];
    this->quantity = stoi(this->db_cart_detail->row[3]);
    this->create_time = this->db_cart_detail->row[4];
    this->modify_time = this->db_cart_detail->row[5];
    this->is_del = this->db_cart_detail->row[6];
}
