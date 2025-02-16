#include <stdio.h>
#include <string.h>

#define MAX_LEN 101

// 翻转字符串中指定区间 [l, r] 的部分
void reverse(char *s, int l, int r) {
    while (l < r) {
        char temp = s[l - 1];
        s[l - 1] = s[r - 1];
        s[r - 1] = temp;
        l++;
        r--;
    }
}

// 复制字符串
void copy_string(char *dest, const char *src) {
    strcpy(dest, src);
}

// 比较两个字符串的字典序
int compare_strings(const char *s1, const char *s2) {
    return strcmp(s1, s2);
}

int main() {
    char s[MAX_LEN];
    scanf("%s", s);
    int len = strlen(s);

    char min_record[MAX_LEN];
    copy_string(min_record, s);

    // 枚举所有可能的翻转区间 [l, r]
    for (int l = 1; l <= len; l++) {
        for (int r = l+1; r <= len; r++) {
            char temp[MAX_LEN];
            copy_string(temp, s);
            // 翻转指定区间
            reverse(temp, l, r);
            // 如果翻转后的字符串字典序更小，则更新最小记录
            if (compare_strings(temp, min_record) < 0) {
                copy_string(min_record, temp);
            }
        }
    }

    printf("%s\n", min_record);

    return 0;
}