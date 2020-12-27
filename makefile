test:main.cpp MyDB.cpp MPcart.cpp MPcart_detail.cpp MPcustomer.cpp MPproduct.cpp MPorder.cpp MPorder_detail.cpp mainfunc.cpp
	#g++ -std=c++11  main.cpp MyDB.cpp MPcart.cpp MPcart_detail.cpp MPcustomer.cpp MPproduct.cpp MPorder.cpp MPorder_detail.cpp mainfunc.cpp -o test  `mysql_config --cflags --libs` 
	g++ -I/usr/local/mysql/include -o  test main.cpp MyDB.cpp MPcart.cpp MPcart_detail.cpp MPcustomer.cpp MPproduct.cpp MPorder.cpp MPorder_detail.cpp mainfunc.cpp -lmysqlclient
