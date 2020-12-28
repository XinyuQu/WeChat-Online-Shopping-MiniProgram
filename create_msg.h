#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class create_msg {
private:
	char *msg;
	int length;
	int getsub(char* temp, char*msg, int start);
public:
	create_msg();
	create_msg(char* head, char* data, int data_len);
	create_msg(char* head, char* data, char* url, int data_len);
	void get_msg(char* outside);
	int get_length();
};
