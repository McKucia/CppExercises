
#include <iostream>
#include <vector>
#include <array>
#include <forward_list>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cstdint>

std::array<std::array<uint8_t, 10>, 3> generateNinja() {
    return {
        std::array<uint8_t, 10>{0, 0, 0, 1, 1, 2, 3, 0, 0, 0},
        {0, 0, 4, 4, 4, 1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2, 1, 2, 2, 2, 2}
    };
}

void print(const std::vector<std::string>& vec) {
	std::for_each(vec.begin(), vec.end(), [](std::string word) { std::cout << word << " "; });
	std::cout << '\n';
}

void print(std::deque<std::string>& deque) {
	std::for_each(deque.begin(), deque.end(), [](std::string word) { std::cout << word << " "; });
	std::cout << '\n';
}

void removeVowels(std::vector<std::string>& words)
{
	const std::string vowels = "aeiouAEIOU";

	for (auto& word : words) {
		word.erase(std::remove_if(word.begin(), word.end(), [&vowels](char c) {
			return vowels.find(c) != std::string::npos;
			}), word.end());
	};
}

std::deque<std::string> lengthSort(std::forward_list<std::string> words)
{
	words.sort([](std::string s1, std::string s2) {
		if (s1.length() == s2.length())
			return s1 < s2;

		return s1.length() < s2.length();
	});

	std::deque<std::string> sorted(words.begin(), words.end());
	return sorted;
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, 10>, 3>& grayscale)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressed;

    for (const auto& row : grayscale)
    {
        uint8_t curr = row[0];
        uint8_t cntr = 1;
        for (size_t i = 1; i < row.size(); i++) {
            if(row[i] != curr)
            {
                compressed.push_back(std::make_pair(curr, cntr));
                cntr = 1;
                curr = row[i];
            }
            else cntr++;
        }
        compressed.push_back(std::make_pair(curr, cntr));
    }

    return compressed;
}

int main()
{
    std::vector<std::string> words{ "abcde", "aabbbccabc", "qwerty" };

    removeVowels(words);
    print(words);

    std::forward_list<std::string> unsorted{ "Three", "One", "Four", "Two" };

    auto sorted = lengthSort(unsorted);
    print(sorted);

    auto ninja = generateNinja();
    auto compressed = compressGrayscale(ninja);

    for (const auto& com : compressed) {
        std::cout << "{" << (int)com.first << "," << (int)com.second << "}";
    }

    return 0;
}