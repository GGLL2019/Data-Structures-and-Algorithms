/**
 * @brief 排序
 * @email xueliang2007@qq.com
 * @date  2019.9.12
 */

#include "sort_tools.h"

using namespace std;

void heap_just(int *a, int level, int n)    // n: 最大节点的序号
{
    int top = a[level];
    for (int i = 2*level+1; i <= n;) {
        if (i < n && a[i] < a[i+1]){
            i++; //找到该树左右子节点的最大值
        }

        if (top < a[i]){
            a[level] = a[i];
            level = i;
            i = i*2+1;
        } else{
            break;
        }
    }
    a[level] = top;
}

void heap_sort(int *a, int n)
{
    // 从下向上,从左向右,构建大顶堆
    for (int i = n/2-1; i >= 0; --i) {
        heap_just(a, i, n-1);
    }

    // 首尾交换,留出最大值
    for (int j = n-1; j > 0; --j) {
        swap_xl(a, 0, j);
        heap_just(a, 0, j-1);
    }
}


int main()
{
    int a[] = {1, 5, 2, 5, 8, 3, 6, 7, 9, 4, 2, 6, 0, 1, 9};
    int n = sizeof(a)/ sizeof(int);

    heap_sort(a, n);
    array_out(a, n);
}