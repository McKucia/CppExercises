
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

/*
Napisz funkcję, która przyjmie std::vector<int>&, zmienną int value, oraz zmienną int new_pos. 
Funkcja powinna odnaleźć value w std::vector<int> i jeżeli ją znajdzie wstawić ją na nowe miejsce new_pos, 
odpowiednio przesuwając resztę elementów by nie zaburzyć ich sekwencji. Następnie zwróć true, 
jeżeli proces się udał, lub false, jeżeli nie dało się zmienić kolejności (np. nie istnieje wartość).
*/

bool changePos(std::vector<int>& vec, int value, int new_pos)
{
	if (new_pos >= vec.size() || new_pos < 0)
		return false;

	auto it = std::find(vec.begin(), vec.end(), value);

	if (it == vec.end()) 
		return false;

	auto item_pos = std::distance(vec.begin(), it);

	if(item_pos > new_pos)
		std::rotate(vec.begin() + new_pos, vec.begin() + item_pos, vec.begin() + item_pos + 1);
	else
		std::rotate(it, it + 1, vec.begin() + new_pos);

	return true;
}

/*
Napisz funkcję GetVec(size_t count), która zwróci std::vector<int> z wartościami od 10 do 10 + n,
inkrementując je co 1. Następnie napisz drugą funkcję int Multiply(std::vector<int> vec), 
która zwróci wartość równą iloczynowi każdego elementu std::vector<int>.

Input: GetVec(7)

Output: {10, 11, 12, 13, 14, 15, 16}

Input: Multiply(vec)

Output: 57657600
*/

std::vector<int> getVec(size_t count)
{
	std::vector<int> new_vec(count);
	//std::iota(new_vec.begin(), new_vec.end(), 10);
	// or
	std::generate(new_vec.begin(), new_vec.end(), [i{ 10 }]() mutable { return i++; });
	return new_vec;
}

int multiply(std::vector<int> vec)
{
	return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
	// or
	//return std::accumulate(vec.begin(), vec.end(), 1, [](int lhs, int rhs) { return lhs * rhs; });
}

int main()
{
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
	changePos(vec, 2, 7);

	std::cout << multiply(getVec(7));
	return 0;
}