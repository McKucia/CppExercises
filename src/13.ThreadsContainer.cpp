
#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <functional>

class Bazowa
{
public:
	explicit Bazowa()
	{
		std::cout << "ctor";
	}
};



int main()
{
	std::vector<std::thread> threads;

	auto fun = [](const auto& word) { std::cout << word; };

	std::thread firstThread(fun, "1");

	// threads.push_back(firstThread); - NIE MOZNA KOPIOWAC
	threads.push_back(std::move(firstThread));
	threads.push_back(std::thread(fun, "2"));
	threads.emplace_back(fun, "3");

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	std::cout << std::endl << std::thread::hardware_concurrency() << std::endl;

	return 0;
}