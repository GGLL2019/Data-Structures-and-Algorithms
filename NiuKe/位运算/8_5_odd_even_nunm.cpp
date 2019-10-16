/**
 * @brief 位运算，数组中出现奇数次的数字(数组中有一个数出现过奇数次)
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */


/*
 * 题目：
 *   有一个整型数组A，其中只有一个数出现了奇数次，其他的数都出现了偶数次，请打印这个数。要求时间复杂度为O(N)，额外空间复杂度为O(1)。
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
    int arr[] = {3,3,5,5,4};
    int N = sizeof(arr)/ sizeof(int);

    // 计算所有元素的异或结果
    int res = arr[0];
    for (int i = 1; i < N; ++i) {
        res ^= arr[i];
    }
    cout << "num:\t" << res << endl;

    return 0;
}
