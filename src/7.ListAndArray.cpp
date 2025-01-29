
#include <iostream>
#include <list>
#include <forward_list>
#include <array>
#include <algorithm>
#include <numeric>

void print(const std::list<int>& lista)
{
	std::for_each(lista.begin(), lista.end(), [] (int x) { std::cout << x << " "; });
	std::cout << '\n';
}

void print(const std::array<int, 8>& tablica)
{
	std::for_each(tablica.begin(), tablica.end(), [](int x) { std::cout << x << " "; });
	std::cout << '\n';
}

void print(const std::forward_list<int>& forward_lista)
{
	std::for_each(forward_lista.begin(), forward_lista.end(), [](int x) { std::cout << x << " "; });
	std::cout << '\n';
}

int main()
{
	std::list<int> lista(6);
	std::iota(lista.begin(), lista.end(), 0);

	print(lista);

	auto it = lista.begin();
	std::advance(it, 2);
	lista.erase(it);

	print(lista);

	lista.push_front(10);
	lista.push_back(10);

	print(lista);

	it = std::next(lista.begin(), 3);
	lista.insert(it, 20);

	print(lista);

	std::array<int, 8> list_copy;
	std::copy(lista.begin(), lista.end(), list_copy.begin());

	print(list_copy);

	std::forward_list<int> forward_lista(6);
	std::iota(forward_lista.begin(), forward_lista.end(), 0);

	print(forward_lista);

	forward_lista.erase_after(std::next(forward_lista.begin(), 1));

	print(forward_lista);

	forward_lista.push_front(10);

	auto iter = forward_lista.begin();
	auto iter2 = forward_lista.before_begin();
	while (iter != forward_lista.end())
	{
		iter++;
		iter2++;
	}
	forward_lista.insert_after(iter2, 10);

	print(forward_lista);

	return 0;
}