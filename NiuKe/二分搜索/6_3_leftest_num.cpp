/**
 * @brief 元素最左出现练习
 * @email xueliang2007@qq.com
 * @date  2019.10.08
 */


/**
 * 题目：
 *   对于一个有序数组arr，再给定一个整数num，请在arr中找到num这个数出现的最左边的位置。
 *   给定一个数组arr及它的大小n，同时给定num。请返回所求位置。若该元素在数组中未出现，请返回-1。
 * 测试样例：
 *   [1,2,3,3,4],5,3
 * 返回：
 *   2
 * */

#include "../include/tools.h"

using namespace std;

class LeftMostAppearance {
public:
    int findPos(vector<int> arr, int n, int num) {
        // write code here
        int size = arr.size();
        if (size == 0){
            return -1;
        }

        int leftest = -1;
        int left = 0, right = size-1, mid = (left + right)/2;
        while(left <= right){
            int m = arr[mid];
            if (num > m){
                left = left + 1;
                mid = (left + right)/2;
            }else if (num < m){
                right = mid - 1;
                mid = (left + right)/2;
            }else{
                leftest = mid;
                right = mid - 1;
                mid = (left + right)/2;
            }
        }

        return leftest;
    }
};


int main()
{
    int num = 3;
    vector<int> arr = {4,1,2,3,3};

    LeftMostAppearance leftMostAppearance;
    int result = leftMostAppearance.findPos(arr, arr.size(), num);
    cout << result << endl;

    return 0;
}