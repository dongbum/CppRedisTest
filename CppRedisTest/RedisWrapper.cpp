#include "RedisWrapper.h"

RedisWrapper::RedisWrapper(void)
	: client_()
{

	WORD version = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(version, &data) != 0) {
		std::cerr << "WSAStartup() failure" << std::endl;
	}
}

RedisWrapper::~RedisWrapper(void)
{
	WSACleanup();
}

bool RedisWrapper::Init(void)
{
	return true;
}

bool RedisWrapper::Connect(std::string server_ip, unsigned short server_port /* = 6379 */)
{
	client_.connect(server_ip, server_port);

	if (false == client_.is_connected())
	{
		std::cout << "Connected Error!!!" << std::endl;
		return false;
	}

	std::cout << "Connected Succeed!!!" << std::endl;

	return true;
}

void RedisWrapper::DisConnect(void)
{
	client_.disconnect();

	if (false == client_.is_connected())
	{
		std::cout << "Connected disconnected!!!" << std::endl;
	}
}

template<typename T>
inline void RedisWrapper::Set(const std::string key, const T value)
{
	client_.set(key, std::string(value));
	client_.sync_commit();
}

bool RedisWrapper::Get(std::string key, OUT std::string& value)
{
	cpp_redis::reply reply = client_.get(key).get();

	if (reply.is_error())
	{
		std::cout << "Data Error!!!" << std::endl;
		return false;
	}

	/*
	client_.get(key, [](cpp_redis::reply& reply) {
		value = reply.as_string();
		return true;
	});
	*/

	return false;
}
