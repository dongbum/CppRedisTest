#pragma once

#include <string>
#include <cpp_redis/cpp_redis>

#ifdef _WIN32
#include <Winsock2.h>
#endif

#define OUT

class RedisWrapper
{
public:
	RedisWrapper(void);
	virtual ~RedisWrapper(void);

	bool Init(void);
	bool Connect(std::string server_ip, unsigned short server_port = 6379);
	void DisConnect(void);

	void Set(std::string key, std::string value);
	bool Get(std::string key, OUT std::string& value);

private:
	cpp_redis::client	client_;
};
