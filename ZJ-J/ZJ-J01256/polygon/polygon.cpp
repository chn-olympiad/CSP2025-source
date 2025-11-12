#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int A[5008];
const int MOD = 998244353;
int tmp;
int now;

void f(int i,int val) {
    if (i>now-1) {
        if (val<=A[now]) {
            tmp++;
        }
        return;
    }
    f(i + 1, val);
    f(i + 1, val + A[i]);
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> N;
    for (int i = 1; i <= N;i++) {
        cin >> A[i];
    }

    sort(A + 1, A + N + 1);

    f(1, 0);
    long long ans = 1;
    for (int i = 1; i <= N;i++) {
        ans = (ans * 2) % MOD;
    }
    ans=(ans+MOD-1)%MOD;

    for (int i = N; i >=1; i--) {
        tmp = 0;
        now = i;
        f(1, 0);
        ans = (ans + MOD - tmp) % MOD;
    }
    cout << ans;
    return 0;
}