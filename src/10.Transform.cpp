
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::vector<std::pair<int, std::string>> vec{
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"}
    };

    // konwersja na inny typ wektora
    std::vector<int> vec2(6);

    std::transform(vec.begin(), vec.end(), vec2.begin(), [](const auto& pair) {
            return pair.first;
        });

    auto print = [](const auto& vec) { 
            for (const auto& el : vec) 
                std::cout << el << ",";
            std::cout << std::endl;
        };

    print(vec2);

    // konwersja na stringa
    std::vector<std::string> vec3;
    std::transform(vec.begin(), vec.end(), std::back_inserter(vec3), [](const auto& pair) {
            return pair.second + " : " + std::to_string(pair.first);
        });

    print(vec3);

    // sumowanie wartości wektora i listy
    std::vector<int> vec4{ 1, 2, 3, 4, 5, 6, 7, 8 };
    std::list<int> list{ 10, 20, 30 , 40 , 50, 60, 70, 80 };

    std::transform(begin(vec4), end(vec4), begin(list), begin(vec4), [](auto first, auto second) {
            return first + second;
        });

    print(vec4);

    // zadanie
    std::vector<int> vec5(8);
    // from 1 to 15
    std::generate(vec5.begin(), vec5.end(), [i{ 1 }]() mutable {
            int res = i;
            i += 2;
            return res;
        });

    // reverse
    std::swap_ranges(vec5.begin(), std::next(vec5.begin() + (vec5.size() / 2) - 1), vec5.rbegin());

    print(vec5);

    std::list<int> lista;

    std::copy(vec5.begin(), vec5.end(), std::back_inserter(lista));

    std::vector<int> vec6(8);
    std::generate(vec6.begin(), vec6.end(), [i{ 0 }]() mutable {
        int res = i;
        i += 2;
        return res;
        });

    print(vec6);

    std::vector<int> vec7;
    std::for_each(vec5.rbegin(), vec5.rend(), [it{ vec6.begin() }, &vec7] (const auto& el) mutable {
            vec7.push_back(*it);
            vec7.push_back(el);
            it++;
        });

    // or
    // std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(vec7));

    print(vec7);

    return 0;
}