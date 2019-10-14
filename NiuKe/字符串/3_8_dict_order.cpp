/**
 * @brief 字符串， 拼接最小字典序
 * @email xueliang2007@qq.com
 * @date  2019.09.13
 */


/*
 * 题目：
 *   对于一个给定的字符串数组，请找到一种拼接顺序，
 *   使所有小字符串拼接成的大字符串是所有可能的拼接中字典序最小的。
 *   给定一个字符串数组strs，同时给定它的大小，请返回拼接成的串。
 * 测试样例：
 *   ["abc","de"],2
 * 结果：
 *   "abcde"
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Prior {
public:
    // 方法一
    string findSmallest1(vector<string> strs, int n) {
        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j < n-1; ++j) {
                string s0 = strs[j] + strs[j+1];
                string s1 = strs[j+1] + strs[j];

                if (s0 > s1){
                    swap(strs[j], strs[j+1]);
                }
            }
        }
        string s_final;
        for (auto s:strs) {
            s_final += s;
        }

        return s_final;
    }

    // 方法二
    string findSmallest2(vector<string> strs, int n) {
        sort(strs.begin(), strs.end(), [](string s0, string s1){if (s0+s1 > s1+s0) return false; else return true;});
        string s_final;
        for (auto s:strs)
            s_final += s;

        return s_final;
    }
};


int main()
{
    return 0;
}
