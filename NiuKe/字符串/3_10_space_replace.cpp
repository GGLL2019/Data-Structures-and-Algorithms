/**
 * @brief 字符串， 替换空格
 * @email xueliang2007@qq.com
 * @date  2019.09.13
 */


#include <iostream>

using namespace std;

class Replacement {
public:
    string replaceSpace(string s, int len) {
        // write code here
        int space_num = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == ' '){
                space_num++;
            }
        }

        int relen = len + space_num*2;
        s.resize(relen);
        for (int i = len-1, j = relen-1; i >= 0; --i) {
            if (s[i] == ' '){
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            } else{
                s[j--] = s[i];
            }
        }
        return s;
    }
};


int main()
{
    return 0;
}
