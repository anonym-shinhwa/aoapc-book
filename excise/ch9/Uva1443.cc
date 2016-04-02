#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 40000 + 5;
const int MAX_M = 10000 + 5;
const int INF = (int)1e9;

int weight[MAX_N], prefixSum[MAX_N];
int dp[MAX_N][2], n, m, d;

bool check(int target) {
    dp[0][0] = 0;
    dp[0][1] = INF;
    for(int i = 2; i <= n; i += 2) {
        dp[i][0] = INF;
        dp[i][1] = INF;
        for(int seg = 1; seg <= d && i - 2 * seg >= 0; seg++) {
            if(prefixSum[i] - prefixSum[i - seg] > target) {
                break;
            }
            if(prefixSum[i-seg] - prefixSum[i - 2 * seg] <= target) {
                dp[i][0] = min(dp[i][0], dp[i - 2 * seg][1] + 1);
                dp[i][1] = min(dp[i][1], dp[i - 2 * seg][0] + 1);
            }
        }
    }
    if(dp[n][(m - 1) % 2] > (m - 1) )return false;
    return true;
}
int main() {
   // freopen("in.txt", "r", stdin);
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        scanf("%d%d%d", &n, &m, &d);
        prefixSum[0] = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &weight[i]);
            prefixSum[i] = prefixSum[i - 1] + weight[i];
        }
        if(n & 1 || n < 2 * (m - 1) || n > 2 * d * (m - 1) ) {
            printf("BAD\n");
            continue;
        }
        int low = 1, high = prefixSum[n];
        while(low < high) {
            int mid = (low + high) >> 1;
            if(check(mid))
                high = mid;
            else low = mid + 1;
        }
        printf("%d\n", low);
    }
    return 0;
}
