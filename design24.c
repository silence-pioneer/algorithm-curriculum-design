#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 1000
#define MAX_SHIFTS 1000

typedef struct {
    int start, end;
} Interval;

typedef struct {
    int id;
    int min_s, max_e;
    int active;
} Student;

typedef struct {
    int s, e;
    int covered;
} Shift;

// 按班次结束时间从小到大排序
int compareShifts(const void* a, const void* b) {
    return ((Shift*)a)->e - ((Shift*)b)->e;
}

int main() {
    Shift shifts[MAX_SHIFTS];
    Student students[MAX_STUDENTS];
    int student_map[MAX_STUDENTS] = {0}; // 记录学号是否出现过
    int shift_count = 0, student_count = 0;
    int n; // 班次数量
    scanf("%d", &n);
    int s, e, sid;
    // 模拟输入处理 (根据题目格式：开始 结束 学号1 学号2...)
    // 注意：题目输入格式较灵活，这里假设每行读取
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s, &e);
        shifts[shift_count].s = s;
        shifts[shift_count].e = e;
        shifts[shift_count].covered = 0;
        shift_count++;

        // 读取该行剩余的学号
        while (getchar() != '\n') {
            if (scanf("%d", &sid) == 1) {
                if (!student_map[sid]) {
                    student_map[sid] = 1;
                    students[sid].id = sid;
                    students[sid].min_s = s;
                    students[sid].max_e = e;
                    students[sid].active = 1;
                } else {
                    if (s < students[sid].min_s) students[sid].min_s = s;
                    if (e > students[sid].max_e) students[sid].max_e = e;
                }
            } else break;
        }
    }

    // 1. 将班次按结束时间排序
    qsort(shifts, shift_count, sizeof(Shift), compareShifts);

    int committee[MAX_STUDENTS];
    int comm_size = 0;

    // 2. 贪心覆盖
    for (int i = 0; i < shift_count; i++) {
        if (shifts[i].covered) continue;

        // 找到能覆盖当前班次 i 且结束时间最远的学生
        int best_sid = -1;
        int max_reach = -1;

        for (int j = 0; j < MAX_STUDENTS; j++) {
            if (student_map[j]) {
                // 学生区间必须与当前班次有交集
                if (!(students[j].max_e < shifts[i].s || students[j].min_s > shifts[i].e)) {
                    if (students[j].max_e > max_reach) {
                        max_reach = students[j].max_e;
                        best_sid = j;
                    }
                }
            }
        }

        if (best_sid != -1) {
            committee[comm_size++] = best_sid;
            // 标记所有被该学生覆盖的班次
            for (int k = 0; k < shift_count; k++) {
                if (!(students[best_sid].max_e < shifts[k].s || students[best_sid].min_s > shifts[k].e)) {
                    shifts[k].covered = 1;
                }
            }
        }
    }

    // 3. 输出结果
    for (int i = 0; i < comm_size; i++) {
        printf("%d%c", committee[i], (i == comm_size - 1 ? '\n' : ' '));
    }

    return 0;
}
