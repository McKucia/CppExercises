
#include <iostream>
#include <functional>

int saySomething(const std::string& something, int x)
{
	std::cout << something;
	return x + 2;
}

int invoker1(const std::string& something, int x, int(*func)(const std::string&, int))
{
	return func(something, x);
}

int invoker2(const std::string& something, int x, std::function<int(const std::string&, int)> func)
{
	return func(something, x);
}

int main()
{
	int x = 1;
	auto ss = saySomething("im", x);
	std::cout << ss << std::endl;

	auto value = invoker1("im", x, saySomething);
	std::cout << value;

	value = invoker2("im", x, saySomething);
	std::cout << value;

	value = invoker2("im", 1, [](const std::string& something, int x) {
		std::cout << something;
		return x + 5;
		});
	std::cout << value;
	return 0;
}