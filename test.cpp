#include<iostream>
#include"MyDB.h"
using namespace std;


int main()
{
    MyDB db; 
    //连接数据库
    db.initDB("cdb-54f0tuve.cd.tencentcdb.com","root","R23BN4xO1KGqZBe7SEpufaLNX","test",10092);
    //将用户信息添加到数据库
    db.exeSQL("CREATE TABLE test2 (col1 int, col2 char, col3 varchar(25))");
    // db.exeSQL("INSERT INTO test values('xq');");
    // db.exeSQL("INSERT INTO test values('xqq');");
    //将所有用户信息读出，并输出。
    db.exeSQL("SELECT * from test;");

    return 0;
}
