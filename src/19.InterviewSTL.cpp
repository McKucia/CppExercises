
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <climits> 

std::pair<int, int> twoSum(const std::vector<int>& nums, int target)
{
	std::unordered_set<int> set;

	int i = 0;
	for (const auto& el : nums)
	{
		auto second = set.find(target - el);

		if (second != set.end())
			return std::make_pair(i, std::distance(set.begin(), second));
		i++;

		set.insert(el);
	}
}

int findLongestSubstring(const std::string& s)
{
    if (s.length() == 0 || s.length() == 1)
        return s.length();

    int left = 0, right = 0;
    int maxLength = 0;
    std::unordered_set<char> charSet;

    while (right < s.length()) {
        while (charSet.count(s[right]) > 0) {
            charSet.erase(s[left]);
            left++;
        }

        charSet.insert(s[right]);
        right++;

        maxLength = std::max(maxLength, right - left);
    }

    return maxLength;
}

int searchInsert(std::vector<int>&& nums, int target) {
    
    int left = 0, right = nums.size() - 1, middle;

    while (left <= right)
    {
        middle = left + (right - left) / 2;

        if (target == nums[middle])
            return middle;
        else if (target < nums[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }
    return left;
}

int calculateCost(std::vector<std::vector<int>>& dp, const std::vector<int>& cuts, const int& l, const int& r)
{
    if (r - l == 0)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    int result = INT_MAX;
    for (const auto& cut : cuts)
    {
        if(cut < r && cut > l)
            result = std::min(result, r - l + 
                calculateCost(dp, cuts, l, cut) +
                calculateCost(dp, cuts, cut, r));
    }

    result = result == INT_MAX ? 0 : result;
    dp[l][r] = result;
    return result;
}

int minimalCost(std::vector<int>& cuts, const int& n)
{
    cuts.push_back(0);
    cuts.push_back(n);
    std::sort(cuts.begin(), cuts.end());
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, -1));
    return calculateCost(dp, cuts, 0, n);
}

void rotateSTL(std::vector<int>& nums, int k) {
    k = k % nums.size();
    if (k == 0 || nums.size() <= 1)
        return;

    std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
}

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<int> rotated(n);

    for (int i = 0; i < n; i++)
        rotated[(i + k) % n] = nums[i];

    nums = rotated;
}

int main()
{
	std::vector<int> nums{ 0, -1, 2, -3, 1 };
	auto res = twoSum(nums, -2);

	std::cout << res.first << " " << res.second << std::endl;
	std::cout << findLongestSubstring("dvdf") << std::endl;
    std::cout << searchInsert(std::vector<int>{1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 13}, 5) << std::endl;

    std::vector<int> cuts{ 1, 3, 4, 5 };
    int minCost = minimalCost(cuts, 7);

    std::cout << minCost << std::endl;

    std::vector<int> rotated{ 1,2,3,4,5,6,7 };
    rotate(rotated, 3);
    return 0;
}
