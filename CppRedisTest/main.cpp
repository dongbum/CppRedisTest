#include <iostream>
#include <thread>

#include "RedisWrapper.h"

int main(void)
{
	

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
	
	return 0;
}