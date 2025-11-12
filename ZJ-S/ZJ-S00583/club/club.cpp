#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int, int>
#define pb push_back
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

inline int read() {
    char ch = getchar();
    int x = 0, m = 1;
    while (!isdigit(ch)) {
        if (ch == '-') m = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * m;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = 1e5 + 5;

int a[N][3], b[N], cnt[3];

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t = read();
    while (t--) {
        int n = read(), ans = 0;
        cnt[0] = cnt[1] = cnt[2] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) a[i][j] = read();
            int x = 0;
            for (int j = 1; j < 3; j++) if (a[i][j] > a[i][x]) x = j;
            b[i] = x;
            cnt[b[i]]++;
            ans += a[i][x];
        }
        if (max({cnt[0], cnt[1], cnt[2]}) * 2 > n) {
            vector<int> num;
            int x = 0;
            for (int i = 1; i < 3; i++) if (cnt[i] > cnt[x]) x = i;
            for (int i = 1; i <= n; i++) {
                if (b[i] == x) {
                    int Max = -1e18;
                    for (int j = 0; j < 3; j++) if (j != x) Max = max(Max, a[i][j] - a[i][x]);
                    num.pb(Max);
                }
            }
            sort(num.rbegin(), num.rend());
            for (auto u : num) {
                cnt[x]--;
                ans += u;
                if (cnt[x] * 2 <= n) break;
            }
        }
        write(ans);
        putchar('\n');
    }
}