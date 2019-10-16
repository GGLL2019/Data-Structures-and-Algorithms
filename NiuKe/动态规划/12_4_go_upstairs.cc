/**
 * @brief 动态规划算法，上台阶问题，类似于斐波那契数列问题
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */


/*
 * 题目：
 *   有n级台阶，一个人每次上一级或者两级，问有多少种走完n级台阶的方法。为了防止溢出，请将结果Mod 1000000007
 *   给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100000。
 * 测试样例：
 *   1
 * 返回：
 *   1
 * */

#include <iostream>
#include <vector>

using std::vector;

const int kMod = 1000000007;


class GoUpstairs_BF {
public:
    int countWays(int n) {
        if (n <= 1)
            return 1;
        return (countWays(n-1) + countWays(n-2))%kMod;
    }
};

class GoUpstairs_Memo {
public:
    vector<int> memo;
    int countWays(int n) {
        memo = vector<int>(n+1, -1);
        return process(n);
    }

    int process(int n){
        if (memo[n] != -1)
            return memo[n];

        int res = 0;
        if (n <= 1)
            res = 1;
        else
            res += (process(n-1) + process(n-2))%kMod;

        memo[n] = res;
        return res;
    }
};

class GoUpstairs_DP {
public:
    int countWays(int n) {
        vector<int> memo(n+1, -1);
        memo[0] = 1;
        memo[1] = 1;
        for (int i = 2; i <= n; ++i) {
            memo[i] = (memo[i-1] + memo[i-2])%kMod;  // 状态转移方程
        }
        return memo[n];
    }
};


int main(){
    std::cout << "上楼梯的方法数" << std::endl;

    int n = 20;

    // 暴力方法
    GoUpstairs_BF goUpstairs_bf;
    int res = goUpstairs_bf.countWays(n);
    std::cout << "bf result:\t" << res << std::endl << std::endl;

    // 记忆化搜索方法
    GoUpstairs_Memo goUpstairs_memo;
    int res_memo = goUpstairs_memo.countWays(n);
    std::cout << "memo result:\t" << res_memo << std::endl << std::endl;

    // 动态规划方法
    GoUpstairs_DP goUpstairs_dp;
    int res_dp = goUpstairs_dp.countWays(n);
    std::cout << "memo result:\t" << res_dp << std::endl;

    return 0;
}