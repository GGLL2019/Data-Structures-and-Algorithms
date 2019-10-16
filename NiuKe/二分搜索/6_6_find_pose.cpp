/**
 * @brief 二分搜索, 最左原位
 * @email xueliang2007@qq.com
 * @date  2019.09.13
 */


/*
 * 题目：
 *   有一个有序数组arr，其中不含有重复元素，请找到满足arr[i]==i条件的最左的位置。
 *   如果所有位置上的数都不满足条件，返回-1。给定有序数组arr及它的大小n，请返回所求值。
 * 测试样例：
 *   [-1,0,2,3],4
 * 返回：
 *   2
 * */

#include <iostream>
#include "../include/tools.h"

using namespace std;

class Find {
public:
    int findPos(vector<int> arr, int n){
        int size = arr.size();
        if (size == 0)
            return -1;

        if (arr[0] > size-1)
            return -1;
        if (arr[size-1] < 0)
            return -1;

        int left = 0, right = size-1, mid = left + (right - left)/2;

        int flag = -1;
        while (left <= right){
            int m = arr[mid];
            if (m > mid){
                right = mid-1;
                mid = left + (right - left)/2;
            } else if (m < mid){
                left = mid+1;
                mid = left + (right - left)/2;
            } else{
                flag = mid;
                right = mid-1;
                mid = left + (right - left)/2;
            }
        }
        return flag;
    }
};


int main()
{
    vector<int> arr = {-1,0,2,3};
    Find find1;
    int result = find1.findPos(arr, arr.size());
    cout << result << endl;

    return 0;
}