#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int CommonLen(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector< vector<int> > dp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = 0;
            if (i == 0 && j == 0) {
                dp[0][0] = (a[0] == b[0]);
                continue;
            }
            else if (i == 0) {
                int tmp = (a[i] == b[j]);
                dp[i][j] = max(dp[i][j - 1], tmp);
            }

            else if (j == 0) {
                int tmp = (a[i] == b[j]);
                dp[i][j] = max(dp[i - 1][j], tmp);
            }

            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (a[i] == b[j])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }


        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    string a, b;
    while (std::cin >> a >> b) {
        int ans = CommonLen(a, b);
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}