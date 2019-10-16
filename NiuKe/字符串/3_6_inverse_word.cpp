/**
 * @brief 字符串， 字符串逆序
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

using namespace std;

class Reverse {
public:
    string word_inverse(string w, int n){
        for (int i = 0; i < n/2; ++i) {
            char c = w[i];
            w[i] = w[n-1-i];
            w[n-1-i] = c;
        }
        return w;
    }

    string reverseSentence(string word, int n) {
        string w_inv = word_inverse(word, n);
        int space_pos = 0;
        for (int i = 1; i < n; ++i) {
            if (w_inv[i] == ' '){
                string temp = w_inv.substr(space_pos, i-space_pos);
                string temp_inv = word_inverse(temp, temp.size());
                for (int j = 0; j < temp.size(); ++j) {
                    w_inv[space_pos+j] = temp_inv[j];
                }
                space_pos = i+1;
            }
        }
        string temp = w_inv.substr(space_pos, n-space_pos);
        string temp_inv = word_inverse(temp, temp.size());
        for (int j = 0; j < temp.size(); ++j) {
            w_inv[space_pos+j] = temp_inv[j];
        }

        return w_inv;
    }
};


int main()
{
    return 0;
}
