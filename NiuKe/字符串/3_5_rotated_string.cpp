/**
 * @brief 字符串， 字符串旋转
 * @email xueliang2007@qq.com
 * @date  2019.09.13
 */


/*
 * 题目：
 *   如果对于一个字符串A，将A的前面任意一部分挪到后边去形成的字符串称为A的旋转词。
 *   比如A="12345",A的旋转词有"12345","23451","34512","45123"和"51234"。
 *   对于两个字符串A和B，请判断A和B是否互为旋转词。给定两个字符串A和B及他们的长度lena，lenb，
 *   请返回一个bool值，代表他们是否互为旋转词。
 * 测试样例：
 *   "cdab",4,"abcd",4
 * 返回：
 *   true
 * */


#include <iostream>

using namespace std;

class Rotation {
public:
    bool chkRotation(string sa, int lena, string sb, int lenb) {
        // write code here
        if (lena != lenb){
            return false;
        }

        string ss = sa + sa;
        for(int i=0; i<lena; i++){
            string sub = ss.substr(i, lena);
            if(sub == sb){
                return true;
            }
        }

        return false;
    }
};

int main()
{
    return 0;
}
