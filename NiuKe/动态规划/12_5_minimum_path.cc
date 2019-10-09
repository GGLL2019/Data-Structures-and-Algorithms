/**
 * @brief 动态规划算法，矩阵最短路径问题
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */


/*
 * 题目：
 *   有一个矩阵map，它每个格子有一个权值。从左上角的格子开始每次只能向右或者向下走，最后到达右下角的位置，
 *   路径上所有的数字累加起来就是路径和，返回所有的路径中最小的路径和。给定一个矩阵map及它的行数n和列数m，
 *   请返回最小路径和。保证行列数均小于等于100.
 * 测试样例：
 *   [[1,2,3],[1,1,1]],2,3
 * 返回：
 *   4
 * */

#include <iostream>
#include <vector>

using std::vector;

typedef vector<int> i_vector;
typedef vector<i_vector> ii_vector;


template <typename T>
void cout_vector(std::vector<T> vector_array) {
    for (auto v:vector_array) {
        std::cout << v << "\t";
    }
    std::cout << "\n";
}


class MinimumPath_BF {
public:
    int getMin(vector<vector<int> > map, int m, int n) {
        return process(map, m-1, n-1);
    }

    int process(const vector<vector<int>> &map, int m, int n){
        int cost = 0;
        if (m == 0 && n == 0)
            cost = map[0][0];
        else if (m == 0 && n != 0)
            cost = map[0][n] + process(map, 0, n-1);
        else if (m != 0 && n == 0)
            cost = map[m][0] + process(map, m-1, 0);
        else
            cost = map[m][n] + std::min(process(map, m-1, n), process(map, m, n-1));
        return cost;
    }
};

class MinimumPath_Memo {
public:
    ii_vector memo;
    int getMin(vector<vector<int>> map, int m, int n) {
        memo = ii_vector(m, i_vector(n, -1));
        return process(map, m-1, n-1);
    }

    int process(const vector<vector<int>> &map, int m, int n){
        if (memo[m][n] != -1)
            return memo[m][n];

        int cost = 0;
        if (m == 0 && n == 0)
            cost = map[0][0];
        else if (m == 0 && n != 0)
            cost = map[0][n] + process(map, 0, n-1);
        else if (m != 0 && n == 0)
            cost = map[m][0] + process(map, m-1, 0);
        else
            cost = map[m][n] + std::min(process(map, m-1, n), process(map, m, n-1));

        memo[m][n] = cost;
        return cost;
    }
};


class MinimumPath_DP {
public:
    int getMin(vector<vector<int> > map, int m, int n) {
        ii_vector cost = ii_vector(m, i_vector(n, -1));
        // 初始化代价图的第一行
        cost[0][0] = map[0][0];
        for (int i = 1; i < n; ++i) {
            cost[0][i] = cost[0][i-1] + map[0][i];
        }

        // 初始化路径代价的第一列
        for (int i = 1; i < m; ++i) {
            cost[i][0] = cost[i-1][0] + map[i][0];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                cost[i][j] = map[i][j] + std::min(cost[i-1][j], cost[i][j-1]);
            }
        }

        for (auto m:cost) {
            cout_vector(m);
        }

        return cost[m-1][n-1];

    }
};

int main(){
    std::cout << "矩阵中最短路径问题" << std::endl;

    int m = 6, n = 6;
    ii_vector map = {{1, 3, 5, 9, 3, 1},
                     {8, 1, 4, 3, 2, 6},
                     {5, 0, 6, 1, 4, 0},
                     {8, 8, 4, 0, 6, 4},
                     {5, 1, 2, 3, 4, 0},
                     {8, 0, 2, 6, 1, 2}};

    // 暴力方法
    MinimumPath_BF minimumPath_bf;
    int res = minimumPath_bf.getMin(map, m, n);
    std::cout << "bf result:\t" << res << std::endl << std::endl;

    // 记忆化搜索方法
    MinimumPath_Memo minimumPath_memo;
    int res_memo = minimumPath_memo.getMin(map, m, n);
    std::cout << "memo result:\t" << res_memo << std::endl << std::endl;

    // 动态规划方法
    MinimumPath_DP minimumPath_dp;
    int res_dp = minimumPath_dp.getMin(map, m, n);
    std::cout << "memo result:\t" << res_dp << std::endl;



    return 0;
}