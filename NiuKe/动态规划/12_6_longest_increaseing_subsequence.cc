/**
 * @brief 动态规划算法，最长上升子序列问题
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */


/*
 * 题目：
 *   这是一个经典的LIS(即最长上升子序列)问题，请设计一个尽量优的解法求出序列的最长上升子序列的长度。
 *   给定一个序列A及它的长度n(长度小于等于500)，请返回LIS的长度。
 * 测试样例：
 *   [1,4,2,5,3],5
 * 返回：
 *   3
 * */


#include <iostream>
#include <vector>
#include <limits.h>

using std::vector;


template <typename T>
void cout_vector(std::vector<T> vector_array) {
    for (auto v:vector_array) {
        std::cout << v << "\t";
    }
    std::cout << "\n";
}


class LongestIncreasingSubsequence_BF{
private:
    int process(vector<int>&arr, int pre_value, int curr_val)
    {
        if (curr_val == arr.size())
            return 0;

        int taken = 0;
        if (arr[curr_val] > pre_value)
            taken = 1 + process(arr, arr[curr_val], curr_val + 1);

        int nottaken = process(arr, pre_value, curr_val + 1);
        return std::max(taken, nottaken);
    }

public:
    int getLIS(vector<int>& arr) {
        return process(arr, INT_MIN, 0);
    }
};


class LongestIncreasingSubsequence_Memo{
private:
    int process(vector<int>&arr, int index)
    {
        if (index == 0)
            return 1;

        if (memo[index] != -1)
            return memo[index];

        int res = 0;
        res += process(arr, index-1) + (arr[index] > arr[index-1] ? 1 : 0);
        memo[index] = res;
        cnt++;

        return res;
    }

public:
    int cnt = 0;
    vector<int> memo;
    int getLIS(vector<int>& arr)
    {
        memo = vector<int>(arr.size(), -1);
        memo[0] = 1;
        process(arr, arr.size()-1);

        int res = 1;
        for (int i = 0; i < arr.size(); ++i) {
            res = std::max(res, memo[i]);
        }

        return res;
    }
};


class LongestIncreasingSubsequence_DP {
public:
    int getLIS(vector<int> arr, int n) {
        if (n <= 1)
            return n;

        // memo[i] 表示以i为结尾的元素的最长生序子序列长度
        vector<int> memo(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // memo[i] = (memo[i], (arr[j] < arr[i] ? 1 : 0) + memo[j]);
                if (arr[j] < arr[i]){
                    memo[i] = std::max(memo[i], 1 + memo[j]);
                }
            }
        }

        int res = memo[0];
        for (int i = 1; i < n; ++i) {
            res = std::max(res, memo[i]);
        }

        return res;
    }
};

int main(){
    std::cout << "最长上升子序列问题" << std::endl;

    int n = 6;
    vector<int> arr = {1, 3, 5, 4, 3, 6};

    // 动态规划方法
    LongestIncreasingSubsequence_BF longestIncreasingSubsequence_bf;
    int res_bf = longestIncreasingSubsequence_bf.getLIS(arr);
    std::cout << "bf result:\t" << res_bf << std::endl << std::endl;

    // 动态规划方法
    LongestIncreasingSubsequence_Memo longestIncreasingSubsequence_memo;
    int res_memo = longestIncreasingSubsequence_memo.getLIS(arr);
    std::cout << "memo result:\t" << res_memo << std::endl << std::endl;

    // 动态规划方法
    LongestIncreasingSubsequence_DP longestIncreasingSubsequence_dp;
    int res_dp = longestIncreasingSubsequence_dp.getLIS(arr, n);
    std::cout << "dp result:\t" << res_dp << std::endl << std::endl;


    return 0;
}