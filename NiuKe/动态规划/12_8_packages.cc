/**
 * @brief 动态规划算法，01背包问题
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */


/*
 * 题目：
 *   一个背包有一定的承重cap，有N件物品，每件都有自己的价值，记录在数组v中，也都有自己的重量，记录在数组w中，
 *   每件物品只能选择要装入背包还是不装入背包，要求在不超过背包承重的前提下，选出物品的总价值最大。
 *   给定物品的重量w价值v及物品数n和承重cap。请返回最大总价值。
 * 测试样例：
 *   [1,2,3],[1,2,3],3,6
 * 返回：
 *   6
 * */


#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Backpack_BF{
public:
    int maxValue(vector<int> w, vector<int> v, int n, int cap){
        if (n == 0)
            return 0;
        return process(w, v, n-1, cap);
    }

    int process(const vector<int> &w, const vector<int> &v, int index, int cap){
        if (cap <= 0 || index < 0)
            return 0;

        int res_with_curr = 0, res_without_curr = 0;
        res_without_curr = process(w, v, index-1, cap);  // 不考虑把当前物体放入背包
        if (cap >= w[index]){
            res_with_curr = v[index] + process(w, v, index-1, cap-w[index]);
        }

        int res = std::max(res_without_curr, res_with_curr);
        return res;
    }
};


class Backpack_Memo{
public:
    vector<vector<int>> memo;
    int maxValue(vector<int> w, vector<int> v, int n, int cap){
        if (n == 0)
            return 0;
        memo = vector<vector<int>>(n, vector<int>(cap+1, -1));
        return process(w, v, n-1, cap);
    }

    int process(const vector<int> &w, const vector<int> &v, int index, int cap){

        if (cap <= 0 || index < 0) {
            return 0;
        }

        if (memo[index][cap] != -1){
            return memo[index][cap];
        }

        int res_with_curr = 0, res_without_curr = 0;
        res_without_curr = process(w, v, index-1, cap);  // 不考虑把当前物体放入背包
        if (cap >= w[index]){
            res_with_curr = v[index] + process(w, v, index-1, cap-w[index]);  // 考虑把当前物体放入背包
        }

        int res = std::max(res_without_curr, res_with_curr);

        memo[index][cap] = res;

        return res;
    }
};


class Backpack_DP {
public:
    int maxValue(vector<int> w, vector<int> v, int n, int cap) {
        vector<vector<int>> dp(n, vector<int>(cap+1, 0));

        // 初始化第一行
        for (int j = 0; j < cap+1; ++j) {
            if (j >= w[0])
                dp[0][j] = v[0];
        }

        // 初始化第一列
        // 第一列元素已然全部为零，不用初始化

        // 填充其他部分
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < cap+1; ++j) {
                int v_without_i = dp[i-1][j];
                int v_with_i = 0;
                if (j-w[i] >= 0){
                    v_with_i = dp[i-1][j-w[i]]+v[i];
                }

                dp[i][j] = std::max(v_without_i, v_with_i);  // 状态转移方程
            }
        }

        for (auto d:dp){
            cout_vector(d);
        }

        return dp[n-1][cap];
    }

private:
    template <typename T>
    void cout_vector(std::vector<T> vector_array) {
        for (auto v:vector_array) {
            std::cout << v << "\t";
        }
        std::cout << "\n";
    }
};



int main(){
    std::cout << "01背包问题" << std::endl;

    vector<int> w{17,34,38,42,36}, v{335,406,160,452,311};
    int n = w.size();
    int cap = 90;

    Backpack_BF backpack_bf;
    int res_bf = backpack_bf.maxValue(w, v, n, cap);
    std::cout << "bf result:\t" << res_bf << std::endl << std::endl;

    Backpack_Memo backpack_memo;
    int res_memo = backpack_memo.maxValue(w, v, n, cap);
    std::cout << "memo result:\t" << res_memo << std::endl << std::endl;

    // 动态规划方法
    Backpack_DP backpack_dp;
    int res_dp = backpack_dp.maxValue(w, v, n, cap);
    std::cout << "dp result:\t" << res_dp << std::endl << std::endl;


    return 0;
}