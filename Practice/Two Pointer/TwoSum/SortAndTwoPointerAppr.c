#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

bool twoSum(int arr[], int n, int target){
    
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;

    // Iterate while left pointer is less than right
    while (left < right){
        int sum = arr[left] + arr[right];

        // Check if the sum matches the target
        if (sum == target)
            return true;
        else if (sum < target)
        
        // Move left pointer to the right
            left++; 
        else
        
        // Move right pointer to the left
            right--; 
    }
    // If no pair is found
    return false;
}

int main(){
    int arr[] = {0, -1, 2, -3, 1};
    int target = -2;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (twoSum(arr, n, target))
        printf("true\n"); 
    else
        printf("false\n");

    return 0;
}