#include <stdio.h>

int path[10];      // 当前排列
int used[10];      // 标记数字是否被使用

// 回溯函数
void dfs(int nums[], int n, int depth)
{
    if (depth == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;
        path[depth] = nums[i];
        used[i] = 1;
        dfs(nums, n, depth + 1);
        used[i] = 0;
    }
}

int main()
{
    int nums[] = {1, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    dfs(nums, n, 0);
    return 0;
}