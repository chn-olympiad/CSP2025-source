#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int N = 100010, mod = 998244353;
int n, m;
u64 calc(int x) {
    u64 ret = 1, c = 1;
    for (int i = 1; i <= x; i ++) {
        c = c * i % mod;
        ret = ret * c % mod;
    }
    return ret;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cout << calc(n) << '\n';
    return 0;
}