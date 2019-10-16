/**
 * @brief 排序, 计数排序
 * @email xueliang2007@qq.com
 * @date  2019.9.12
 */

#include "sort_tools.h"

using namespace std;

class CountingSort {
public:
    int* countingSort(int* arr, int n) {
        if (arr == nullptr){
            return nullptr;
        }

        // 计算数组元素范围，最大和最小值
        int min_val = 1e6, max_val = -1e6;
        for (int i = 0; i < n; ++i) {
            if (arr[i] > max_val){
                max_val = arr[i];
            }
            if (arr[i] < min_val){
                min_val = arr[i];
            }
        }

        // 建立哈希表，统计各个元素出现次数
        int size = max_val - min_val + 1;
        vector<int> hash(size, 0);
        for (int i = 0; i < n; ++i) {
            hash[arr[i]-min_val]++;
        }

        // 将数据导出，恢复序列
        int *brr = new int[n];
        for (int i = 0, j = 0; i < size; ++i) {
            while (hash[i] != 0){
                brr[j] = i + min_val;
                j++;
                hash[i]--;
            }
        }

        array_out(brr, n);

        return brr;
    }
};



int main()
{
    int a[] = {54,35,48,36,27,12,44,44,8,14,26,17,28};
    int n = sizeof(a) / sizeof(int);
    printf("array size is %d\ninit:\n", n);

    CountingSort countingSort;
    countingSort.countingSort(a, n);
}