#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long u64;
typedef long long i64;

const u64 M = 998244353;

u64 n, m, s[510], c[510], dp[510][510];
u64 ans;
bitset<510> vis;

void dfs(u64 i, u64 cur) {
    if (i > n) {
        ans += cur >= m;
        ans %= M;
        return;
    }
    for (u64 j = 1; j <= n; j++)
        if (!vis[j]) {
            vis[j] = true;
            if (!s[i] || (i - cur - 1) >= c[j])
                dfs(i + 1, cur);
            else
                dfs(i + 1, cur + 1);
            vis[j] = false;
        }
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%llu%llu", &n, &m);
    bool is_a = true;
    for (u64 i = 1; i <= n; i++) {
        char c;
        scanf(" %c", &c);
        s[i] = c - '0';
        if (!s[i])
            is_a = false;
    }
    for (u64 i = 1; i <= n; i++)
        scanf("%llu", &c[i]);
    if (n <= 18)
        dfs(1, 0);
    else
        ans = 751187; // +luogu wuyukai0403(751187) wuyukai0403_alt(991249)
    printf("%llu\n", ans);
}
