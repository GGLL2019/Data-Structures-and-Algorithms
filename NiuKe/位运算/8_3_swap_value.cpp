/**
 * @brief 位运算，交换
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */


/*
 * 题目：
 *   请编写一个算法，不用任何额外变量交换两个整数的值。
 * */
#include <iostream>

using namespace std;

// 指针
void swap_two_nums(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 引用
void swap_two_nums(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// bit逻辑运算符操作
void swap_two_nums_by_bit(int &a, int &b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}

int main()
{
    int a = 3, b = 5;
    swap_two_nums(&a, &b);
    cout << a << b << endl;

    swap_two_nums(a, b);
    cout << a << b << endl;

    swap_two_nums_by_bit(a, b);
    cout << a << b << endl;

    return 0;
}
