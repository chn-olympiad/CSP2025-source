#include <bits/stdc++.h>
using namespace std;
const int N = 505, MOD = 998244353;
bool easy[N], used[N];
int n, m, p[N];
long long dfs(int k, int pass) {
    if (k == n)
        return pass >= m;
    long long res = 0;
    if (pass < m) {
        for (int i = 0; i < n; i++)
            if (!used[i]) {
                used[i] = true;
                res = (res + dfs(k + 1, pass + (p[i] > k - pass && easy[k]))) % MOD;
                used[i] = false;
            }
    } else {
        for (int i = 0; i < n; i++)
            if (!used[i]) {
                used[i] = true;
                res = (res + dfs(k + 1, pass)) % MOD;
                used[i] = false;
            }
    }
    return res;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++)
        easy[i] = getchar() - '0';
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("%lld", dfs(0, 0));
    return 0;
}