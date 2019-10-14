/**
 * @brief 排序
 * @email xueliang2007@qq.com
 * @date  2019.9.12
 */

#include "sort_tools.h"

using namespace std;


int partition(int *a, int left, int right)
{
    int point = a[left];
    while (left < right){
        while (left < right && a[right] >= point){
            right--;
        }
        swap_xl(a, left, right);

        while (left < right && a[left] <= point){
            left++;
        }
        swap_xl(a, left, right);
    }
    return left;
}


void quick(int *a, int left, int right)
{
    if (left < right){
        int key = partition(a, left, right);
        quick(a, left, key-1);
        quick(a, key+1, right);
    }
}


void quick_sort(int *a, int n){
    quick(a, 0, n-1);
}


int main()
{
    int a[] = {1, 8, 9, 2, 6, 4, 5, 7, 0, 5, 9, 4, 2, 0, 9, 1, 7, 3, 9, 5, 8, 6, 4, 3, 1, 0};
    int n = sizeof(a)/ sizeof(int);
    printf("array size is %d\ninit:\n", n);

    quick_sort(a, n);
    array_out(a, n);
}