#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void mergeArrays(int* a, int* b, int n, int m) {
    int i = n - 1, j = 0;

    // Swap smaller elements from b[] with 
    // larger elements from a[]
    while (i >= 0 && j < m) {
        if (a[i] < b[j])
            i--;
        else {
            int temp = b[j];
            b[j] = a[i];
            a[i] = temp;
            i--;
            j++;
        }
    }

    // Sort both arrays
    qsort(a, n, sizeof(int), cmp);
    qsort(b, m, sizeof(int), cmp);
}

int main() {
    int a[] = {1, 5, 9, 10, 15, 20};
    int b[] = {2, 3, 8, 13};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    mergeArrays(a, b, n, m);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < m; i++)
        printf("%d ", b[i]);
    return 0;
}