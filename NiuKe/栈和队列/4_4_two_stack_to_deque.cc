/**
 * @brief 队列和栈问题
 * @email xueliang2007@qq.com
 * @date  2019.10.14
 */


/**
 * 题目：
 *   编写一个类,只能用两个栈结构实现队列,支持队列的基本操作(push，pop)。给定一个操作序列ope及它的长度n，
 *   其中元素为正数代表push操作，为0代表pop操作，保证操作序列合法且一定含pop操作，请返回pop的结果序列。
 * 测试样例：
 *   [1,2,3,0,4,0],6
 * 返回：
 *   [1,2]
 * */


#include <iostream>
#include <deque>
#include <stack>
#include <vector>

using std::vector;
using std::stack;
using std::deque;


class TwoStack {
public:
    vector<int> twoStack(vector<int> ope, int n) {
        vector<int> pop_vector;
        for (auto v:ope) {
            if (v == 0){
                int top = pop();
                pop_vector.push_back(top);
            } else{
                push(v);
            }
        }
        return pop_vector;
    }

    void push(int value){
        stack_push.push(value);
    }

    int pop(){
        int top;
        if (stack_pop.empty()){
            // 将push栈 转移到 pop栈中
            while (!stack_push.empty()){
                int top = stack_push.top();
                stack_push.pop();
                stack_pop.push(top);
            }
            // 弹出
            top = stack_pop.top();
            stack_pop.pop();
        } else{
            top = stack_pop.top();
            stack_pop.pop();
        }
        return top;
    }

private:
    stack<int> stack_push;
    stack<int> stack_pop;
};

int main()
{
    vector<int> ope = {1,2,3,0,4,0};

    TwoStack ts;
    ts.twoStack(ope, ope.size());

    return 0;
}
