#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 200 + 5;
const int INF = int(1e9 + 10);
struct Car {
    int arrived;
    int cost;
    Car(int arrived = 0, int cost = 0): arrived(arrived), cost(cost) {}

};

vector<Car>_left, _right;
int _nLeft, _nRight;
int n, dp[MAX_N][MAX_N][2];
void init() {
    scanf("%d", &n);
    char dir[2];
    int arrived, cost;
    _left.clear();
    _right.clear();
    _left.push_back(Car());
    _right.push_back(Car());
    for(int i = 0; i < n; i++) {
        scanf("%s %d %d", dir, &arrived, &cost);
        if(dir[0] == 'A') {
            _left.push_back(Car(arrived, cost));
        } else {
            _right.push_back(Car(arrived, cost));
        }
    }
    _nLeft = _left.size()-1;
    _nRight = _right.size()-1;
    for(int i = 0; i <= _nLeft; i++) {
        for(int j = 0; j <= _nRight; j++) {
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
}


int solve() {
    dp[0][0][0] = dp[0][0][1] = 0;
    for(int i = 0; i <= _nLeft; i++) {
        for(int j = 0; j <= _nRight; j++) {
            int begin = dp[i][j][0], end = 0;
            for(int k = i + 1; k <= _nLeft; k++) {
                begin = max(begin, _left[k].arrived);
                end = max(end, begin + _left[k].cost);
                dp[k][j][1] = min(dp[k][j][1], end);
                begin += 10;
                end += 10;
            }
            begin = dp[i][j][1], end = 0;
            for(int k = j + 1; k <= _nRight; k++) {
                begin = max(begin, _right[k].arrived);
                end = max(end, begin + _right[k].cost);
                dp[i][k][0] = min(dp[i][k][0], end);
                begin += 10;
                end += 10;
            }
        }
    }
    return min(dp[_nLeft][_nRight][0], dp[_nLeft][_nRight][1]);
}
int main() {
 //   freopen("E:\\in.txt", "r", stdin);
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        init();
        printf("%d\n", solve());
    }
    return 0;
}
