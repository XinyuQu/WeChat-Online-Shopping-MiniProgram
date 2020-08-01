test:main.cpp MyDB.cpp  	
	#g++  main.cpp MyDB.cpp -o test  `mysql_config --cflags --libs` 
	g++ -I/usr/local/mysql/include -o  test main.cpp MyDB.cpp -lmysqlclient
