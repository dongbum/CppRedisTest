#include <iostream>
#include <thread>



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
		// input_thread.join();

		while (true)
		{
			/*
			// data insert
			client.set("key_1", "value_aaaa");
			client.set("key_2", "value_bbbb");

			// sync
			client.sync_commit();

			// data get
			client.get("key_1", [](cpp_redis::reply& reply) {
				std::cout << reply << std::endl;
			});
			*/

			// sync
			client.sync_commit();
			std::cout << "sync_commit()" << std::endl;

			Sleep(2000);
		}

		
	}
	else
	{
		std::cout << "Connected Failed!!!" << std::endl;
	}
	
	return 0;
}