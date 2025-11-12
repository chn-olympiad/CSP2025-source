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

const int N = 520;
const ll mod = 998244353;

int n, m;
char s[N];
int a[N], p[N];
ll fac[N];

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll inv(ll a) { return qpow(a, mod - 2); }
ll A(ll n, ll m) { return fac[n] * inv(fac[n - m]) % mod; }

void solve() {
    read(n, m);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) read(a[i]);
    if (n <= 20) {
        for (int i = 1; i <= n; ++i) p[i] = i;
        int ans = 0;
        do {
            int num = 0;
            int lq = 0;
            for (int i = 1; i <= n; ++i) {
                if (s[i] == '0' || num >= a[p[i]]) num++;
                else lq++;
            }
            if (lq >= m) ans++;
        } while(next_permutation(p + 1, p + n + 1));
        cout << ans << endl;
        return;
    }
    printf("%lld\n", fac[n]);
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    // read(T);
    while (T--) solve();
    return 0;
}