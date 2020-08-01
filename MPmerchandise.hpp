#include <iostream>
#include <ctime>
using namespace std;

class MPmerchandise
{
  private:
    string product_id;
    string product_name;
    string detail;
    float price;
    string thumbnail;
    time_t create_date;
    string create_by;
    time_t modify_date;
    string modify_by;      
    bool is_del;
  public:
    MPmerchandise(string product_id, string product_name, string detail, float price, string thumbnail, time_t create_date, string create_by, time_t modify_date, string modify_by, bool is_del):product_id(product_id), product_name(product_name), detail(detail), price(price), thumbnail(thumbnail), create_date(create_date), create_by(create_by), modify_date(modify_date), modify_by(modify_by), is_del(false){}
    int MPmerchandise_add(string product_id, string product_name, string detail, float price, string thumbnail, time_t create_date, string create_by, time_t modify_date, string modify_by, bool is_del);
    int MPmerchandise_delete(string product_id);
    int MPmechandise_mod_product_id(string product_id, string new_product_id);
    int MPmechandise_get_product_id(string product_id);

  
};
