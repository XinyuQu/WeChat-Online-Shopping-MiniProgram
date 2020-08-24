#ifndef MPcustomer_hpp
#define MPcustomer_hpp
#include <string>
#include "MyDB.hpp"
using namespace std;

class MPcustomer{
private:
  string user_id;
  string user_name;
  string phone;
  string email;
  short sex; // 0 for female; 1 for male
  string create_time;     
  bool is_del;
  MyDB* db_customer;

public:
  MPcustomer(MyDB* db_customer, string user_id, string user_name, string phone, string email, short sex, string create_time, bool is_del);
  MPcustomer(MyDB* db_customer, string user_id);

  // getters
  string MPcustomer_getUserID()const {return user_id;}
  string MPcustomer_getUserName()const {return user_name;}
  string MPcustomer_getPhone()const {return phone;}
  string MPcustomer_getemail()const {return email;}
  short MPcustomer_getSex()const {return sex;}
  string MPcustomer_getCreateTime()const {return create_time;}
  bool MPcustomer_getIsDel()const {return is_del;}


};
#endif