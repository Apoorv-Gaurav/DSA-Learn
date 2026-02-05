#include<stdio.h>

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int b_sort(int arr[], int n){
    for(int i = 0; i<n-1 ;i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j+1]>arr[j]){
                swap(&arr[j+1],&arr[j]);
            }
        }
    }
}

void printfArr(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {6, 1, 6, 5, 8, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    b_sort(arr,n);
    printfArr(arr,n);
    int perimeter;
    int flag = 0;
    for(int i=0;i<n-2;i++){
        if(arr[i]<arr[i+1]+arr[i+2]){
            flag = 1;
            perimeter = arr[i]+arr[i+1]+arr[i+2];
            break;
        }
    }
    if(!flag){
        printf("Triangle is not possible.");
        return 0;
    }
    else{
        printf("Larget Perimeter: %d",perimeter);
    }
    return 0;
}