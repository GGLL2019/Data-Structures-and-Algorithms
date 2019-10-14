/**
 * @brief 队列和栈问题
 * @email xueliang2007@qq.com
 * @date  2019.10.14
 */


/**
 * 题目：
 *   实现一个栈的逆序，但是只能用递归函数和这个栈本身的pop操作来实现，而不能自己申请另外的数据结构。
 *   给定一个整数数组A即为给定的栈，同时给定它的大小n，请返回逆序后的栈。
 * 测试样例：
 *   [4,3,2,1],4
 * 返回：
 *   [1,2,3,4]
 * */


#include <iostream>
#include <deque>
#include <stack>
#include <vector>

using std::vector;
using std::stack;
using std::deque;


class StackReverse {
public:
    int get_bottom_element(stack<int> &stk){
        int top = stk.top();
        stk.pop();
        if(stk.empty()){
            return top;
        }else{
            int bottom = get_bottom_element(stk);
            stk.push(top);
            return bottom;
        }
    }

    void stack_reverse(stack<int> &stk){
        if (stk.empty()){
            return;
        }else{
            int bottom = get_bottom_element(stk);
            stack_reverse(stk);
            stk.push(bottom);
        }
    }

    vector<int> reverseStack(vector<int> A, int n) {
        for(auto a:A)
            stk.push(a);

        stack_reverse(stk);

        vector<int> B = A;
        for(int i=n-1; i>=0; i--){
            int top = stk.top();
            stk.pop();
            B[i] = top;
        }
        return B;
    }

private:
    stack<int> stk;
};

int main()
{
    vector<int> vv{1, 2, 3, 4, 5};

    StackReverse stk_inv;
    vector<int> bb = stk_inv.reverseStack(vv, vv.size());

    return 0;
}
