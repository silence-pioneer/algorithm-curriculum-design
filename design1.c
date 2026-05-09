#include <stdio.h>
#include <stdlib.h>
int result(int *arr, int n) {
    int count = 0;
    int *a = (int *)malloc(n * sizeof(int));
    a[0] = arr[0];
    for (int i = 1; i < n; i++) {
        a[i] = arr[i] + a[i - 1];
    }
    int *b = (int *)malloc(n * sizeof(int));
    b[0] = arr[n-1];
    for (int i = 1; i < n; i++) {
        b[i] = arr[n-i-1] + b[i - 1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                count++;
                break;
            }
        }
    }
    free(a);
    free(b);
    return count;
}
int main() {
    int n=0;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d", result(arr, n));
    free(arr);
    return 0;
}