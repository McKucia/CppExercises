
#include <mutex>
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <functional>

class Shared_data
{
private:
	int counter = 0;
	std::mutex mtx;
public:
	void increment()
	{
		std::lock_guard<std::mutex> g(mtx);
		counter++;
		std::cout << counter << '\n';
	}
};

struct increment
{
	void operator()(Shared_data& data)
	{
		data.increment();
	}
};

int main()
{
	Shared_data shared_data;

	int num_threads = 5;
	std::vector<std::thread> threads;

	for (int i = 0; i < num_threads; i++)
	{
		threads.emplace_back(increment(), std::ref(shared_data));
	}

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	return 0;
}