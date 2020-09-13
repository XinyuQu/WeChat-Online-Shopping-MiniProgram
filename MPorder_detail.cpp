#include "MPorder_detail.hpp"
#include <string>

using namespace std;

// assume we don't have this row in db before
MPorder_detail::MPorder_detail(MyDB* db_order_detail, string order_detail_id, string order_id, string cart_detail_id, double price)
:db_order_detail(db_order_detail), order_detail_id(order_detail_id), order_id(order_id), cart_detail_id(cart_detail_id), price(price) {
    string cmd = "INSERT INTO order_detail_database VALUES ('" + order_detail_id + "','" + order_id + "','" 
    + cart_detail_id + "','" + to_string(price) + "')";

    if(mysql_query(db_order_detail->mysql, cmd.c_str())){
        cout << "Error from MPorder_detail constructor!" << endl;
        cout << "Mysql error message: " << mysql_error(db_order_detail->mysql) << endl;
        return;
    }
}

// assume we have already had this row in db
MPorder_detail::MPorder_detail(MyDB* db_order_detail, string order_id):db_order_detail(db_order_detail), order_id(order_id){
    string comd = "SELECT * FROM order_detail_database WHERE order_id='" + order_id + "';";

    if(mysql_query(db_order_detail->mysql, comd.c_str())){
        cout << "Error from MPorder_detail constructor!" << endl;
        cout << "Mysql error message: " << mysql_error(db_order_detail->mysql) << endl;
        return;
    }
    db_order_detail->result = mysql_store_result(db_order_detail->mysql);
    if(!db_order_detail->result){
        cout << "Error! Can't retrieve any result from database(MPorder_detail)" << endl;
        return;
    }
    
    int num_rows = mysql_num_rows(db_order_detail->result);
    if(num_rows > 1){
        cout << "Error! More than one order have same ID!(MPorder_detail)" << endl;
        return;
    }
    this->db_order_detail->row = mysql_fetch_row(db_order_detail->result); // assume the order_id is unique    
    this->order_detail_id = this->db_order_detail->row[0];
    this->cart_detail_id = this->db_order_detail->row[2];
    this->price = stod(this->db_order_detail->row[3]);
}


int MPorder_detail::MPorder_detail_setOrderDetailID(const string& newDetailID){
    string cmd = "UPDATE order_detail_database SET order_detail_id = '" + newDetailID + "' WHERE order_id='" + order_id + "';";
    // cout << comd << endl;

    if(mysql_query(db_order_detail->mysql, cmd.c_str())){
        cout << "Error from MPorder_detail setOrderDetailID!" << endl;
        cout << "Mysql error message: " << mysql_error(db_order_detail->mysql) << endl;
        return -1;
    }
    this->order_detail_id = newDetailID;
    db_order_detail->result = mysql_store_result(db_order_detail->mysql);
    return 0;
}

int MPorder_detail::MPorder_detail_setOrderID(const string& newOrderID){
    string cmd = "UPDATE order_detail_database SET order_id = '" + newOrderID + "' WHERE order_id='" + order_id + "';";

    if(mysql_query(db_order_detail->mysql, cmd.c_str())){
        cout << "Error from MPorder_detail setOrderID!" << endl;
        cout << "Mysql error message: " << mysql_error(db_order_detail->mysql) << endl;
        return -1;
    }
    this->order_id = newOrderID;
    db_order_detail->result = mysql_store_result(db_order_detail->mysql);
    return 0;
}

int MPorder_detail::MPorder_detail_setCartDetailID(const string& newCartDetailID){
    //get new product id and quantity with the new set cart_detail_id accordingly in cart_detail_database
    string comd = "SELECT * FROM cart_detail_database WHERE cart_detail_id='" + newCartDetailID + "';";
    if(mysql_query(db_order_detail->mysql, comd.c_str())){
        cout << "Error from MPorder_detail setCartDetailID getting price with cart_detail_id!" << endl;
        cout << "Mysql error message: " << mysql_error(db_order_detail->mysql) << endl;
        return -1;
    }
    db_order_detail->result = mysql_store_result(db_order_detail->mysql);
    if(!db_order_detail->result){
        cout << "Error! Can't retrieve any result from cart_detail_database(MPorder_detail setCartDetailID)" << endl;
        return -1;
    }
    
    int num_rows = mysql_num_rows(db_order_detail->result);
    if(num_rows > 1){
        cout << "Error! More than one cart_detail have same ID!(MPorder_detail setCartDetailID)" << endl;
        return -1;
    }
    this->db_order_detail->row = mysql_fetch_row(db_order_detail->result); // assume the order_id is unique    
    string product_id = this->db_order_detail->row[2];
    int quantity = stoi(this->db_order_detail->row[3]);  
    //get the product price with the new product_id accordingly in product_database
    MPproduct ProductInfo(db_order_detail, product_id);
    cout << "Error from MPorder_detail setCartDetailID getting product price!" << endl;
    double product_price = ProductInfo.MPproduct_getPrice();
    
    //update new cart_detail_id in database
    string cmd = "UPDATE order_detail_database SET cart_detail_id = '" + newCartDetailID + "' WHERE order_id='" + order_id + "';";
    if(mysql_query(db_order_detail->mysql, cmd.c_str())){
        cout << "Error from MPorder_detail setCartDetailID!" << endl;
        cout << "Mysql error message: " << mysql_error(db_order_detail->mysql) << endl;
        return -1;
    }
    this->cart_detail_id = newCartDetailID;
    //update new price in database
    this->price = quantity*product_price;

    db_order_detail->result = mysql_store_result(db_order_detail->mysql);
    return 0;
}

