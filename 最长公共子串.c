#include<stdio.h>
#include<string.h>

int lss(char *str1, char *str2)
{
    if (str1 == NULL || str2 == NULL) {
        return 0;
    }
    int m = strlen(str1);
    int n = strlen(str2);
    int res = 0;
    int dp[101][101] = {0};
    int i, j;
    for (i = 1; i < m + 1; i++) {
        for (j = 1; j < n + 1; j++) {
            if (str1[i - 1] == str2[j - 1] ||
                str1[i - 1] == str2[j - 1] + ('a' - 'A') ||
                str1[i - 1] == str2[j - 1] - ('a' - 'A')) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = (dp[i][j] > res) ? dp[i][j] : res;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return res;
}

int main()
{
    char str1[100];
    char str2[100];
    while (scanf("%s %s", str1, str2) != EOF) {
        printf("%d\n", lss(str1, str2));
    }
    return 0;
}