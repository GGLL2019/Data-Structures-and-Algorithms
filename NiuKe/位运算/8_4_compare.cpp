/**
 * @brief 位运算，比较
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */


/*
 * 题目：
 *   对于两个32位整数a和b，请设计一个算法返回a和b中较大的。但是不能用任何比较判断。
 *   若两数相同，返回任意一个。给定两个整数a和b，请返回较大的数。
 * */

#include <iostream>
#include <algorithm>

using namespace std;


int32_t flip(int32_t n)
{
    return n^1;
}

int32_t sign(int32_t n)
{
    return flip((n>>31)&1);
}

int32_t get_max(int32_t a, int32_t b)
{
    int32_t c = a - b;
    int32_t sc_a = sign(c);
    int32_t sc_b = flip(sc_a);
    return a*sc_a + b*sc_b;
}

int main()
{
    int32_t a = 3, b = 5;
    int32_t c = get_max(a, b);
    cout << c << endl;

    return 0;
}
