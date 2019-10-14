/**
 * @brief 队列和栈问题, 数组变树问题
 * @email xueliang2007@qq.com
 * @date  2019.10.14
 */


/**
 * 题目：
 *   对于一个没有重复元素的整数数组，请用其中元素构造一棵MaxTree，MaxTree定义为一棵二叉树，其中的节点与数组元素一一对应，
 *   同时对于MaxTree的每棵子树，它的根的元素值为子树的最大值。现有一建树方法，对于数组中的每个元素，
 *   其在树中的父亲为数组中它左边比它大的第一个数和右边比它大的第一个数中更小的一个。若两边都不存在比它大的数，
 *   那么它就是树根。请设计O(n)的算法实现这个方法。给定一个无重复元素的数组A和它的大小n，请返回一个数组，
 *   其中每个元素为原数组中对应位置元素在树中的父亲节点的编号，若为根则值为-1。
 * 测试样例：
 *   [3,1,4,2],4
 * 返回：
 *   [2,0,-1,2]  // 注：没搞明白最后一个2是怎么来的
 * */


#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>

using std::vector;
using std::stack;
using std::deque;
using std::map;


class MaxTree {
public:
    vector<int> buildMaxTree(vector<int> va, int n) {
        vector<int> res;
        if (va.empty() || n < 1){
            return res;
        }

        // 左面第一个大与当前值的元素值
        vector<int> left = get_left_first_bigger(va, n);
        // 右面第一个大与当前值的元素值
        vector<int> right = get_right_first_bigger(va, n);

        // int head_element = *std::max_element(va.begin(), va.end());  // 头节点元素

        map<int, int> tree;  // first: 树中节点的元素； second：当前节点的父节点的元素值
        for (int i = 0; i < n; ++i) {
            int head_node = ( left[i] == -1 ? right[i] : (right[i] == -1 ? left[i] : std::min(left[i], right[i])) );
            tree[va[i]] = head_node;
        }

        for (auto m:tree) {
            std::cout << m.first << "\t" << m.second << std::endl;
        }

        // TODO(xueliang: xueliang2007@qq.com): 不明白输出是什么意思，未完

        return res;
    }

    vector<int> get_left_first_bigger(const vector<int> &va, int n){
        stack<int> stk;
        vector<int> left(n);
        for (int i = 0; i < n; ++i) {
            if (stk.empty()){
                stk.push(va[i]);
                left[i] = -1;
            } else{
                int top = stk.top();
                if (va[i] < top){
                    stk.push(va[i]);
                    left[i] = top;
                } else{
                    do{
                        stk.pop();
                        if (stk.empty()){
                            break;
                        } else{
                            top = stk.top();
                        }
                    }while (va[i] > top);

                    if (stk.empty()){
                        left[i] = -1;
                    } else{
                        left[i] = top;
                    }
                    stk.push(va[i]);
                }
            }
        }
        return left;
    }

    vector<int> get_right_first_bigger(const vector<int> &va, int n){
        stack<int> stk;
        vector<int> right(n);
        for (int i = n-1; i >= 0; --i) {
            int val = va[i];
            if (stk.empty()){
                stk.push(va[i]);
                right[i] = -1;
            } else{
                int top = stk.top();
                if (va[i] < top){
                    stk.push(va[i]);
                    right[i] = top;
                } else{
                    do{
                        stk.pop();
                        if (stk.empty()){
                            break;
                        } else{
                            top = stk.top();
                        }
                    }while (va[i] > top);

                    if (stk.empty()){
                        right[i] = -1;
                    } else{
                        right[i] = top;
                    }
                    stk.push(va[i]);
                }
            }
        }
        return right;
    }
};


int main()
{
    vector<int> vv{3,4,5,1,2};

    MaxTree maxTree;
    vector<int> res = maxTree.buildMaxTree(vv, vv.size());
    for (auto r:res){
        std::cout << r << "\t";
    }

    return 0;
}
