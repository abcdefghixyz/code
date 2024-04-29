#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}
int constructOBST(int keys[], int freq[], int n) {
    int dp[n + 1][n + 1];
    int i, j, k, L;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    for (i = 1; i <= n; i++) {
        dp[i][i] = freq[i - 1];
    }

    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            dp[i][j] = INT_MAX;
            int sumFreq = 0; 
            for (k = i; k <= j; k++) {
                sumFreq += freq[k - 1];
            }
            for (k = i; k <= j; k++) {
                int cost = ((k > i) ? dp[i][k - 1] : 0) +
                           ((k < j) ? dp[k + 1][j] : 0) +
                           sumFreq + dp[i][i - 1] + dp[j + 1][j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n];
}

int main() {
    int i,n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];
    printf("Enter the keys:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter the frequency of each key:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    int cost = constructOBST(keys, freq, n);
    printf("The cost of the optimal binary search tree is: %d\n", cost);

    return 0;
}
