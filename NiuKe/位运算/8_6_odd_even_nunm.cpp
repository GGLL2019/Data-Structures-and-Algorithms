/**
 * @brief 位运算，数组中出现奇数次的数字(数组中有两个数出现过奇数次)
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */


/*
 * 题目：
 *   给定一个整型数组arr，其中有两个数出现了奇数次，其他的数都出现了偶数次，找到这两个数。
 *   要求时间复杂度为O(N)，额外空间复杂度为O(1)。
 *   给定一个整形数组arr及它的大小n，请返回一个数组，其中两个元素为两个出现了奇数次的元素,请将他们按从小到大排列。
 *
 * */

#include <iostream>
#include <algorithm>

using namespace std;


/*
 * 一个数组，只有一个数字出现了奇数次，其他的都是偶数次，求出这个奇数的数字，空间复杂度为O(1),时间复杂度为O(N)
 *
 * n^0 = n
 * n^n = 0
 * 并且，异或满足交换律和结合律
 * */

int main()
{
    int arr[] = {3,5,4,3,4,8};
    int N = sizeof(arr)/ sizeof(int);

    // 计算所有元素的异或结果
    int res = arr[0];
    for (int i = 1; i < N; ++i) {
        res ^= arr[i];
    }

    // 根据结果res中某一位上为1，声明变量i
    int i = 0x01;
    while (!(res & i)){
        i = i << 1;
    }

    int a_hat;
    for (int j = 0; j < N; ++j) {
        if (arr[j] & i)
            a_hat = a_hat^arr[j];
    }
    cout << "first num:\t" << a_hat << endl;

    int b_hat = a_hat^res;
    cout << "first num:\t" << b_hat << endl;


    return 0;
}
