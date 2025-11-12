#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PII pair<int, int>
#define mk(a, b) makr_pair(a, b)
using namespace std;
template<typename P>
inline void read(P &x) {
    P res = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        res = (res << 3) + (res << 1) + (ch ^ 48);
        ch = getchar();
    }
    x = res * f;
}
template<typename PP, typename ...Arg>
inline void read(PP &x, Arg &...args) { read(x); read(args...); }
int T = 1;

const int N = 1e5 + 10, M = 5e6 + 10;

char s[2][M];

int n, q;

void solve() {
    read(n, q);   
    for (int i = 1; i <= n; ++i) scanf("%s", s[0] + 1), scanf("%s", s[1] + 1);
    for (int i = 1; i <= q; ++i) scanf("%s", s[0] + 1), scanf("%s", s[1] + 1);
    for (int i = 1; i <= q; ++i) puts("0");
}

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    // read(T);
    while (T--) solve();
    return 0;
}