#pragma once
#pragma once
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
#include "create_msg.h"
#include <map>
#pragma comment(lib,"ws2_32.lib")
int send_server(char* url, int len, std::map<std::string, std::string>& data);