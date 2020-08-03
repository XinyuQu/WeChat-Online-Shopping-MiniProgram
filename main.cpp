#include <iostream>
#include <vector>
#include "MPcart.hpp"
// #include "MPcustomer.hpp"
// #include "MPmerchandise.hpp"
// #include "MPorder.hpp"
#include "MyDB.hpp"
using namespace std;


void getCart(MyDB& db);

int main()
{
    MyDB db; 
    //连接数据库
    db.initDB("cdb-54f0tuve.cd.tencentcdb.com","root","R23BN4xO1KGqZBe7SEpufaLNX","ECommerce",10092);
    MPcart testCart(db,"test_cart_id");
    string res = testCart.MPcart_getUserID();
    cout << "Hi" << endl;
    //将用户信息添加到数据库
    //db.exeSQL("CREATE TABLE test2 (col1 int, col2 char, col3 varchar(25))");
    // db.exeSQL("INSERT INTO cart_database values('test_cart_id','test_user_id');");
    // db.exeSQL("INSERT INTO test values('xqq');");
    //将所有用户信息读出，并输出。
    //db.exeSQL("SELECT * from cart_database;");
    return 0;
}

