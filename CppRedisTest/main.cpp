#include <iostream>

#ifdef _WIN32
#include <Winsock2.h>
#endif

#include <cpp_redis/cpp_redis>

int main(void)
{
	WORD version = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(version, &data) != 0) {
		std::cerr << "WSAStartup() failure" << std::endl;
		return -1;
	}

	cpp_redis::client client;
	client.connect("127.0.0.1", 6379);

	if (true == client.is_connected())
	{
		std::cout << "Connected Succeed!!!" << std::endl;
		client.disconnect();

		if (false == client.is_connected())
		{
			std::cout << "Connected disconnected!!!" << std::endl;
		}
	}
	else
	{
		std::cout << "Connected Failed!!!" << std::endl;
	}
	
	return 0;
}