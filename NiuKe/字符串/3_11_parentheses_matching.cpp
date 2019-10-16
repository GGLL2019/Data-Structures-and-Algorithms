/**
 * @brief 字符串， 最长无重复子串问题
 * @email xueliang2007@qq.com
 * @date  2019.09.13
 */


/**
 * 题目：
 *   对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。给定一个字符串A和它的长度n，
 *   请返回一个bool值代表它是否为一个合法的括号串。
 * */

#include <iostream>

using namespace std;

class Parenthesis {
public:
    bool chkParenthesis(string s, int n) {
        // write code here
        if (s.size() != n)
            return false;

        int num = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ')'){
                num--;
            } else if (s[i] == '('){
                num++;
            } else{
                return false;
            }

            if (num < 0){
                return false;
            }
        }
        if (num == 0){
            return true;
        } else{
            return false;
        }
    }
};


int main()
{
    string s = "(()())a()";
    int n = s.size();
    Parenthesis parenthesis;
    bool result = parenthesis.chkParenthesis(s, n);
    cout << result << endl;
    return 0;
}
