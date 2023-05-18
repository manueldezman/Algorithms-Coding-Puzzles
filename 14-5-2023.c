/*This code finds the minimum number of delete operations required to disconnect a series of nodes represented by a string.
It uses a dynamic programming approach to optimize the computation and avoid redundant calculations.
*/

#include <stdio.h>
#include <string.h>

//define the length of the string
#define N 132

// Function to return the minimum number of delete operations
int findMinimumDeletion(int l, int r, int dp[N][N], char* s)
{
    if (l > r)
        return 0;
    if (l == r)
        return 1;
    if (dp[l][r] != -1)
        return dp[l][r];

    // When a single character is deleted
    int res = 1 + findMinimumDeletion(l + 1, r, dp, s);

    // When a group of consecutive characters are deleted if any of them matches
    for (int i = l + 1; i <= r; ++i)
    {
        // When both the characters are the same, then delete the letters in between them
        if (s[l] == s[i])
            res = (res < (findMinimumDeletion(l + 1, i - 1, dp, s) + findMinimumDeletion(i, r, dp, s))) ? res : (findMinimumDeletion(l + 1, i - 1, dp, s) + findMinimumDeletion(i, r, dp, s));
    }

    // Memoize
    dp[l][r] = res;
    return res;
}

int main()
{
    char s[] = "kjslaqpwoereeeeewwwefifjdksjdfhjdksdjfkdfdlddkjdjfjfjfjjjjfjffnefhkjgefkgjefkjgkefjekihutrieruhigtefhgbjkkkknbmssdsdsfdvneurghiueor";
    int n = strlen(s);
    int dp[N][N];
    memset(dp, -1, sizeof(dp));
    printf("%d steps is needed to disconect the string\n", findMinimumDeletion(0, n - 1, dp, s));
    return 0;
}
