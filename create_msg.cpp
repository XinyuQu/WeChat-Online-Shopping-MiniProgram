#include "create_msg.h"
create_msg::create_msg() {
	length = 0;
	msg = nullptr;
}
create_msg::create_msg(char* head, char* data, int data_len) {
	int start=0;
	this->msg = (char*)malloc(1024);
	memset(msg,0,1024);
	char ver[10] = "HTTP/1.1";
	char header[270];
	memset(header, 0, 270);
	sprintf(header, "Server: Wing\r\nLast-Modified: Mon, 27 July 2020 13:50:00 GMT\r\nAccept-Ranges: bytes\r\nVary: Accept-Encoding, user-Agent\r\nContent-Type: application/json;charset=UTF-8\r\nContent-Length: %d\r\n\r\n",data_len);
	start=getsub(this->msg, ver,start);
	this->msg[start] = 32;
	start = getsub(this->msg, head, start+1);
	this->msg[start] = 13;
	this->msg[start+1] = 10;
	start = start + 2;
	start = getsub(this->msg, header, start);
	start = getsub(this->msg, data, start);
}
create_msg::create_msg(char* head, char* data, char* url, int data_len) {
	int start = 0;
	this->msg = (char*)malloc(1024);
	memset(msg, 0, 1024);
	char ver[10] = "HTTP/1.1";
	char host[9] = "\r\nHost: ";
	char header[270];
	memset(header, 0, 270);
	sprintf(header, "\r\nConnection: keep-alive\r\nPragma: no-cache\r\nCache-Control: no-cache\r\nsec-ch-ua: nwjs 75\r\nSec-Fetch-Mode: cors\r\nOrigin: http://127.0.0.1:19746\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.1 (KHTML, like Gecko) Chrome/14.0.835.163 Safari/535.1 \r\nSec-Fetch-Dest: empty\r\nSec-Fetch-Site: cross-site\r\vAccept: */*\ r\nAccept-Encoding: gzip, deflate, br, UTF-8\r\n");
	start = getsub(this->msg, head, start + 1);
	if (head[0] == 71) {
		this->msg[start] = 63;
		start = getsub(this->msg, data, start + 1);
	}
	this->msg[start] = 32;
	start = getsub(this->msg, ver, start);
	start = getsub(this->msg, host, start);
	start = getsub(this->msg, url, start);
	start = getsub(this->msg, header, start);
	if (head[0] == 80) {
		char post[50];
		memset(post,0,50);
		sprintf (post,"Content-Length: %d\r\ncontent-type: application/json\r\n\r\n", data_len);
		start = getsub(this->msg, post, start);
		start = getsub(this->msg, data, start + 1);
	}
}	

int create_msg::getsub(char* temp, char*msg,int start) {
	int i=0;
	while(msg[i]!=0) {
		temp[start+i] = msg[i];
		++i;
	}
	return start + i;
}
int create_msg::get_length() {
	return this->length;
}
void create_msg::get_msg(char* outside) {
	getsub(outside, this->msg, 0);
}
