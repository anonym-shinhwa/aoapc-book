#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100 + 5;
const int MAX_M = 30 + 5;
const int INF = 1 << 30;
int n, m;
int p[MAX_M];
int d[MAX_N][MAX_N];
int d2[MAX_N][MAX_N];
int maxL;
int main() {
    while(scanf("%d%d", &n, &m) == 2 && n) {
        for(int i = 0; i < m; i++) {
            scanf("%d", &p[i]);
        }
        for(int i = m - 1; i >= 0; i--) {
            for(int j = 0; j <= n; j++) {
                int& u = d[i][j];
                if(j == 0) {
                    u = INF;
                } else {
                    if(i == m - 1) {
                        u = p[i] / j;
                    } else {
                        u = d[i + 1][j];
                        for(int k = 1; k <= j; k++) {
                            u = max(u, min(p[i] / k, d[i + 1][j - k]));
                        }
                    }
                }
            }
        }
        maxL = d[0][n];
        for(int i = m - 1; i >= 0; i--) {
            for(int j = 0; j <= n; j++) {
                int& u = d2[i][j];
                u = INF;
                if(j == 0) {
                    u = 0;
                } else {
                    if(i == m - 1) {
                        if(p[i] / j >= maxL) {
                            u = p[i];
                        }
                    } else {
                        if(d[i + 1][j] >= maxL) {
                            u = d2[i + 1][j];
                        }
                        for(int k = 1; k <= j; k++) {
                            if(min(p[i] / k, d[i + 1][j - k]) >= maxL) {
                                u = min(u, d2[i + 1][j - k] + p[i]);
                            }
                        }
                    }
                }
            }
        }
        if(!maxL)d2[0][n] = 0;
        printf("%d %d\n", d[0][n], d2[0][n]);
    }
    return 0;
}
