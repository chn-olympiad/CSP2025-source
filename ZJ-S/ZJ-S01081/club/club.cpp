// BU YAO GUA FEN!!!!
// GEI WO GUO!!!!
// bu yao gua fenQAQ
// pls
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
// rp++
inline int read() {
    char c = getchar(); int f = 1;
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-') f = -f;
    int res = 0;
    for (; c >= '0' && c <= '9'; c = getchar())
        res = (res << 1) + (res << 3) + (c ^ 48);
    return res;
} int T, n; pair<int, int> a[maxn][3]; vector<int> tab[3];
#define mk make_pair
#define ll long long
#define getchar getchar_unlocked
#define open(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)
int main() { open(club);
    for (T = read(); T --; ) {
        n = read(); for (int i = 0; i < 3; i ++) tab[i].clear();
        ll ans = 0;
        for (int i = 1; i <= n; i ++) {
            a[i][0] = mk(read(), 0), a[i][1] = mk(read(), 1), a[i][2] = mk(read(), 2);
            sort(a[i], a[i] + 3, greater<pair<int, int> >());
            tab[a[i][0].second].push_back(a[i][0].first - a[i][1].first), ans += a[i][0].first;
        } int lim = n >> 1;
        if ((int)tab[0].size() <= lim && (int)tab[1].size() <= lim && (int)tab[2].size() <= lim) { printf("%lld\n", ans); continue; }
        for (int i = 0; i < 3; i ++) if ((int)tab[i].size() > lim) {
            sort(tab[i].begin(), tab[i].end()); int k = (int)tab[i].size() - lim;
            for (int j = 0; j < k; j ++) ans -= tab[i][j];
            break;
        } printf("%lld\n", ans);
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/