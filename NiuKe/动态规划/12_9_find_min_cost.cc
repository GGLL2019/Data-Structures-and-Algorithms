/**
 * @brief 动态规划算法，计算字符串sa变换到字符串sb的最小代价
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */


/*
 * 题目：
 *   对于两个字符串A和B，我们需要进行插入、删除和修改操作将A串变为B串，定义c0，c1，c2分别为三种操作的代价，
 *   请设计一个高效算法，求出将A串变为B串所需要的最少代价。给定两个字符串A和B，及它们的长度和三种操作代价，
 *   请返回将A串变为B串所需要的最小代价。保证两串长度均小于等于300，且三种代价值均小于等于100。
 * 测试样例：
 *   "abc",3,"adc",3,5,3,100
 * 返回：
 *   8
 * */


#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class MinCost_DP {
public:
    int findMinCost(string sa, int n, string sb, int m, int ic, int dc, int rc) {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));  // dp[i][j]表示字符串sa[0:i-1]变换到sb[0:j-1]所需最小代价
        // 初始化第一行
        for (int j = 1; j < m+1; ++j) {
            dp[0][j] = ic*j;
        }

        // 初始化第一列
        for (int i = 1; i < n+1; ++i) {
            dp[i][0] = dc*i;
        }

        // 填充其他部分
        for (int i = 1; i < n+1; ++i) {  // 行
            for (int j = 1; j < m+1; ++j) {  // 列
                // 有四种情况
                int cost = std::min(dp[i-1][j]+dc, dp[i][j-1]+ic);  // 状态转移方程1
                if (sa[i-1] == sb[j-1])
                    cost = std::min(cost, dp[i-1][j-1]);  // 状态转移方程2
                else
                    cost = std::min(cost, dp[i-1][j-1]+rc);  // 状态转移方程3
                dp[i][j] = cost;
            }
        }

        for (auto d:dp){
            cout_vector(d);
        }

        return dp[n][m];
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
    std::cout << "字符串的最优编辑方法" << std::endl;

    string sa = "abc";
    string sb = "adc";
    int dc = 5, ic = 3, rc = 100;
    int n = sa.length();
    int m = sb.length();

    // 动态规划方法
    MinCost_DP minCost_dp;
    int res_dp = minCost_dp.findMinCost(sa, n, sb, m, ic, dc, rc);
    std::cout << "dp result:\t" << res_dp << std::endl << std::endl;


    return 0;
}