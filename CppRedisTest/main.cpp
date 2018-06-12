#include <iostream>
#include <thread>

#include "RedisWrapper.h"

int main(void)
{
	// 윈속 초기화
	// tacopie 시스템상 client가 호출되기전 무조건 호출되어야 함.
	WORD version = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(version, &data) != 0) {
		std::cerr << "WSAStartup() failure" << std::endl;
	}
	//

	static auto InputFunction = []()
	{
		while (true)
		{
			std::string input_msg = "";
			std::getline(std::cin, input_msg);

			std::cout << "InputMsg : " << input_msg << std::endl;
		};
	};

	std::thread input_thread = std::thread(InputFunction);

	RedisWrapper redis;
	redis.Init();
	if (false == redis.Connect("127.0.0.1"))
		return -1;

	redis.DisConnect();
	
	input_thread.join();

	WSACleanup();	// tacopie 시스템상 제일 마지막에 호출 필요.
	
	return 0;
}