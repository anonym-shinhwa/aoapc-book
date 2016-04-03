#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1000 + 5;
const int MAX_M = 1000 + 5;
int dp[MAX_N][10][10];

char s1[MAX_N], s2[MAX_M];
int main() {
    freopen("E:\\in.txt", "r", stdin);
    while(scanf("%s%s", s1, s2) == 2) {
        int n = strlen(s1);
        memset(dp, 63, sizeof(dp));
        dp[0][0][0]=0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 10; j++) {
                for(int k = 0; k < 10; k++) {
                    int r = (s1[i] - s2[i] + 20 - j) % 10;
                    for(int p = 0; p <= r; p++) {
                        for(int q = 0; q <= p; q++) {
                            dp[i + 1][(k + p) % 10][q] = min(dp[i + 1][(k + p) % 10][q], dp[i][j][k] + r);
                        }
                    }
                    r = (10 - r) % 10;
                    for(int p = 0; p <= r; p++) {
                        for(int q = 0; q <= p; q++) {
                            dp[i + 1][(k - p + 10) % 10][(10 - q) % 10] = min( dp[i + 1][(k - p + 10) % 10][(10 - q) % 10], dp[i][j][k] + r);
                        }
                    }
                }
            }
        }
        printf("%d\n", dp[n][0][0]);
    }
    return 0;
}
