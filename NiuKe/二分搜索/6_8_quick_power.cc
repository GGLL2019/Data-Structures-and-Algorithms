/**
 * @brief 使用二分思想快速求k^N
 * @email xueliang2007@qq.com
 * @date  2019.10.08
 */


/*
 * 题目：
 *   如果更快的求一个整数k的n次方。如果两个整数相乘并得到结果的时间复杂度为O(1)，得到整数k的N次方的过程请实现时间复杂度为O(logN)的方法。
 *   给定k和n，请返回k的n次方，为了防止溢出，请返回结果Mod 1000000007的值。
 * 测试样例：
 *   2,3
 * 返回：
 *   8
 * */


class QuickPower {
public:
    int getPower(int k, int N) {
        long res = 1;
        long temp = k;
        int mod_value = 1000000007;

        while (N){
            if (N&1){
                res *= temp;
            }
            temp *= temp;

            res %= mod_value;
            temp %= mod_value;

            N = N >> 1;
        }

        return static_cast<int>(res);
    }
};