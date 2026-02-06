#include<stdio.h>

int main(){
    int arr[] = {8, 2, 4, 5, 3, 7, 1};
    int n = 7;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    int esum= (n+1)*(n+2)/2;
    printf("%d",esum - sum);
    return 0;
}