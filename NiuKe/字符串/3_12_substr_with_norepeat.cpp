/**
 * @brief 字符串， 最长无重复子串问题
 * @email xueliang2007@qq.com
 * @date  2019.09.13
 */


/*
 * 题目：
 *   对于一个字符串,请设计一个高效算法，找到字符串的最长无重复字符的子串长度。
 *   给定一个字符串A及它的长度n，请返回它的最长无重复字符子串长度。
 *   保证A中字符全部为小写英文字符，且长度小于等于500。
 * 测试样例：
 *   "aabcb",5
 * 返回：
 *   2
 * */

#include "../include/tools.h"
#include <cstring>

using namespace std;

class DistinctSubstring {
public:
    int longestSubstring1(string A, int n) {
        map<char, int> m;//哈希表存储 字符a上次出现的位置i
        int pre_index = -1;//字符i的前一个字符i-1的上次出现的位置
        int temp = 0;
        int res = 0;//最长无重复长度
        m[A[0]] = 0;//初始化第一个字符上次出现的位置就是0
        for (int i = 1; i < n; i++) {

            char ch = A[i];
            int cur;
            if (m.find(ch) != m.end()) {//在哈希表中寻找上次出现的位置 找不到则为-1
                cur = m[ch];
            } else {
                cur = -1;
            }
            /*
            比较当前字符i和i-1字符的上次的出现的位置，
            谁出现的位置更靠近i就用它计算长度.因为如果i-1字符上次出现的位置比i大，
            那么说明i字符没到上次它出现的位置就会因为i-1字符重复而失败(否则i-1字符上次出现的位置就不会比i的大)
            反之，则说明i字符可以到上次出现的字符的位置，在这中间i-1字符保证不会发生重复
            */
            if (pre_index > cur) {
                temp = i - pre_index;
            } else {
                temp = i - cur;
                pre_index = cur;//用了新的位置计算，所以更新pre_index
            }

            m[ch] = i;//更新字符ch上次出现的位置
            res = max(res, temp);
        }

        return res;
    }

    int longestSubstring2(string s, int len) {
        int hash[256];
        memset(hash, -1, 256* sizeof(int));

        int pre = -1;
        int max_len=-1;

        hash[s[0]] = 0;
        for (int i = 1; i < len; ++i) {
            char c_curr = s[i];
            int curr = hash[c_curr];

            int max_temp = 0;
            if (pre > curr){
                max_temp = i - pre;
            } else {
                max_temp = i - curr;
                pre = curr;
            }

            if (max_len < max_temp)
                max_len = max_temp;

            hash[c_curr] = i;
        }

        return max_len;
    }
};



int main()
{
    string s = "aabcb";
    DistinctSubstring distinctSubstring;
    int result1 = distinctSubstring.longestSubstring1(s, s.size());
    cout << result1 << endl;

    int result2 = distinctSubstring.longestSubstring2(s, s.size());
    cout << result2 << endl;

    return 0;
}
