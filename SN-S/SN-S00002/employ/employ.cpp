#include <bits/stdc++.h>

#define int long long

constexpr int MOD = 998244353;

char s[1010];
int c[1010];
int p[1010];
int d[1010];
int frac[1010];
int vis[1010];
int n, m;

constexpr int T = 1 << 18;
std::bitset<T> set[19][19];
signed dp[19][19][1 << 18];
int dfs(int idx, int sum, int stat) {
    if (idx == n + 1) {
        return sum >= m;
    }
    if (sum >= m) {
        return frac[n - idx + 1];
    }
    if (set[idx][sum][stat]) {
        return dp[idx][sum][stat];
    }
    
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (stat & (1 << (i - 1))) {
            continue;
        }
        bool ext = idx - sum - 1 < c[i] && s[idx] == '1';
        stat |= (1 << (i - 1));
        res += dfs(idx + 1, sum + ext, stat);
        res %= MOD;
        stat &= ~(1 << (i - 1));
    }
    set[idx][sum][stat] = true;
    return dp[idx][sum][stat] = res;
}

int dfs2(int idx, int sum) {
    if (idx == n + 1) {
        return sum >= m;
    }
    if (sum >= m) {
        return frac[n - idx + 1];
    }
    
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        bool ext = idx - sum - 1 < c[i] && s[idx] == '1';
        vis[i] = true;
        res += dfs2(idx + 1, sum + ext);
        res %= MOD;
        vis[i] = false;
    }
    return res;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cin >> n >> m;
    std::cin >> (s + 1);
    frac[0] = 1;
    for (int i = 1; i <= n; i++) {
        std::cin >> c[i];
        frac[i] = frac[i - 1] * i % MOD;
    }

    if (n <= 18) {
        std::cout << dfs(1, 0, 0) << '\n';
    } else {
        std::cout << dfs2(1, 0) << '\n';
    }
}

