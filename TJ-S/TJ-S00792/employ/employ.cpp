#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
inline LL read() {
    LL num = 0, sign = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') sign = (ch == '-' ? -1 : 1), ch = getchar();
    while ('0' <= ch && ch <= '9') num = (num << 3) + (num << 1) + ch - '0', ch = getchar();
    return (sign == 1 ? num : -num);
}
const int MAXN = 5e2 + 8;
const LL MOD = 998244353;
int n, m, c[MAXN], p[MAXN];
string s;
LL frac[MAXN];
bool check() {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] == '0' || cnt >= c[p[i]]) cnt++;
    return cnt + m <= n;
}
void solve1() {
    for (int i = 1; i <= n; i++) p[i] = i;
    LL ans = 0;
    do {
        ans = (ans + check()) % MOD;
    } while (next_permutation(p + 1, p + n + 1));
    cout << ans;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    n = read(), m = read();
    cin >> s, s = ' ' + s;
    int cnt = 0;
    frac[1] = 1;
    for (int i = 1; i <= n; i++)
        c[i] = read(), cnt += (s[i] == '1'), frac[i] = frac[i - 1] * i % MOD;
    if (n <= 10) solve1();
    else if (cnt == n) return cout << frac[n], 0;
    return 0;
}
