#include <cstdio>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include "http_reqana.h"
#include "mainfunc.h"
#include "create_msg.h"
bool equal(char* obe, char* msg) {
	int i=0;
	while (obe[i]!=0 && msg[i]!=0) {
		if (obe[i] != msg[i]) return false;
		++i;
	}
	return true;
}
int main(){
	char rec_buff[4096], send_buff[4096];
	int server_sockfd;
	int ret = -1;
	int conn_fd = -1;
	int recv_len = -1;
	int server_ip_port = 714;
	int sta = 1;
	char *path, *output;
	struct sockaddr_in server_sockaddr;
	memset(&server_sockaddr, 0, sizeof(server_sockaddr));
	server_sockaddr.sin_family = AF_INET;
	server_sockaddr.sin_port = htons(server_ip_port);
	server_sockaddr.sin_addr.s_addr=htons(INADDR_ANY);
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_sockfd < 0) {
		fprintf(stderr, "socket error %s errno %d\n", strerror(errno), errno);
	}
	ret = bind(server_sockfd, (struct sockaddr*) &server_sockaddr, sizeof(server_sockaddr));
	if (ret < 0) {
		fprintf(stderr, "bind socket error %s errno: %d\n", strerror(errno), errno);
	}
	ret = listen(server_sockfd, 1024);
	if (ret < 0) {
		fprintf(stderr, "listen error %s errno: %d\n", strerror(errno), errno);
	}
	MyDB* db = new MyDB();
	db->initDB("cdb-54f0tuve.cd.tencentcdb.com", "root", "R23BN4xO1KGqZBe7SEpufaLNX", "ECommerce", 10092);
	while (1) {
		fprintf(stdout, "start listen\n");
		conn_fd = accept(server_sockfd, (struct sockaddr*)NULL,NULL);
		if (conn_fd < 0) {
			fprintf(stderr, "accept socket error %s errno: %d\n", strerror(errno), errno);
			continue;
		}
		recv_len = recv(conn_fd,rec_buff, 1024, 0);
		if (recv_len < 0) {
			fprintf(stderr, "recv error %s errno: %d\n", strerror(errno), errno);
		}
		rec_buff[recv_len]='\0';
		http_reqana* dat = new http_reqana(rec_buff, recv_len);
		std::map<std::string, std::string> outside;
		sta=dat->get_data(outside);
		path=dat->get_path();
		if (equal("/add_cart",path)) {
			add_cart(outside, 2, db);
			sta = 0;
		}
		if (equal("/cart_tota", path)) {
			cart_tota(outside, 0, db);
			sta = 0;
		}
		if (equal("/merchan_info", path)) {
			output = (char*)malloc(2048);
			merchan_info(outside, 0, output, db);
			sta = 0;
		}
		if (equal("/nw_order", path)) {
			nw_order(outside, 0, db);
			sta = 0;
		}
		if (equal("/add_user", path)) {
			add_user(outside, 0, db);
			sta = 0;
		}
		printf("message from outside: %s\n", rec_buff);
		create_msg *senda;
		if(sta==0) senda= new create_msg("200 OK", "{\"sta\":\"0\"}", 11);
		else senda = new create_msg("200 OK", "{\"sta\":\"1\"}", 11);
		senda->get_msg(send_buff);
		send(conn_fd,send_buff,4096,0);
		close(conn_fd);
		conn_fd = -1;
	}
	close(server_sockfd);
	server_sockfd = -1;
    printf("finish from ConsoleApplication5!\n");
    return 0;
}