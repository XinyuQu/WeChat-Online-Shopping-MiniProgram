#include <iostream>
#include <vector>
#include "MyDB.h"
#include "MPcart.hpp"
#include "MPcustomer.hpp"
#include "MPmerchandise.hpp"
#include "MPorder.hpp"
using namespace std;

vector<MPcart> cart_vec;


void getCart(MyDB& db);

int main()
{
    MyDB db; 
    //连接数据库
    db.initDB("cdb-54f0tuve.cd.tencentcdb.com","root","R23BN4xO1KGqZBe7SEpufaLNX","ECommerce",10092);
    //将用户信息添加到数据库
    //db.exeSQL("CREATE TABLE test2 (col1 int, col2 char, col3 varchar(25))");
    // db.exeSQL("INSERT INTO cart_database values('test_cart_id','test_user_id');");
    // db.exeSQL("INSERT INTO test values('xqq');");
    //将所有用户信息读出，并输出。
    //db.exeSQL("SELECT * from cart_database;");
    return 0;
}

void getCart(MyDB& db){
    if(mysql_query(db.mysql, "SELECT * from cart_database")){
        cout << "Get error when reading from cart database" << endl;
        return;
    }
    
    db.cart_res = mysql_store_result(db.mysql);
    int num_fields = mysql_num_fields(db.cart_res);
    int num_rows = mysql_num_rows(db.cart_res);
    for(size_t each_cart = 0; each_cart < num_rows; each_cart++){
        
    }
}
