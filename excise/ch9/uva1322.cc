#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 50000 + 5;
const int INF = int(1e9 + 10);

int fenw[MAX_N];

inline int lowbit(int x) {
    return x & (-x);
}
void modify(int x, int val, int up) {
    while(x <= up) {
        fenw[x] = min(fenw[x], val);
        x += lowbit(x);
    }
}
int query(int x) {
    int ret = INF;
    while(x) {
        ret = min(ret, fenw[x]);
        x -= lowbit(x);
    }
    return ret;
}
int main() {
    int testCase;
    int n, m, x, y;
    freopen("E:\\in.txt","r",stdin);
    scanf("%d", &testCase);
    while(testCase--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; i++) {
            fenw[i] = INF;
        }
        modify(n, 0, n);
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &x, &y);
            int val = query(n - x + 1) + 1;
            modify(n - y + 1, val, n);
        }
        int res = query(1);
        printf("%d\n", res);
        if(testCase) {
            puts("");
        }
    }
    return 0;
}
