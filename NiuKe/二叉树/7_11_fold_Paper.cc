/**
 * @brief 利用二叉树求解折纸问题折纸问题.
 *   折纸问题中， down折痕会产生up和down折痕， up折痕会产生up和down折痕，最后对二叉树中序遍历即可
 * @email xueliang2007@qq.com
 * @date  2019.10.09
 */


/*
 * 题目：
 *   请把纸条竖着放在桌⼦上，然后从纸条的下边向上⽅对折，压出折痕后再展 开。此时有1条折痕，突起的⽅向指向纸条的背⾯，这条折痕叫做“下”折痕；
 *   突起的⽅向指向纸条正⾯的折痕叫做“上”折痕。如果每次都从下边向上⽅ 对折，对折N次。请从上到下计算出所有折痕的⽅向。给定折的次数n,
 *   请返回从上到下的折痕的数组，若为下折痕则对应元素为"down",若为上折痕则为"up".
 * 测试样例：
 *   1
 * 返回：
 *   ["down"]
 * */

#include <iostream>
#include <vector>

using std::vector;
using std::string;

class FoldPaper {
public:
    vector<string> res;
    vector<string> foldPaper(int n) {
        fold(n, MY_LEFT);
        return res;
    }

private:
    enum: int {
        MY_LEFT = -1,
        MY_RIGHT = 1
    };

    void fold(int n, int pos){
        if (n==0)
            return;

        fold(n-1, MY_LEFT);
        if (pos == MY_LEFT)
            res.emplace_back("down");
        else
            res.emplace_back("up");
        fold(n-1, MY_RIGHT);
    }
};


int main(){

    int n = 3;
    FoldPaper fd;
    fd.foldPaper(n);

    std::cout << '[';
    for (auto iter = fd.res.begin(); iter != fd.res.end() ; ++iter) {
        std::cout << *iter;
        if (iter != fd.res.end()-1){
            std::cout << ", ";
        }
    }
    std::cout << "]\n";


    return 0;
}