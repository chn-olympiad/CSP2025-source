#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define REP(i, l, r)    for(int (i) = (l);(i) <= (r);(i)++)
#define DEP(i, r, l)    for(int (i) = (r);(i) >= (l);(i)--)
#define pb push_back

void read(){}
template<typename T1, typename ...T2>inline void read(T1 &x, T2 &...oth) {
    x = 0;
    int ch = getchar(), f = 0;
    while(ch < '0' or '9' < ch) {
        if (ch == '-')  f = 1;
        ch = getchar();
    }
    while('0' <= ch and ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    if (f)  x = -x;
    read(oth...);
    return;
}

void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x <= 9) return putchar(x + '0'), void();
    write(x / 10);
    putchar(x % 10 + '0');
    return;
}

namespace YZLK{
    const int N = 5e2 + 10;
    const int mod = 998244353;
    int n, m;
    char c[N];
    int a[N];
    bool vis[N];
    int cnt;
    int dp[N][N];
    void dfs1(int t, int cc) {
        // cout << t << " " << cc << "\n";
        if (t == n + 1) {
            // cout << 111 << "\n";
            // cout << cc << "\n";
            if (cc >= m) cnt++;
            return;
        }
        if ((n - t + 1) + cc < m)    return;
        REP(i, 1, n) {
            if (vis[i]) continue;
            vis[i] = 1;
            if (c[t] == '0')    dfs1(t + 1, cc);
            else {
                if (t - 1 - cc >= a[i])  dfs1(t + 1, cc);
                else                     dfs1(t + 1, cc + 1);
            }
            vis[i] = 0; 
        }
        return;
    }
    void main() {
        read(n, m);
        scanf("%s", c + 1);
        REP(i, 1, n)    read(a[i]);
        if (n <= 10) {
            dfs1(1, 0);
            cout << cnt << "\n";
            return;
        }
        bool flag = 1;
        REP(i, 1, n) {
            if (c[i] == '0')    flag = 0;
        }
        return;
    }
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    int T = 1;
    // read(T);
    while(T--) {
        YZLK::main();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}