#include <iostream>
#include <thread>

#include "RedisWrapper.h"

std::vector<std::string> split(std::string target, std::string delimiter) {
	std::vector<std::string> result;
	int position = target.find(delimiter);

	while (position != -1) {
		std::string str1 = target.substr(0, position);
		result.push_back(str1);
		target = target.substr(position + 1);
		position = target.find(delimiter);
	}
	result.push_back(target);

	return result;
}

RedisWrapper redis;

void InputFunction(void)
{
	while (true)
	{
		std::string input_msg = "";

		std::cout << "Input : ";
		std::getline(std::cin, input_msg);

		std::cout << "InputMsg : " << input_msg << std::endl;

		std::vector<std::string> command = split(input_msg, " ");

		for (size_t i = 0; i < command.size(); ++i)
		{
			std::cout << i << ":" << command[i] << std::endl;
		}

		std::string result;

		if (command[0] == "get")
		{
			redis.Get(command[1], result);
			std::cout << "GET Result : " << result << std::endl;
		}
	};
}

int main(void)
{
	INIT_CPP_REDIS();

	
	redis.Init();
	if (false == redis.Connect("127.0.0.1"))
		return -1;

	std::thread input_thread = std::thread(InputFunction);
	input_thread.join();

	redis.DisConnect();
	
	CLEAR_CPP_REDIS();
	
	return 0;
}