#include "send_msg.h"
int send_server(int port,char* url, int len, std::map<std::string, std::string>& data) {
	int clientSocket;
	int socket_id = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_id < 0) {

	}

}