#include <iostream>
#include <ctime>
using namespace std;

class MPcustomer
{
  private:
    string user_id;
    string user_name;
    string phone;
    string email;
    int sex;
    time_t create_time;     
    bool is_del;
  public:
    MPcustomer(string user_id, string user_name, string phone, string email, int sex, time_t create_time, is_del(false){}
    int MPcustomer_add(string user_id, string user_name, string phone, string email, int sex, time_t create_time, bool is_del);
    int MPcustomer_delete(string user_id);
    int MPcustomer_mod_user_id(string user_id, string new_user_id);
    int MPcustomer_get_uer_id(string user_id);


  
};
