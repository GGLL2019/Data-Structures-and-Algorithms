//
// Created by snow on 19-8-31.
//
#include <iostream>
#include <algorithm>

using namespace std;

bool check_huiwen(string s)
{
    int len = s.size();
    if (len == 1)
        return true;
    else{
        for (int i = 0; i < len/2; ++i) {
            if (s[i] != s[len-1-i])
                return false;
        }
    }
    return true;
}

int main()
{
    string s = "dfggfg";
    int n = s.size();
    if(n < 1 || n > 50){
        return 0;   // 输入不正确
    }

    int i;
    string s_huiwen="";
    for (i=0; i<n-1; i++){
        string ss = s.substr(i, n-i);
        bool result = check_huiwen(ss);
        if (result)
            break;
        s_huiwen += s[i];
    }
    std::reverse(s_huiwen.begin(), s_huiwen.end());
    cout << n + i <<"\t" << s+"|"+s_huiwen<<endl;


    return 0;
}
