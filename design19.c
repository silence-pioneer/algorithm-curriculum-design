#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int kadane(int *arr, int n){
    int max_current = arr[0];
    int max_global = arr[0];
    for(int i = 1; i < n; i++){
        max_current = (arr[i] > max_current + arr[i]) ? arr[i] : max_current + arr[i];
        if(max_current > max_global){
            max_global = max_current;
        }
    }
    return max_global;
}
int maxresult(int arr[MAX][MAX], int n){
    int maxresult = arr[0][0];
    int temp_arr[MAX];
    for(int i=0; i<n; i++){
        for(int k=0; k<n; k++)    temp_arr[k] = 0;
        for(int j=i; j<n; j++){
            for(int k=0; k<n; k++){
                temp_arr[k] += arr[j][k];
            }
            int current_max = kadane(temp_arr, n);
            if(current_max > maxresult){
                maxresult = current_max;
            }
        }
    }
    return maxresult;
}
int main(){
    int n;
    scanf("%d", &n);
    int arr[MAX][MAX];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d", maxresult(arr, n));
    return 0;
}