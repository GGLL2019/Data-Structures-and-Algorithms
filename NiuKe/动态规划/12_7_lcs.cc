/**
 * @brief 动态规划算法，字符串的最长公共子序列
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */


/*
 * 题目：
 *   给定两个字符串A和B，返回两个字符串的最长公共子序列的长度。例如，A="1A2C3D4B56”，B="B1D23CA45B6A”，
 *   ”123456"或者"12C4B6"都是最长公共子序列。给定两个字符串A和B，同时给定两个串的长度n和m，请返回最长公共子序列的长度。
 *   保证两串长度均小于等于300。
 * 测试样例：
 *   "1A2C3D4B56",10,"B1D23CA45B6A",12
 * 返回：
 *   6
 * */


#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;


class LCS_DP {
public:
    int findLCS(string sa, int n, string sb, int m) {
        vector<vector<int>> dp(n, vector<int>(m, 1));
        // 初始化第一行
        for (int i = 0; i < m; ++i) {
            if (sa[0] != sb[i])
                dp[0][i] = 0;
            else
                break;
        }

        // 初始化第一列
        for (int i = 0; i < n; ++i) {
            if (sa[i] != sb[0])
                dp[i][0] = 0;
            else
                break;
        }

        // 填补其他位置
        int dp_iminus1_j = 0, dp_i_jminus1 = 0, dp_ij = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp_iminus1_j = dp[i-1][j];
                dp_i_jminus1 = dp[i][j-1];
                dp_ij = dp[i-1][j-1] + (sa[i] == sb[j] ? 1 : 0);
                dp[i][j] = max3(dp_iminus1_j, dp_i_jminus1, dp_ij);  // 状态转移方程
            }
        }

        for (auto d:dp){
            cout_vector(d);
        }

        return dp[n-1][m-1];
    }

private:

    template <typename T>
    inline T max3(T a, T b, T c){
        return std::max(std::max(a, b), c);
    }

    template <typename T>
    void cout_vector(std::vector<T> vector_array) {
        for (auto v:vector_array) {
            std::cout << v << "\t";
        }
        std::cout << "\n";
    }

};

int main(){
    std::cout << "最长上升子序列问题" << std::endl;

    string sa = "1A2C3D4B56";
    string sb = "B1D23CA45B6A";
    int n = sa.length(), m = sb.length();

    // 动态规划方法
    LCS_DP lcs_dp;
    int res_dp = lcs_dp.findLCS(sa, n, sb, m);
    std::cout << "dp result:\t" << res_dp << std::endl << std::endl;


    return 0;
}