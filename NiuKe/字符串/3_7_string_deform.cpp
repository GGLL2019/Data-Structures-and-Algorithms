/**
 * @brief 字符串， 字符串位移
 * @email xueliang2007@qq.com
 * @date  2019.09.13
 */


/*
 * 题目：
 *   对于一个字符串，请设计一个算法，将字符串的长度为len的前缀平移到字符串的最后。
 *   给定一个字符串A和它的长度，同时给定len，请返回平移后的字符串。
 * 测试样例：
 *   "ABCDE",5,3
 * 返回：
 *   "DEABC"
 * */

#include <iostream>

using namespace std;

class Translation {
public:
    void string_weiyi(string &s, int sublen, int pos){
        if (sublen == 1)
            return ;

        for (int i=0; i<sublen/2; i++){
            char c = s[i+pos];
            s[pos+i] = s[sublen-1-i+pos];
            s[sublen-1-i+pos] = c;
        }
    }

    string stringTranslation(string s, int len, int i) {
        // write code here
        if (s.size() != len || i < 0 || i > len)
            return "";

        string_weiyi(s, i, 0);
        string_weiyi(s, len-i, i);
        for (int i = 0; i < len / 2; ++i) {
            char c = s[i];
            s[i] = s[len-1-i];
            s[len-1-i] = c;
        }
        return s;
    }
};

int main()
{
    return 0;
}
