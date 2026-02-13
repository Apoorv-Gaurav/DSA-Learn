//Two Pointer Technique - O(n × logn + n) Time and O(1) Space

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

void sumClosest(int arr[], int n, int target){ //n>2
    if(n<2){
        return;
    }

    qsort(arr,n,sizeof(int),cmp);

    int* res = (int*)malloc(2 * sizeof(int));

    int minDiff = INT_MAX;
    int absDiff = INT_MIN;
    int left = 0, right = n-1;

    while(left<right){
        int currSum = arr[left] + arr[right];

        if(abs(target-currSum) < minDiff){
            minDiff = abs(target - currSum);
            res[0] = arr[left];
            res[1] = arr[right];

            if(currSum < target){
                left++;
            }
            else if(currSum > target){
                right--;
            }
            else{
                break;
            }
        }
        else break;
    }
    printf("%d %d",res[0],res[1]);
}

int main(){
    int arr[] = {5, 2, 7, 1, 4};
    int target = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    sumClosest(arr, n, target);
    return 0;
}

//Very Good Method/Question