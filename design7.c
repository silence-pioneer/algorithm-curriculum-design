#include <stdio.h>
#include <stdlib.h>
int result(int *arr, int n, int k){
    if(n <= 0) return -1;
    int min = arr[0];
    int s=0;
    for(int i = 1; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
            s = i;
        }
    }
    if(k == 1) return min;
    arr[s] = arr[n-1]; 
    return result(arr, n-1, k-1);
}
int main(){
    int n,k;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL) return 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    if(k > n || k <= 0) {
        printf("-1");
        free(arr);
        return 0;
    }
    printf("%d", result(arr, n, k));
    free(arr);
    return 0;
}