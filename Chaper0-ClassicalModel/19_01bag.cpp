#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXC = 1010;
const int MAXN = 110;

// int dp[MAXM][MAXN] = {0};
int dp[MAXC];
int val[MAXN];
int cost[MAXN];
int c = 0;
int n = 0;

int main() {
    while (scanf("%d %d", &c, &n) != EOF) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &cost[i], &val[i]);
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 0; j <= c; j++) {
        //         dp[i][j] = dp[i - 1][j];
        //         if (j >= cost[i]) {
        //             dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + val[i]);
        //         }
        //     }
        // }

        for (int i = 1; i <= n; i++) {
            for (int j = c; j >= cost[i]; j--) {
                dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
            }
        }
        std::cout << dp[c] << std::endl;
    }
    system("pauses");
    return 0;
}








// reverse version ----- capactiy and item are reversed, is also correct, 
// but cannot compress the 2 - dimension dp to 1 - dimension
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXC = 1010;
const int MAXN = 110;

int dp[MAXC][MAXN] = {0};
int val[MAXN];
int cost[MAXN];
int c = 0;
int n = 0;

int main() {
    while (scanf("%d %d", &c, &n) != EOF) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &cost[i], &val[i]);
        }
        for (int i = 0; i <= c; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i][j - 1];
                if (i >= cost[j]) {
                    dp[i][j] = max(dp[i][j], dp[i - cost[j]][j - 1] + val[j]);
                }
            }
        }
        std::cout << dp[c][n] << std::endl;
    }
    system("pauses");
    return 0;
}