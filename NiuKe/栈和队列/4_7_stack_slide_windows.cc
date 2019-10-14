/**
 * @brief 队列和栈问题
 * @email xueliang2007@qq.com
 * @date  2019.10.14
 */


/**
 * 题目：
 *   有一个整型数组 arr 和一个大小为 w 的窗口从数组的最左边滑到最右边,窗口每次向右边滑一个位置。
 *   返回一个长度为n-w+1的数组res，res[i]表示每一种窗口状态下的最大值。
 *   以数组为[4,3,5,4,3,3,6,7]，w=3为例。因为第一个窗口[4,3,5]的最大值为5，第二个窗口[3,5,4]的最大值为5，
 *   第三个窗口[5,4,3]的最大值为5。第四个窗口[4,3,3]的最大值为4。第五个窗口[3,3,6]的最大值为6。
 *   第六个窗口[3,6,7]的最大值为7。所以最终返回[5,5,5,4,6,7]。给定整形数组arr及它的大小n，
 *   同时给定w，请返回res数组。保证w小于等于n，同时保证数组大小小于等于500。
 * 测试样例：
 *   [4,3,5,4,3,3,6,7],8,3
 * 返回：
 *   [5,5,5,4,6,7]
 * */


#include <iostream>
#include <deque>
#include <stack>
#include <vector>

using std::vector;
using std::stack;
using std::deque;


class SlideWindow {
public:
    vector<int> slide(vector<int> arr, int n, int w) {
        vector<int> max_value(n-w+1);
        deque<int> dq_max;
        for (int i = 0, j = 0; i < n; ++i) {
            if (dq_max.empty()){
                // 当双端队列为空时,直接在尾部插入
                dq_max.push_back(i);
            } else{
                int back = dq_max.back();
                if (arr[back] > arr[i]){
                    // 当双端队列的尾部 > 当前数组元素, 则直接插入
                    dq_max.push_back(i);
                } else{
                    // 当双端队列的尾部 <= 当前数组元素, 则弹出尾部,直至为空或者尾部元素 > 当前数组元素
                    dq_max.pop_back();
                    while (!dq_max.empty()){
                        back = dq_max.back();
                        if (arr[back] <= arr[i]){
                            dq_max.pop_back();
                        } else{
                            break;
                        }
                    }
                    dq_max.push_back(i);
                }
            }

            int front = dq_max.front();
            if (front == i-w){
                // 维护窗口的大小
                dq_max.pop_front();
            }
            if (i >= w-1){
                // 提取当前窗口的最大值
                front = dq_max.front();
                max_value[j++] = arr[front];
            }
        }

        return max_value;
    }
};



int main()
{
    vector<int> vv{1, 7, 2, 4, 5, 5, 5, 5};
    int n = vv.size();
    int w = 3;

    SlideWindow slideWindow;
    vector<int> res = slideWindow.slide(vv, n, w);
    for (auto r:res){
        std::cout << r << "\t";
    }

    return 0;
}
