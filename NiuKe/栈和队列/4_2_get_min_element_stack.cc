/**
 * @brief 队列和栈问题
 * @email xueliang2007@qq.com
 * @date  2019.10.14
 */


/**
 * 题目：
 *   定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
 * */


#include <iostream>
#include <deque>
#include <stack>
#include <vector>

using std::vector;
using std::stack;
using std::deque;


class Solution_method1 {
public:
    void push(int value) {
        if (data_stack.empty()){
            data_stack.push(value);
            min_stack.push(value);
        } else{
            int top = data_stack.top();
            data_stack.push(value);
            if (value <= top){
                min_stack.push(value);
            }
        }
    }
    void pop() {
        int top_data_stack = data_stack.top();
        data_stack.pop();
        int top_min_stack = min_stack.top();
        if (top_data_stack <= top_min_stack){
            min_stack.pop();
        }
    }
    int top() {
        return data_stack.top();
    }
    int min() {
        return min_stack.top();
    }

private:
    stack<int> data_stack;
    stack<int> min_stack;
};


class Solution_method2 {
public:
    void push(int value) {
        if (data_stack.empty()){
            data_stack.push(value);
            min_stack.push(value);
        } else{
            int top = data_stack.top();
            data_stack.push(value);

            if (value <= top){
                min_stack.push(value);
            } else{
                min_stack.push(top);
            }
        }
    }

    void pop() {
        data_stack.pop();
        min_stack.pop();
    }

    int top() {
        return data_stack.top();
    }

    int min() {
        return min_stack.top();
    }

private:
    stack<int> data_stack;
    stack<int> min_stack;
};


int main()
{
    Solution_method1 sm1;

    int arr[6] = {3, 4, 2, 3, 2, 1};
    for (int i = 0; i < 6; ++i) {
        sm1.push(arr[i]);
        std::cout << "data_stack_top: " << sm1.top() << "\t" << "min_stack_top " << sm1.min() << std::endl;
    }

    std::cout << std::endl;
    for (int i = 0; i < 6; ++i) {
        std::cout << "data_stack_top: " << sm1.top() << "\t" << "min_stack_top " << sm1.min() << std::endl;
        sm1.pop();
    }

    std::cout << "-----------" << std::endl;

    Solution_method1 sm2;
    for (int i = 0; i < 6; ++i) {
        sm2.push(arr[i]);
        std::cout << "data_stack_top: " << sm2.top() << "\t" << "min_stack_top " << sm2.min() << std::endl;
    }

    std::cout << std::endl;
    for (int i = 0; i < 6; ++i) {
        std::cout << "data_stack_top: " << sm2.top() << "\t" << "min_stack_top " << sm2.min() << std::endl;
        sm2.pop();
    }

}
