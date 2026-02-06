#include <stdio.h>
#include <limits.h>

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int f_largest = INT_MIN;
    int s_largest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > f_largest) {
            s_largest = f_largest;
            f_largest = arr[i];
        }
        else if (arr[i] > s_largest && arr[i] < f_largest) {
            s_largest = arr[i];
        }
    }

    printf("%d", s_largest);
    return 0;
}
