/**
 * @brief 循环有序数组最小值问题
 * @email xueliang2007@qq.com
 * @date  2019.10.08
 */


/**
 * 题目：
 *   对于一个有序循环数组arr，返回arr中的最小值。有序循环数组是指，有序数组左边任意长度的部分放到右边去，
 *   右边的部分拿到左边来。比如数组[1,2,3,3,4]，是有序循环数组，[4,1,2,3,3]也是。给定数组arr及它的大小n，
 *   请返回最小值。
 * 测试样例：
 *   [4,1,2,3,3],5
 * 返回：
 *   1
 * */

#include "../include/tools.h"

using namespace std;

class MinValue {
public:
    int getMin(vector<int> arr, int n) {
        // write code here
        if (arr.size() < 1)
            return -1;

        int left = 0, right = arr.size()-1, mid = left + (right - left)/2;
        if (arr[left] < arr[right])
            return arr[left];

        int flag = -1;
        while (left <= right){
            if (right - left < 3){
                flag = 1;
                break;
            }
            int l_val = arr[left];
            int m = arr[mid];
            int r_val = arr[right];
            if (m < l_val){
                right = mid;
                mid = left + (right - left)/2;
            } else if (m > r_val){
                left = mid;
                mid = left + (right - left)/2;
            } else{
                flag = 1;
                break;
            }
        }
        int temp = arr[mid];
        if (flag == 1){
            for (int i = left; i <= right; ++i) {
                if (temp > arr[i]){
                    temp = arr[i];
                }
            }
        }

        return temp;
    }
};

int main()
{
    vector<int> arr = {4,1,2,3,3};

    MinValue minValue;
    int result = minValue.getMin(arr, arr.size());
    cout << result << endl;

    return 0;
}