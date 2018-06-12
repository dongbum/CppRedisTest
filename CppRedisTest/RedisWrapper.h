#pragma once

#include <string>
#include <cpp_redis/cpp_redis>

#ifdef _WIN32
#include <Winsock2.h>
#endif

#define OUT

#define INIT_CPP_REDIS() WORD version = MAKEWORD(2, 2); \
WSADATA data; \
if (WSAStartup(version, &data) != 0) { \
	std::cerr << "WSAStartup() failure" << std::endl; \
}

#define CLEAR_CPP_REDIS() WSACleanup();

class RedisWrapper
{
public:
	enum RedisReturnType
	{
		REDIS_ERROR = 0,
		REDIS_
	};

public:
	RedisWrapper(void);
	virtual ~RedisWrapper(void);

	bool Init(void);
	bool Connect(std::string server_ip, unsigned short server_port = 6379);
	void DisConnect(void);

	template<typename T>void Set(const std::string key, const T value);

	bool Get(std::string key, OUT std::string& value);

private:
	cpp_redis::client	client_;
};


