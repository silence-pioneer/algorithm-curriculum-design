#include <stdio.h>
#define MAX 100
void revolve(int *a, int *b, int *c, int *d)
{
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = *d;
    *d = temp;
}

void rotate(int arr[][MAX], int start, int n)
{
    if (n <= 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        revolve(
            &arr[start][start + i],                 // 上
            &arr[start + i][start + n - 1],        // 右
            &arr[start + n - 1][start + n - 1 - i], // 下
            &arr[start + n - 1 - i][start]         // 左
        );
    }

    rotate(arr, start + 1, n - 2);
}

int main()
{
    int n;
    int arr[MAX][MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    rotate(arr, 0, n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}