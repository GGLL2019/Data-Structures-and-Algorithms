/**
 * @brief 排序
 * @email xueliang2007@qq.com
 * @date  2019.9.12
 */

#include "sort_tools.h"

using namespace std;

void insert_sort(int *a, int n)
{
    for (int i = 1; i < n; ++i) {
        for (int j = i; j >= 1; --j) {
            if (a[j] < a[j-1]){
                // swap
                swap_xl(a, j-1, j);
            }
        }
        printf("cnt:%d\t\t", i);
        array_out(a, n);
    }
}



int main()
{
    int a[] = {1, 8, 9, 2, 6, 4, 5, 7, 0, 5, 9, 7, 3, 9, 8};
    int n = sizeof(a)/ sizeof(int);
    printf("array size is %d\ninit:\n", n);

    insert_sort(a, n);
}