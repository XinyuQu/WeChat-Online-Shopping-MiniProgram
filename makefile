test:test.cpp MyDB.cpp  	
	g++  test.cpp MyDB.cpp -o test  `mysql_config --cflags --libs` 
