/**
 * @brief 字符串， 词语变形
 * @email xueliang2007@qq.com
 * @date  2019.09.13
 */


/*
 * 题目：
 *   对于两个字符串A和B，如果A和B中出现的字符种类相同且每种字符出现的次数相同，则A和B互为变形词，
 *   请设计一个高效算法，检查两给定串是否互为变形词。给定两个字符串A和B及他们的长度，
 *   请返回一个bool值，代表他们是否互为变形词。
 * 测试样例：
 *   "abc",3,"bca",3
 * 返回：
 *   true
 * */


#include <iostream>

using namespace std;

class Transform {
public:
    bool chkTransform(string A, int lena, string B, int lenb) {
        // write code here
        if (lena != lenb || A.size() != lena || B.size() != lenb)
            return false;

        int hash[256] = {0};
        for(int i=0; i<lena; i++){
            int ca = A[i];
            int cb = B[i];
            hash[ca]++;
            hash[cb]--;
        }

        for (int j=0; j<256; j++){
            if (hash[j]){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
