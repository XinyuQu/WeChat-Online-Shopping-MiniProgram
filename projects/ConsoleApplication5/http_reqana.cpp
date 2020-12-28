#include "http_reqana.h"
http_reqana::http_reqana() {
	this->status = -1;
	this->cont_length = 0;
	this->path = { 0 };
}
http_reqana::http_reqana(char* message, int length) {
	int task = 543210;
	int i, start = 0, end, len = 0, j = 0;
	char* temp;
	bool sta = false;
	dict* tempair;
	temp = (char *)malloc(70);
	this->cont_length = 0;
	for (i = 0;i < length;i++) {
		if (i + this->cont_length == length) {
			break;
		}
		memset(temp, 0, 64);
		if (message[i] == 32) {
			end = i;
			getsub(temp, message, start, end);
			if (task % 10 == 1) {
				memset(this->path, 0, 64);
				getsub(this->path, message, start, end);
				task /= 10;
			}
			if (task % 10 == 0) {
				getsub(this->type, message, start, end);
				task /= 10;
			}
			if (equal("Content-Length:", message, start, end)) {
				task = task * 10 + 40;
				task /= 10;
			}
			start = i + 1;
		}
		else if (message[i] == 10) {
			end = i - 1;
			if (task % 10 == 6) {
				getsub(temp, message, start, end);
				while (temp[j] != 0) {
					len = len * 10 + temp[j] - 48;
					j++;
				}
				this->cont_length = len;
				task /= 10;
			}
			start = i + 1;
		}
	}
	start++;
	end = start;
	j = 0;
	this->data_len = 0;
	if (this->cont_length > 0) {
		for (i = 0;i < this->cont_length - 1;i++) {
			if (message[end + i] == 58) {
				memset(temp, 0, 16);
				getsub(temp, message, start + 1, end + i - 1);
				start = end + i + 1;
			}
			else if (message[end + i] == 44) {
				std::string key(temp);
				memset(temp, 0, 64);
				getsub(temp, message, start + 1, end + i - 1);
				std::string data(temp);
				this->data.insert(std::pair<std::string, std::string>(key, data));
				this->data_len = this->data_len + 1;
				start = end + i + 1;
				j++;
			}
			if (i == cont_length - 2) {
				std::string key(temp);
				memset(temp, 0, 64);
				getsub(temp, message, start + 1, end + i - 1);
				std::string data(temp);
				this->data.insert(std::pair<std::string, std::string>(key, data));
				this->data_len = this->data_len + 1;
			}
		}
	}
	else {
		end = 0;
		while (this->path[end] != 0) {
			if (this->path[end] == 63) {
				start = end + 1;
			}
			if (this->path[end] == 61) {
				memset(temp, 0, 16);
				getsub(temp, this->path, start, end);
				start = end + 1;
			}
			else if (this->path[end] == 38) {
				std::string key(temp);
				memset(temp, 0, 64);
				getsub(temp, this->path, start, end);
				std::string data(temp);
				this->data.insert(std::pair<std::string, std::string>(key, data));
				this->data_len = this->data_len + 1;
				++j;
				start = end + 1;
			}
			else if (this->path[end + 1] == 0) {
				std::string key(temp);
				memset(temp, 0, 64);
				getsub(temp, this->path, start, end);
				std::string data(temp);
				this->data.insert(std::pair<std::string, std::string>(key, data));
				this->data_len = this->data_len + 1;
			}
			++end;
		}
	}
	free(temp);
	free(this->status_msg);
	this->status = 0;
}
http_reqana::http_reqana(char* message, int length) {
	int i, j = 0, start = 0, end, task = 543210, len = 0;
	char* temp;
	temp = (char *)malloc(70);
	for (i = 0;i < length;i++) {
		if (i + this->cont_length == length) {
			break;
		}
		memset(temp, 0, 64);
		if (message[i] == 32) {
			end = i;
			getsub(temp, message, start, end);
			if (task % 10 == 1) {
				end = i;
				this->status = 0;
				while (temp[j] != 0) {
					this->status = this->status * 10 + (temp[j] - 48);
					++j;
				}
			}
			if (task % 10 == 0) {
				task /= 10;
			}
			if (equal("Content-Length:", message, start, end)) {
				task = task * 10 + 40;
				task /= 10;
			}
			start = i + 1;
		}
		else if (message[i] == 10) {
			end = i - 1;
			if (task % 10 == 1) {
				memset(this->status_msg, 0, 64);
				getsub(this->status_msg, message, start, end);
				if (this->status > 399) {
					printf("error in the response message with error code: %d, error message: %s", this->status, this->status_msg);
					http_reqana();
					return;
				}
				task /= 10;
			}
			if (task % 10 == 6) {
				getsub(temp, message, start, end);
				while (temp[j] != 0) {
					len = len * 10 + temp[j] - 48;
					j++;
				}
				this->cont_length = len;
				task /= 10;
			}
			start = i + 1;
		}
	}
	start++;
	end = start;
	j = 0;
	this->data_len = 0;
	for (i = 0;i < this->cont_length - 1;i++) {
		if (message[end + i] == 58) {
			memset(temp, 0, 16);
			getsub(temp, message, start + 1, end + i - 1);
			start = end + i + 1;
		}
		else if (message[end + i] == 44) {
			std::string key(temp);
			memset(temp, 0, 64);
			getsub(temp, message, start + 1, end + i - 1);
			std::string data(temp);
			this->data.insert(std::pair<std::string, std::string>(key, data));
			this->data_len = this->data_len + 1;
			start = end + i + 1;
			j++;
		}
		if (i == cont_length - 2) {
			std::string key(temp);
			memset(temp, 0, 64);
			getsub(temp, message, start + 1, end + i - 1);
			std::string data(temp);
			this->data.insert(std::pair<std::string, std::string>(key, data));
			this->data_len = this->data_len + 1;
		}
	}
}
http_reqana::~http_reqana() {
	free(this->path);
	free(this->type);
	free(this->status_msg);
	this->cont_length = 0;
}
bool http_reqana::equal(const char* obe, const char* msg, int start, int end) {
	int i;
	for (i = 0;i < end - start;i++) {
		if (obe[i] != msg[start + i]) return false;
	}
	return true;
}
bool http_reqana::equal(const char* obe, char* msg, int start, int end) {
	int i;
	for (i = 0;i < end - start;i++) {
		if (obe[i] != msg[start + i]) return false;
	}
	return true;
}
void http_reqana::getsub(char* temp, char* msg, int start, int end) {
	if (start > end) return;
	int i;
	for (i = 0;i < end - start;i++) {
		temp[i] = msg[start + i];
	}
}
char* http_reqana::get_path() {
	return this->path;
}
int http_reqana::get_data(std::map<std::string, std::string>& outside) {
	std::map<std::string, std::string>::iterator   iter;
	for (iter = this->data.begin(); iter != this->data.end(); iter++) {
		outside.insert(std::pair<std::string, std::string>(iter->first, this->data[iter->first]));
	}
	return 0;
}
int http_reqana::get_length() {
	return this->cont_length;
}
int http_reqana::get_status() {
	return this->status;
}
char* http_reqana::get_sta_msg() {
	return this->status_msg;
}
char* http_reqana::get_type() {
	return this->type;
}
int http_reqana::get_data_len() {
	return this->data_len;
}