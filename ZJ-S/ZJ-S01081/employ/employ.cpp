#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
#define getchar getchar_unlocked
inline int read() {
    char c = getchar(); int f = 1;
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-') f = -f;
    int res = 0;
    for (; c >= '0' && c <= '9'; c = getchar())
        res = (res << 1) + (res << 3) + (c ^ 48);
    return res;
} int n, m, s[maxn], c[maxn];
const int P = 998244353;
int add(int x, int y) { return (x += y) >= P ? x - P : x; }
void addto(int &x, int y) { if ((x += y) >= P) x -= P; }
int mul(int x, int y) { return 1ll * x * y % P; }
void multo(int &x, int y) { x = 1ll * x * y % P; }
namespace Subtask0 {
    bool chk() { return n <= 18; }
    const int N = 20;
    int f[1 << 18][N];
    int main() {
        f[0][0] = 1;
        for (int sta = 0; sta < (1 << n) - 1; sta ++) {
            int t = __builtin_popcount(sta) + 1;
            for (int k = 0; k <= t - 1; k ++) {
                for (int i = 1; i <= n; i ++) if (!(sta & (1 << i - 1))) {
                    if (s[t] == 0 || k >= c[i]) addto(f[sta | (1 << i - 1)][k + 1], f[sta][k]);
                    else addto(f[sta | (1 << i - 1)][k], f[sta][k]);
                }
            }
        } int ans = 0;
        for (int i = 0; i <= n - m; i ++) addto(ans, f[(1 << n) - 1][i]);
        printf("%d\n", ans);
        return 0;
    }
} namespace Subtask1 {
    bool chk() { return m == n; }
    int main() {
        for (int i = 1; i <= n; i ++) if (c[i] == 0 || s[i] == 0) { puts("0"); return 0; }
        int ans = 1;
        for (int i = 1; i <= n; i ++) multo(ans, i);
        printf("%d\n", ans);
        return 0;
    }
}
#define open(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)
int main() { open(employ);
    n = read(), m = read();
    for (int i = 1; i <= n; i ++) {
        char c; for (c = getchar(); c != '0' && c != '1'; c = getchar());
        s[i] = c - '0';
    } for (int i = 1; i <= n; i ++) c[i] = read();
    if (Subtask0 :: chk()) return Subtask0 :: main();
    if (Subtask1 :: chk()) return Subtask1 :: main();
    return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
/*
when i finish all the score i can get there is only 12 min left
i am so nervous
i wish i will not lose any score>w<
exception score: 324pts
pls do not GUA FEN !!!!!!!!!!!!!!!!!!!!!
*/

/*
wo xiang qu wc qwq
*/