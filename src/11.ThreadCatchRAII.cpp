
#include <thread>
#include <iostream>
#include <vector>

struct func
{
	int& i;

	func(int& i_) : i(i_){}

	void operator()()
	{
		unsigned sum = 0;
		for (unsigned j = 0; j < 10000; j++)
		{
			sum++;
			std::cout << sum << std::endl;
		}
	}
};

class thread_guard
{
	std::thread& t;

public:
	thread_guard(std::thread& t_) : t(t_){}
	~thread_guard()
	{
		if (t.joinable())
		{
			t.join();
			std::cout << "joined";
		}
	}
	thread_guard(thread_guard const&) = delete;
	thread_guard& operator=(thread_guard const&) = delete;
};

void exception_fun() {
	throw std::invalid_argument("test");
}

int main()
{
	int some_local_state = 0;
	std::thread my_thread(func{ some_local_state });
	thread_guard g(my_thread);
	exception_fun(); // w przypadku rzucenia wyjątku, kod idzie w górę. Wywołuje się destruktor thread_guard który joinuje wątek - elegancko

	return 0;
}