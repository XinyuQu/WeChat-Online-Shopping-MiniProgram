#include "mainfunc.h"
#include <iostream>
#include <vector>
#include "MPcart.hpp"
#include "MPcart_detail.hpp"
#include "MPcustomer.hpp"
#include "MPproduct.hpp"
#include "MyDB.hpp"
#include "MPorder.hpp"
#include "MPorder_detail.hpp"
#include <string>
using namespace std;

long prevOrderID = 0;
long prevCartID = 0;
long prevCartDetailID = 0;

int copy(std::string ori,char* dest, int start) {
	int i = 0;
	while (ori[i] != 0) {
		dest[start+i] = ori[i];
	}
	return i - 1;
}
int add_cart(std::map<std::string, std::string> data, int len, MyDB* db) {
	if (len != 2) return -1;
	std::string cart_detail;
	char* id;
	char* cart;
	id = (char*)malloc(data["id"].length()+1);
	memset(id, 0, data["id"].length() + 1);
	copy(data["id"],id,0);
	cart = (char*)malloc(data["cart"].length()+1);
	memset(cart,0, data["cart"].length() + 1);
	copy(data["cart"], cart,0);
	string user_id(id); // user_id
	string oldCart = "";

	MPcart* mpCart = new MPcart(db, user_id);
	string cart_id = mpCart->MPcart_getCartID();
	MPcart_detail* mpCartDetail = new MPcart_detail(db, cart_id);
	if(!mpCartDetail->MPcart_detail_getIsDel()){
		mpCartDetail->MPcart_detail_setIsDel(true);
	}
	string str_cart(cart);
	mpCartDetail->MPcart_detail_setProductID(str_cart);



	// MPcart* cart=new MPcart(info, id);
	//std::string cartid=cart.MPcart_getCartID();
	//MPcart_detail* detail=new MPcart_detail(info, cartid);
	//cart_detail=
	//update the cart with the char *cart that is composed in the frontend
	return 0;
}
int cart_tota(std::map<std::string, std::string> data, int len, MyDB* db) {
	char* id; // user_id
	id = (char*)malloc(data["id"].length() + 1);
	memset(id, 0, data["id"].length() + 1);
	copy(data["id"], id,0);
	//get the total value of the cart of user with char *id
	string str_id(id);
	MPcart* cart = new MPcart(db, id);
	MPcart_detail* cart_detail = new MPcart_detail(db, cart->MPcart_getUserID());
	// product ID
	string productID = cart_detail->MPcart_detail_getProductID();

	// price
	MPproduct* product = new MPproduct(db, productID);
	double price = product->MPproduct_getPrice();

	return 0;
}
int merchan_info(std::map<std::string, std::string> data, int len, char* output, MyDB* db) {
	int idlen, i, start=0;
	char* id;
	id = (char*)malloc(data["id"].length() + 1);
	memset(id, 0, data["id"].length() + 1);
	copy(data["id"], id,0);
	idlen = data["id"].length() / 2;
	int* ids;
	ids = (int *)malloc(idlen*sizeof(int));
	memset(ids,0,idlen);
	for (i = 0; i < idlen; ++i) {
		ids[i] += (id[2*i]-48)*10;
		ids[i] += (id[2 * i+1] - 48) * 10;
	}
	char* data;
	
	for (i = 0; i < idlen; ++i) {
		//ids[i];//product ID
		//get the info of mechants with id of ids[i]
		MPproduct* product = new MPproduct(db, to_string(ids[i]));
		// 熊猫的超长str
		string info = "name:\'" + product->MPproduct_getProductName() + "\',price:\'¥" + to_string(product->MPproduct_getPrice()) + "\',oldprice:\'¥0\',count:0,image:\"" + product->MPproduct_getThumbnail() + "\",";
	}
}
int nw_order(std::map<std::string, std::string> data, int len, MyDB* db) {
	char* id, *address, *uid; // id = userID
	id = (char*)malloc(data["id"].length() + 1);
	memset(id, 0, data["id"].length() + 1);
	copy(data["id"], id, 0);
	uid = (char*)malloc(data["uid"].length() + 1);
	memset(uid, 0, data["uid"].length() + 1);
	copy(data["uid"], uid, 0);
	address = (char*)malloc(data["address"].length() + 1);
	memset(address, 0, data["address"].length() + 1);
	copy(data["address"], id, 0);
	//make a cart to be a new order and distribute a id for it
	string str_user(id);
	MPcart* cart = new MPcart(db, str_user);
	MPcart_detail* cart_detail = new MPcart_detail(db, cart->MPcart_getCartID());
	// new order based on cart detail ID
	double price = 0;
	MPorder* order = new MPorder(db, to_string(++prevOrderID), str_user, price, "remark", "2020,8,6 12,00,00", true);
	return 0;
}
int add_user(std::map<std::string, std::string> data, int len, MyDB* db) {
	std::string user_id="";
	std::string user_name="";
	std::string phone="";
	std::string email="";
	std::string time=""; //引入time
	int sex;
	if (1 == data.count("id")) user_id = data["id"];
	if (1 == data.count("name")) user_name = data["name"];
	if (1 == data.count("phone")) phone = data["phone"];
	if (1 == data.count("email")) email = data["email"];

	MPcustomer* customer = new MPcustomer(db, user_id, user_name, phone, email, sex, time, true);

	MPcart* cart = new MPcart(db, user_id, to_string(++prevCartID));
	MPcart_detail* cart_detail = new MPcart_detail(db, to_string(++prevCartDetailID), cart->MPcart_getCartID(), "",0,time, "2020,8,6 12,00,00", true);
	//MPcustomer(info, user_id, name, phone, email, 0, time, false);
}