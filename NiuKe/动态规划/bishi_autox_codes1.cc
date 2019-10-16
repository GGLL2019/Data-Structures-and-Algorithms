/**
 * @brief 动态规划问题
 * @details AutoX 定位算法工程师笔试题一
 * @email xueliang2007@qq.com
 * @date  2019.10.12
 * */

/**
 * 题目
 *   输入两行字符串s和keypad,其中第二行大小为9,分布的九宫格中.（九宫格mat中,mat[i][j]本位置为0,相邻(包括斜对角相邻)的为1,其余的为2）.
 *   计算s[i]和s[i-1]在keypad中的距离，并求和
 * 样例输入：
 *   "423692","923857614"
 * 输出：
 *   8
 * */



#include <iostream>
#include <vector>
#include <map>

using std::string;
using std::map;
using std::vector;


int caculate_distance012(int i_hang, int i_lie, int j_hang, int j_lie){
    int res = 0;
    if (abs(i_hang-j_hang) == 0 && abs(i_lie-j_lie) == 0)
        res  = 0;
    else if ((abs(i_hang-j_hang) <= 1 && abs(i_lie-j_lie) <= 1))
        res = 1;
    else
        res = 2;
    return res;
}

int entryTime(string s, string keypad){
    // 对keypad建立哈希表映射
    map<char, int> hash;
    for (int i = 0; i < 9; ++i) {
        hash[keypad[i]] = i;
    }

    // 建立dp数组
    vector<vector<int>> dp(9, vector<int>(9, 0));
    int i_hang, i_lie, j_hang, j_lie;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            i_hang = i/3;
            j_hang = j/3;
            i_lie = i%3;
            j_lie = j%3;

            dp[i][j] = caculate_distance012(i_hang, i_lie, j_hang, j_lie);
        }
    }

    // 计算距离
    int len_s = s.length();
    int sum = 0;
    for (int i = 1; i < len_s; ++i) {
        char last = s[i-1];
        char curr = s[i];
        int pos_last = hash[last];
        int pos_curr = hash[curr];
        int dist = dp[pos_last][pos_curr];
        sum += dist;
    }
    return sum;
}


int main()
{
    string s;
    string keypad;
    getline(std::cin, s);
    getline(std::cin, keypad);

    int result = entryTime(s, keypad);
    std::cout << result << "\n";

    return 0;
}

