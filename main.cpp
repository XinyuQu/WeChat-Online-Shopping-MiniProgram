#include <iostream>
#include <vector>
#include "MPcart.hpp"
// #include "MPcustomer.hpp"
// #include "MPmerchandise.hpp"
// #include "MPorder.hpp"
#include "MyDB.hpp"
using namespace std;

int main()
{
    MyDB* db = new MyDB(); 
    //连接数据库
    db->initDB("cdb-54f0tuve.cd.tencentcdb.com","root","R23BN4xO1KGqZBe7SEpufaLNX","ECommerce",10092);
    MPcart testCart(db,"test_user_id2");
    string res = testCart.MPcart_getCartID();
    cout << res << endl;

    // MPcart testCart2(db, "user_id_3", "cart_id_3");
    MPcart testCart2(db, "user_id_3");
    cout << "testCart2 cart: " << testCart2.MPcart_getCartID() << endl;
    cout << "testCart2 user: " << testCart2.MPcart_getUserID() << endl;


    //将用户信息添加到数据库
    //db.exeSQL("CREATE TABLE test2 (col1 int, col2 char, col3 varchar(25))");
    //db->exeSQL("INSERT INTO cart_database values('test_cart_id2','test_user_id2');");
    // db.exeSQL("INSERT INTO test values('xqq');");
    //将所有用户信息读出，并输出。
    //db.exeSQL("SELECT * from cart_database;");
    return 0;
}

