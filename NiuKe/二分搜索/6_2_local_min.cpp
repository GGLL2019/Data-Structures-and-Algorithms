/**
 * @brief 二分搜索
 * @email xueliang2007@qq.com
 * @date  2019.09.13
 */


/*
 * 题目：
 *   定义局部最小的概念。arr长度为1时，arr[0]是局部最小。arr的长度为N(N>1)时，如果arr[0]<arr[1]，
 *   那么arr[0]是局部最小；如果arr[N-1]<arr[N-2]，那么arr[N-1]是局部最小；如果0<i<N-1，
 *   既有arr[i]<arr[i-1]又有arr[i]<arr[i+1]，那么arr[i]是局部最小。 给定无序数组arr，
 *   已知arr中任意两个相邻的数都不相等，写一个函数，只需返回arr中任意一个局部最小出现的位置即可。
 * */

#include "../include/tools.h"

using namespace std;


class Solution {
public:
    int getLessIndex(vector<int> arr) {
        int size = arr.size();
        if (size == 0)
            return -1;
        if (size == 1)
            return 0;

        if (arr[0] < arr[1])
            return 0;
        if (arr[size-2] > arr[size-1])
            return size - 1;

        int left = 1;
        int right = size-2;
        int mid = left + (right - left)/2;
        while (left <= right){
            int mid_sub = arr[mid-1];
            int mid_val = arr[mid];
            int mid_add = arr[mid+1];
            if (mid_val < mid_add && mid_val < mid_sub){
                return mid; // 就是局部极小值
            } else if (mid_val < mid_add && mid_val > mid_sub){
                right = mid-1;  // 局部极小值在mid左侧
                mid = (left + right)/2;
            } else if (mid_val > mid_add && mid_val < mid_sub){
                left = mid+1;   // 局部极小值在mid右侧
                mid = (left + right)/2;
            } else if (mid_val > mid_add && mid_val > mid_sub){
                // left = mid+1;   // 局部极小值在mid两侧均存在, 向左或者向右查找均可
                right = mid-1;
                mid = (left + right)/2;
            }
        }
        return -1;
    }
};


int main()
{
    vector<int> arr = {3,2,9,2,1,4,0,10,9,0,8,3,5,6,7,1,9,2,4,0,7};

    Solution solution;
    int result = solution.getLessIndex(arr);
    cout << result << endl;

    return 0;
}