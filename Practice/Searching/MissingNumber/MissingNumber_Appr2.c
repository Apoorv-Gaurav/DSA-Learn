#include<stdio.h>

int main(){
    int arr[] = {8, 2, 4, 5, 3, 7, 1};
    int n = 7;
    int xor1 = 0, xor2 = 0;
    for(int i=0; i<n; i++){
        xor1 ^= arr[i];
    }
    for(int i=1;i<=n+1;i++){
        xor2^=i;
    }
    printf("%d",xor1-xor2);
    return 0;
}