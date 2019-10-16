/**
 * @brief 动态规划算法，利用二维数组，自下而生的计算结果.
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */


/*
 * 题目：
 *   有数组penny，penny中所有的值都为正数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，
 *   再给定一个整数aim(小于等于1000)代表要找的钱数，求换钱有多少种方法。给定数组penny及它的大小(小于等于50)，
 *   同时给定一个整数aim，请返回有多少种方法可以凑成aim。
 * 测试样例：
 *   [1,2,4],3,3
 * 返回：
 *   2
 * */

#include <iostream>
#include <vector>

using std::vector;

template <typename T>
void cout_vector(std::vector<T> vector_array) {
    for (auto v:vector_array) {
        std::cout << v << "\t";
    }
    std::cout << "\n";
}

class Exchange_BF {
public:
    typedef std::vector<int> i_vector;

    int countWays(i_vector penny, int size, int aim){
        return bf_method(penny, aim);
    }

private:
    int bf_method(i_vector penny, int aim){
        if (penny.empty() || aim <= 0)
            return 0;

        return bf_process(penny, 0, aim);
    }

    int bf_process(i_vector penny, int index, int aim){
        int res = 0;
        int size = penny.size();
        if (index == size){
            res = aim == 0 ? 1 : 0;
        } else{
            for (int i = 0; i*penny[index] <= aim; ++i) {
                res += bf_process(penny, index+1, aim-penny[index]*i);
            }
        }
        return res;
    }
};

class Exchange_Memory {
public:
    typedef std::vector<int> i_vector;
    typedef std::vector<i_vector> ii_vector;

    ii_vector memo;
    int countWays(i_vector penny, int size, int aim){
        if (penny.empty() || aim <= 0)
            return 0;

        memo = ii_vector(size+1);
        for (auto &m:memo) {
            m = i_vector(aim+1, 0);
        }

        int res = memo_process(penny, size, 0, aim);

        for (auto m:memo) {
            cout_vector(m);
        }

        return res;
    }

private:
    int memo_process(const i_vector &penny, int size, int index, int aim){
        int res = 0;
        if (index == size){
            if (aim == 0)
                res = 1;
        } else{
            int memo_ij = 0;
            for (int i = 0; i*penny[index] <= aim; ++i) {
                memo_ij = memo[index+1][aim - i*penny[index]];
                if (memo_ij != 0){
                    // if (memo_ij != -1) // TODO(xueliang2007@qq.com) 我认为这一行的判断是多余的，因为从未赋值-1给数组元素
                    res += memo_ij;  // 当前index-aim对应的方法数，之前计算过且已更新，所以直接使用即可
                } else{
                    // 之前的index-aim结果未计算过，计算并保存在memo中
                    res += memo_process(penny, size, index+1, aim-i*penny[index]);
                }
            }
        }

        if (res != 0)
            memo[index][aim] = res;

        return res;
    }
};

class Exchange_DP {
public:
    typedef std::vector<int> i_vector;
    typedef std::vector<i_vector> ii_vector;

    int countWays(i_vector penny, int size, int aim){
        if (penny.empty() || aim <= 0)
            return 0;

        ii_vector memo = ii_vector(size);
        for (auto &m:memo) {
            m = i_vector(aim+1, 0);
        }

        // 第一列设置为1， 表示使用钱包里的各种钱，组成金额为0的方法只有一种，那就是都不拿出来组成；
        for (auto &m:memo)
            m[0] = 1;

        // 第一行设置为1， 表示只使用第一种货币面额，能组成的金额；
        for (int i = 0; i <= aim; ++i) {
            if (i % penny[0] == 0) {
                memo[0][i] = 1;
            }
        }
        
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j <= aim; ++j) {
                if (j >= penny[i]){
                    // 可组成的金额需大于当前货币的面额
                    int method_nums_without_i = memo[i-1][j];  // 不使用当前面额的货币的情况
                    int method_nums_with_i = memo[i][j-penny[i]];  // 使用当前货币面额的货币的情况
                    memo[i][j] = method_nums_without_i + method_nums_with_i; // 状态转移方程
                } else{
                    // 可组成的金额始终小于当前货币面额时，不使用当前货币，只是用i-1之前的货币
                    memo[i][j] = memo[i-1][j];
                }
            }
        }


        for (auto m:memo) {
            cout_vector(m);
        }

        return memo[size-1][aim];
    }
};



int main(){
    std::cout << "兑换零钱的方法数" << std::endl;

    int aim = 12;
    std::vector<int> penny{2, 1, 5};

    // 暴力方法
    Exchange_BF exchange_bf;
    int res = exchange_bf.countWays(penny, penny.size(), aim);
    std::cout << "bf result:\t" << res << std::endl << std::endl;

    // 记忆化搜索方法
    Exchange_Memory exchange_memory;
    int res_memo = exchange_memory.countWays(penny, penny.size(), aim);
    std::cout << "memo result:\t" << res_memo << std::endl << std::endl;

    // 动态规划方法
    Exchange_DP exchange_dp;
    int res_dp = exchange_dp.countWays(penny, penny.size(), aim);
    std::cout << "memo result:\t" << res_dp << std::endl;

    return 0;
}