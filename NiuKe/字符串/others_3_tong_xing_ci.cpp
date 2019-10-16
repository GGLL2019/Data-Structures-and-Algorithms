/**
 * @brief 字符串， 同形词
 * @email xueliang2007@qq.com
 * @date  2019.09.13
 */
#include <iostream>

using namespace std;

int main()
{
    string sa, sb;
    int lena, lenb;
    sa = "UGRPJTDLDYILAZVKSFALAVUYWYTMQFKMN";
    lena = 33;
    sb = "MFGJPSVALYNdDTKRAFUQWYZIADMLTYLKV";
    lenb = 33;

    if (sa.size() != lena || sb.size() != lenb || lena != lenb)
        return false;

    int hash[256] = {0};
    for (int i = 0; i < lena; ++i) {
        int ca = sa[i];
        int cb = sb[i];
        hash[ca]++;
        hash[cb]--;
    }

    for (int j = 0; j < 256; ++j) {
        if(hash[j]){
            cout << "不是" << endl;
            return false;
        }
    }

    cout << "同形" << endl;

    return 0;
}

