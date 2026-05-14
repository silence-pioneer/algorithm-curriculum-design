#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char* removeDuplicateLetters(char* s) {
    int len = strlen(s);
    int last[26];
    for (int i = 0; i < len; i++) {
        last[s[i] - 'a'] = i;
    }
    bool visited[26] = {false};
    char stack[10001];
    int top = -1;

    for (int i = 0; i < len; i++) {

        char c = s[i];
        if (visited[c - 'a'])
            continue;
        while (top >= 0 &&
               stack[top] > c &&
               last[stack[top] - 'a'] > i) {

            visited[stack[top] - 'a'] = false;
            top--;
        }
        stack[++top] = c;
        visited[c - 'a'] = true;
    }

    stack[top + 1] = '\0';

    static char ans[10001];
    strcpy(ans, stack);

    return ans;
}
int main() {
    char s[] = "cbacdcbc";
    printf("%s\n", removeDuplicateLetters(s));
    return 0;
}