
#include <iostream>
#include <algorithm>

bool checkPalindrome(std::string word)
{
	word.erase(std::remove_if(word.begin(), word.end(), 
		[](char& c) { return std::isspace(c) || !std::isalpha(c); }), 
		word.end());

	return std::equal(word.begin(), std::next(word.begin(), word.size() / 2), word.rbegin());
}

int main()
{
	std::cout << checkPalindrome("ko,by lamam $al^y[bok");
    return 0;
}