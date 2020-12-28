#include "mainfunc.h"
using namespace std;

long prevOrderID = 4;
long prevCartID = 0;
long prevCartDetailID = 0;

int copy(std::string &ori, char* dest, int start) {
	int i = 0;
	while (ori[i] != 0){
		dest[start + i] = ori[i];
		i++;
	}
	printf("%c,%d\n",ori[i],i);
	return i - 1;
}

// key: cart; value: productID(4) + quantity(2) + ...
// key: id; value
int add_cart(std::map<std::string, std::string>& data, int len, MyDB* db) {
	if (len != 2) return -1;
	std::string cart_detail;
	char* id;
	char* cart;
	id = (char*)malloc(data["user_id"].length() + 1);
	memset(id, 0, data["user_id"].length() + 1);
	if (1 == data.count("user_id")) copy(data["user_id"], id, 0);
	else {
		printf("format wrong without user_id\n");
		return 0;
	}
	cart = (char*)malloc(data["cart"].length() + 1);
	memset(cart, 0, data["cart"].length() + 1);
	if (1 == data.count("cart")) copy(data["cart"], cart, 0);
	else {
		printf("format wrong without cart\n");
		return 0;
	}
	
	string user_id(id); // user_id
	string oldCart = "";
	cout << "Hello" << endl;

	cout << user_id << endl;
	MPcart* mpCart = new MPcart(db, user_id);
	string cart_id = mpCart->MPcart_getCartID();
	MPcart_detail* mpCartDetail = new MPcart_detail(db, cart_id);
	if (!mpCartDetail->MPcart_detail_getIsDel()) {
		mpCartDetail->MPcart_detail_setIsDel(true);
	}
	string str_cart(cart);
	mpCartDetail->MPcart_detail_setProductID(str_cart);



	//MPcart* cart=new MPcart(info, id);
	//std::string cartid=cart.MPcart_getCartID();
	//MPcart_detail* detail=new MPcart_detail(info, cartid);
	//cart_detail=
	//update the cart with the char *cart that is composed in the frontend
	return 0;
}

// key is user ID; 先不测试
int cart_tota(std::map<std::string, std::string>& data, int len, MyDB* db) {
	char* id; // user_id
	int i, count;
	double price;
	string temp;
	id = (char*)malloc(data["user_id"].length() + 1);
	memset(id, 0, data["user_id"].length() + 1);
	if (1 == data.count("user_id")) copy(data["user_id"], id, 0);
	else {
		printf("format wrong without user_id\n");
		return 0;
	}
	copy(data["user_id"], id, 0);

	//get the total value of the cart of user with char *id
	string str_id(id);
	MPcart* cart = new MPcart(db, id);
	MPcart_detail* cart_detail = new MPcart_detail(db, cart->MPcart_getUserID());
	// product ID
	string productID = cart_detail->MPcart_detail_getProductID();

	// price
	while (productID[i] != 0) {
		temp = "";
		count = 0;
		temp += productID[i];
		temp += productID[i + 1];
		temp += productID[i + 2];
		temp += productID[i + 3];
		count += (productID[i + 4] - 48) * 10;
		count += (productID[i + 3] - 48);
		MPproduct* product = new MPproduct(db, temp);
		price += product->MPproduct_getPrice()*count;
	}
	return 0;
}

// key: id; 
// value product id 的集合
// 
int merchan_info(std::map<std::string, std::string>& data, int len, char* output, MyDB* db) {
	int idlen, i, start = 0, oprice, lenth;
	char* id;
	double price;
	string info, temp = "{";
	id = (char*)malloc(data["product_id"].length() + 1);
	memset(id, 0, data["product_id"].length() + 1);
	if (1 == data.count("product_id")) copy(data["product_id"], id, 0);
	else {
		printf("format wrong without product_id\n");
		return 0;
	}
	idlen = data["product_id"].length() / 4;
	printf(id);
	int* ids;
	ids = (int *)malloc(idlen * sizeof(int));
	printf("%d,%d\n",idlen,ids[0]);
	memset(ids, 0, idlen*sizeof(int));
	for (i = 0; i < idlen; ++i) {
		ids[i] += (id[4 * i] - 48) * 1000;
		ids[i] += (id[4 * i + 1] - 48)*100;
		ids[i] += (id[4 * i+2] - 48) * 10;
		ids[i] += (id[4 * i+3] - 48);
	}
	printf("%d,%d\n",idlen,ids[0]);
	for (i = 0; i < idlen; ++i) {
		info = "";
		//ids[i];//product ID
		//get the info of mechants with id of ids[i]
		string prodID = to_string(ids[i]);
		if (ids[i] < 10) {
			prodID = "0" + prodID;
		}
		MPproduct* product = new MPproduct(db, prodID);
		// 熊猫的超长str
		price = product->MPproduct_getPrice();
		oprice = price * (10 + rand() % 5) / 10;
		info = prodID+":{name:\"" + product->MPproduct_getProductName() + "\",price:\"¥" + to_string(product->MPproduct_getPrice()) + "\",oldprice:\"" + to_string(oprice) + "\',count:0,image:\"" + product->MPproduct_getThumbnail() + "\"}";
		temp += info;
	}
	temp += "}";
	lenth = temp.length()-1;
	temp.copy(output,lenth,0);
	cout << temp << endl;
	return lenth;
}
// key: user ID 
int nw_order(std::map<std::string, std::string>& data, int len, MyDB* db) {
	char* id, *address, *uid; // id = userID
	if (1 == data.count("product_ids")){
		id = (char*)malloc(data["product_ids"].length());
		memset(id, 0, data["product_ids"].length() );
		printf("lol\n");
		copy(data["product_ids"], id, 0);
	}
	else {
		printf("format wrong without product_id\n");
		return 0;
	}
	if (1 == data.count("user_id")){
		uid = (char*)malloc(data["user_id"].length()+1);
		memset(uid, 0, data["user_id"].length()+1);
		copy(data["user_id"], uid, 0);
	}
	else {
		printf("format wrong without user_id\n");
		return 0;
	}
	if (1 == data.count("address")) {
		address = (char*)malloc(data["address"].length() + 1);
		memset(address, 0, data["address"].length() + 1);
		copy(data["address"], address, 0);
	}
	else {
		printf("format wrong without address\n");
		return 0;
	}
	//make a cart to be a new order and distribute a id for it
	string str_user(uid);
	MPcart* cart = new MPcart(db, str_user);
	MPcart_detail* cart_detail = new MPcart_detail(db, cart->MPcart_getCartID());
	// new order based on cart detail ID
	double price = 0;
	MPorder* order = new MPorder(db, to_string(++prevOrderID), str_user, price, "remark", "2020,8,6 12,00,00", true);
	return 0;
}
// key: user ID
int add_user(std::map<std::string, std::string>& data, int len, MyDB* db) {
	std::string user_id = "";
	std::string user_name = "";
	std::string phone = "";
	std::string email = "";
	std::string time = "2020,8,6 12,00,00"; //引入time
	int sex;
	if (1 == data.count("user_id")) user_id = data["user_id"];
	if (1 == data.count("name")) user_name = data["name"];
	if (1 == data.count("phone")) phone = data["phone"];
	if (1 == data.count("email")) email = data["email"];

	MPcustomer* customer = new MPcustomer(db, user_id, user_name, phone, email, sex, time, true);


	MPcart* cart = new MPcart(db, user_id, to_string(++prevCartID));
	MPcart_detail* cart_detail = new MPcart_detail(db, to_string(++prevCartDetailID), cart->MPcart_getCartID(), "", 0, time, "2020,8,6 12,00,00", true);
	//MPcustomer(info, user_id, name, phone, email, 0, time, false);
	return 0;
}
