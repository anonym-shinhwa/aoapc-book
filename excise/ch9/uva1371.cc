#include<bits/stdc++.h>
using namespace std;

const int N = 5000 + 5;
const int M = 50 + 5;
const int INF = (int)1e9 + 10;
char x[N], y[N];
int dp[N][M];
int nx, ny;
void readData() {
    scanf("%s%s", y + 1, x + 1);
    nx = strlen(x + 1);
    ny = strlen(y + 1);
}
bool check(int c) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i <= nx; i++) {
        if(dp[i][ny] <= c)
            dp[i][0] = 0;
        for(int j = 0; j <= ny; j++) {
            if(dp[i][j] > c)continue;
            if(i + 1 <= nx && j + 1 <= ny)
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (x[i + 1] == y[j + 1] ? 0 : 1));
            if(i + 1 <= nx)
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            if(j + 1 <= ny)
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
        }
    }
    return dp[nx][ny] <= c;
}

int solve() {
    int low = 0, high = ny;
    while(low < high) {
        int mid = (low + high) >> 1;
        if(check(mid))
            high = mid;
        else low = mid + 1;
    }
    return low;
}
int main() {
  //  freopen("E:\\in.txt", "r", stdin);
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        readData();
        int res = solve();
        printf("%d\n", res);
    }
    return 0;
}
