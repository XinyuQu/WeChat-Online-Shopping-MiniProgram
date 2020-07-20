#include<iostream>
#include"MyDB.h"
using namespace std;


int main()
{
    MyDB db; 
    //连接数据库
    db.initDB("localhost","root","xq","test");
    //将用户信息添加到数据库
    db.exeSQL("INSERT accounts values('xq','123');");
    db.exeSQL("INSERT accounts values('xqq','456');");
    //将所有用户信息读出，并输出。
    db.exeSQL("SELECT * from accounts;");

    return 0;
}
