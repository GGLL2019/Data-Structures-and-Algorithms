/**
 * @brief 排序
 * @email xueliang2007@qq.com
 * @date  2019.9.12
 */

#include "sort_tools.h"

using namespace std;

void bubble_sorted(int *a, int n)
{
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[j+1]){
                swap_xl(a, j+1, j);
            }
        }
        printf("cnt:%d\t\t", n-i);
        array_out(a, n);
    }
}

void bubble_sorted_improved(int *a, int n)
{
    for (int i = n-1; i >= 0; --i) {
        int changed = 0;
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[j+1]){
                swap_xl(a, j+1, j);
                changed = 1;
            }
        }
        printf("cnt:%d\t|%d|\t", n-i, changed);
        array_out(a, n);
        if (!changed){
            break;
        }
    }
}

int main()
{
    int a[] = {1, 8, 9, 2, 6, 4, 5, 7, 0, 5, 9, 7, 3};
    int n = sizeof(a) / sizeof(int);
    printf("array size is %d\ninit:\n", n);
    array_out(a, n);

    bubble_sorted_improved(a, n);
}