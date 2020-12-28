#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <string>

struct dict {
	char* key = (char*)malloc(16);
	char* data = (char*)malloc(64);
};
class http_reqana
{
private:
	//是否为空
	int status;
	char* status_msg = (char*)malloc(64);
	//POST数据长度
	int cont_length;
	//数据结构体指针
	std::map<std::string, std::string> data;
	//请求路径
	char* path = (char*)malloc(64);
	//请求类型
	char* type = (char*)malloc(4);
	//数据长度
	int data_len;
	//内置功能方法
	bool equal(const char* obe, const char* msg, int start, int end);
	bool equal(const char* obe, char* msg, int start, int end);
	void getsub(char* temp, char*msg, int start, int end);
public:
	//传http报文进来的结构函数
	http_reqana(char* message, int length);
	http_reqana(char* message, int length,int code);
	//无参结构函数
	http_reqana();
	//析构函数
	~http_reqana();
	//get函数
	char* get_path();
	char* get_type();
	char* get_sta_msg();
	int get_data(std::map<std::string, std::string>& outside);
	int get_length();
	int get_status();
	int get_data_len();
};
