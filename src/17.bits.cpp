
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <cmath>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        int bit = n & 1;    
        result = (result << 1) | bit;
        n = n >> 1;       
    }
    return result;
}

void printBinary(uint32_t num) {
    for (int i = 32; i >= 0; --i) {
        std::cout << ((num >> i) & 1);
    }
    std::cout << std::endl;
}

std::string addBinary(std::string a, std::string b) {
    int ia = a.size() - 1, ib = b.size() - 1, carry = 0;
    std::string result = "";

    while (ia >= 0 || ib >= 0 || carry) {
        int a_val = ia >= 0 ? a[ia--] - '0' : 0;
        int b_val = ib >= 0 ? b[ib--] - '0' : 0;
        int sum = a_val + b_val + carry;
        carry = sum / 2;
        result += (sum % 2) + '0';
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int rangeBitwiseAnd(int left, int right) {
    int i = 0;
    const uint32_t left_flag = std::pow(2, 31);
    uint32_t result = 0;

    for (i = 0; i < 32; i++)
    {
        auto costam = left & left_flag;
        auto costam2 = right & left_flag;
        if ((left & left_flag) == (right & left_flag))
            result = (result << 1) | ((left & left_flag) > 0 ? 1 : 0);
        else
            break;
        left = left << 1;
        right = right << 1;
    }

    for (; i < 32; i++)
    {
        result = (result << 1) | 0;
    }
    return result;
}

int main()
{
    uint32_t num = 0b00000010100101000001111010011100;
    uint32_t res = reverseBits(num);
    printBinary(res);

    std::string a = "1111";
    std::string b = "1111";
    std::cout << addBinary(a, b) << std::endl;

    std::cout << rangeBitwiseAnd(5, 7);
    return 0;
}