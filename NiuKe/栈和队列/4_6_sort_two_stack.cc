/**
 * @brief 队列和栈问题
 * @email xueliang2007@qq.com
 * @date  2019.10.14
 */


/**
 * 题目：
 *   请编写一个程序，按升序对栈进行排序（即最大元素位于栈顶），要求最多只能使用一个额外的栈存放临时数据，
 *   但不得将元素复制到别的数据结构中。给定一个int[] numbers(C++中为vector&ltint>)，
 *   其中第一个元素为栈顶，请返回排序后的栈。请注意这是一个栈，意味着排序过程中你只能访问到第一个元素。
 * 测试样例：
 *   [1,2,3,4,5]
 * 返回：
 *   [5,4,3,2,1]
 * */


#include <iostream>
#include <deque>
#include <stack>
#include <vector>

using std::vector;
using std::stack;
using std::deque;


class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        // 非空检查
        vector<int> result;
        if (numbers.empty()){
            return result;
        }

        // 构造栈
        for (auto v:numbers){
            stk_original.push(v);
        }

        // 向辅助栈中压入元素
        int top = 0;
        while (!stk_original.empty()){
            top = stk_original.top();
            stk_original.pop();
            if (stk_help.empty()){
                // 如果help栈为空，则直接压入
                stk_help.push(top);
            } else{
                int top_help = stk_help.top();
                if (top >= top_help){
                    // 如果top不大于help栈顶元素，则直接压入
                    stk_help.push(top);
                } else{
                    // 如果top小于help栈顶元素
                    do{
                        stk_help.pop();
                        stk_original.push(top_help);
                        if (stk_help.empty()){
                            break;
                        } else{
                            top_help = stk_help.top();
                        }
                    } while (top < top_help);

                    stk_help.push(top);
                }
            }
        }

        while (!stk_help.empty()){
            top = stk_help.top();
            stk_help.pop();
            result.emplace_back(top);
        }

        return result;
    }

private:
    stack<int> stk_original;
    stack<int> stk_help;
};
int main()
{
    vector<int> vv{1, 7, 2, 4, 5};

    TwoStacks twoStacks;
    vector<int> res = twoStacks.twoStacksSort(vv);
    for (auto r:res){
        std::cout << r << "\t";
    }

    return 0;
}
