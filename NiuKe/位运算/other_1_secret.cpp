/**
 * @brief 位运算，加密解密
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */

#include "../include/tools.h"

using namespace std;


int main()
{
    char text[] = "abcdef";
    char pw = 'w';

    int n = sizeof(text) / sizeof(char);
    char *cipher = new char[n];
    memcpy(cipher, text, n);

    cout_array(text, n);

    for (int i = 0; i < n; ++i)
        cipher[i] = text[i]^pw;
    cout_array(cipher, n);

    char *text_gen = new char[n];
    memcpy(text_gen, cipher, n);
    for (int i = 0; i < n; ++i)
        text_gen[i] = cipher[i]^pw;
    cout_array(text_gen, n);

    return 0;
}
