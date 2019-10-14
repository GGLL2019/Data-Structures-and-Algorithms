//
// Created by snow on 19-9-2.
//

#include <iostream>
#include <map>

using namespace std;

int main()
{
    string s0 = "10101";
    map<string, int> dict;
    int len = s0.size();
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j < i; ++j) {
            string ss = s0.substr(j, i-j);
            if (dict.find(ss) != dict.end()){
                dict[ss]++;
            } else
            {
                dict[ss] = 1;
            }
        }
    }

    for (auto mm:dict){
        cout << mm.first << ":\t" << mm.second <<endl;
    }
    return 0;
}