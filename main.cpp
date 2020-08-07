#include <iostream>
#include <vector>
#include "MPcart.hpp"
#include "MPcart_detail.hpp"
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
    MPcart testCart(db,"new_user_id");
    string res = testCart.MPcart_getCartID();
    cout << "testCart original ID: " << res << endl;

    int i = testCart.MPcart_setCartID("new_user_id_3");
    res = testCart.MPcart_getCartID();
    cout << "New cart ID" << res << endl;
    for(int i = 0; i < 40; i++)cout << "-";
    cout << endl;

    // MPcart testCart2(db, "user_id_3", "cart_id_3");
    MPcart testCart2(db, "user_id_3");
    cout << "testCart2 cart: " << testCart2.MPcart_getCartID() << endl;
    cout << "testCart2 user: " << testCart2.MPcart_getUserID() << endl;

    for(int i = 0; i < 40; i++)cout << "-";
    cout << endl;

    // MPcart_detail test1_cart_detail(db, "detail_id_1", "cart_id_1", "product_id_1", 1, "2020,8,6 12,00,00", "2020,8,6 12,00,00", false);
    
    MPcart_detail test1_cart_detail(db, "cart_id_1");
    cout << "cart_detail_1: detail_ID  " << test1_cart_detail.MPcart_detail_getIsDel() << endl;


    //将用户信息添加到数据库
    //db.exeSQL("CREATE TABLE test2 (col1 int, col2 char, col3 varchar(25))");
    //db->exeSQL("INSERT INTO cart_database values('test_cart_id2','test_user_id2');");
    // db.exeSQL("INSERT INTO test values('xqq');");
    //将所有用户信息读出，并输出。
    //db.exeSQL("SELECT * from cart_database;");
    return 0;
}

