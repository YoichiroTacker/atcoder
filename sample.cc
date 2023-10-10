// sample shellsort
#include <stdio.h>

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void shellSort(int arr[], int arr_length)
{
    int h, i, j, k;
    for (h = 1; h < (arr_length / 9); h = h * 3 + 1)
        ; // 要素数が９を超えないようにhを決める(一般的に1,4,13,121...を使う)
    while (h > 0)
    {
        for (i = h; i < arr_length; i++)
        {
            j = i;
            while (j >= h && arr[j - h] > arr[j])
            {
                k = arr[j];
                arr[j] = arr[j - h];
                arr[j - h] = k;
                j = j - h;
            }
        }
        h = (h - 1) / 3;
    }
}

int main()
{
    int arr[] = {8, 3, 1, 2, 7, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);
    printArray(arr, n);
    return 0;
}