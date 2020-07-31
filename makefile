test:test.cpp MyDB.cpp  	
	g++  test.cpp MyDB.cpp -o test  `mysql_config --cflags --libs` 
	#g++ -I/usr/local/mysql/include -o  test test.cpp MyDB.cpp -lmysqlclient
