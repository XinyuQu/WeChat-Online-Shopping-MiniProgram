#include <iostream>
#include <vector>
#include "MPcart.hpp"
#include "MPcart_detail.hpp"
#include "MPcustomer.hpp"
#include "MPproduct.hpp"
#include "MyDB.hpp"
#include "MPorder.hpp"
#include "MPorder_detail.hpp"

#include "mainfunc.h"
#include <map>
#include <string>
using namespace std;

int main()
{
    MyDB* db = new MyDB(); 
    //连接数据库
    db->initDB("cdb-54f0tuve.cd.tencentcdb.com","root","R23BN4xO1KGqZBe7SEpufaLNX","ECommerce",10092);
    cout << "connect db successfully!" << endl;

    // 分割线
    for(int i = 0; i < 40; i++)cout << "-";
    cout << endl;

    cout << "Hello" << endl;
    try{
        MPcart_detail testDetail(db, "1111");
    }
    catch(string& err){
        cout << err << endl;
    }
    // adcart pass
    // map<string, string> m; // add_cart
    // m["id"] = "01"; // user iD
    // m["cart"] = "0299"; // id + quantity
    // add_cart(m, 2, db);

    // map<string, string> merchanINFO;
    // merchanINFO["id"] = "03"; // product id
    // char* str;
    // merchan_info(merchanINFO, 0, str, db);

    // map<string, string> nwOrder;
    // nwOrder["id"] = "01"; // userID
    // nw_order(nwOrder, 0, db);

    //map<string, string> addUser;
   // addUser["id"] = "07"; // userID
    //addUser["name"] = "Ray";
   // addUser["phone"] = "13900000000";
   // addUser["email"] = "lalala@qq.com";
   // add_user(addUser, 0, db);



    // // test set cart id (success)

    // MPcart testCart(db,"user_id_3");
    // string res = testCart.MPcart_getCartID();
    // cout << "testCart original ID: " << res << endl;

    // int i = testCart.MPcart_setCartID("new_cart_id_3");
    // res = testCart.MPcart_getCartID();
    // cout << "!!!" << endl;
    // cout << "New cart ID " << res << endl;

    // 分割线
    for(int i = 0; i < 40; i++)cout << "-";
    cout << endl;

    // // test MPcart set User ID (success)
    // MPcart testCart(db, "test_user_id");
    // string res = testCart.MPcart_getUserID();
    // cout << "testCart original user ID: " << res << endl;

    // int i = testCart.MPcart_setUserID("new_user_id");
    
    // res = testCart.MPcart_getUserID();
    // cout << "!!!" << endl;
    // cout << "New user ID " << res << endl;

    // for(int i = 0; i < 40; i++)cout << "-";
    // cout << endl;

    // test MPcart detail's constructor (success)
    // // MPcart_detail test1_cart_detail(db, "detail_id_1", "cart_id_1", "product_id_1", 1, "2020,8,6 12,00,00", "2020,8,6 12,00,00", false);
    
    // MPcart_detail testDetail(db, "new_cart_id_1");
    // cout << "Detail: " << testDetail.MPcart_detail_getCartID() << endl;


    // test MPcart_detail setter (all pass)
    // MPcart_detail test1_cart_detail(db, "new_cart_id_1");
    // cout << "origin:  " << test1_cart_detail.MPcart_detail_getCartDetailID() << endl;
    // int res = test1_cart_detail.MPcart_detail_setIsDel(false);
    // cout << "updated: " << test1_cart_detail.MPcart_detail_getIsDel() << endl;

    // test MPcustomer constructor and getters (pass)
    // MPcustomer testCustomer(db, "userId");
    // cout << "success: " << testCustomer.MPcustomer_getemail() << endl;
    

    // // test MPproduct constructor
    // MPproduct testProduct(db, "id");
    // testProduct.MPproduct_setCreateBy("c");
    // cout << "product: " << testProduct.MPproduct_getCreateBy() << endl;

    // test order
    // MPorder_detail testOrderDetail(db, "order_id");
    // cout << "Hi" << endl;
    // testOrderDetail.MPorder_detail_setCartDetailID("cartID");
    // cout << "2" << endl;
    // cout << "cart_detail_id: " << testOrderDetail.MPorder_detail_getCartDetail() << endl;


    //将用户信息添加到数据库
    //db.exeSQL("CREATE TABLE test2 (col1 int, col2 char, col3 varchar(25))");
    //db->exeSQL("INSERT INTO cart_database values('test_cart_id2','test_user_id2');");
    // db.exeSQL("INSERT INTO test values('xqq');");
    //将所有用户信息读出，并输出。
    //db.exeSQL("SELECT * from cart_database;");
    cout << "Program finished!" << endl;
    return 0;
}

