#include<bits/stdc++.h>
using namespace std; 

namespace Main {

#define int long long 
#define ld long double
#define all(x) begin(x), end(x) 
#define rep(i, l, r) for(int i(l), END##i(r); i <= END##i; ++ i) 
#define per(i, r, l) for(int i(r), END##i(l); i >= END##i; -- i) 

const int mod = 998244353; 

template<class T>
inline void cmax(T& x, const T& y) { x = max(x, y); }
template<class T>
inline void cmin(T& x, const T& y) { x = min(x, y); }

const int N = 510; 

int n, m; 
char s[N]; 
int c[N]; 

namespace Sub1 {

int b[N], vis[N]; 
int ans; 
bool check() {
    int i = 0, j = 0, k = 0;  
    rep(p, 1, n) {
        int x = b[p]; 
        if (k >= c[x]) {
            ++ k; 
            continue; 
        } 
        if (s[p] == '1') ++ j; 
        else ++ k; 
    }
    return j >= m; 
}
void dfs(int step) {
    if (step == n + 1) {
        if (check()) ++ ans; 
        return; 
    } 
    rep(i, 1, n) if (!vis[i]) {
        vis[i] = 1; 
        b[step] = i; 
        dfs(step + 1); 
        vis[i] = 0; 
    }
}

void solve() {
    dfs(1); 
    printf ("%lld\n", ans); 
}

} // namespace Sub1; 

namespace Sub2 {

const int M = 19; 

int dp[1 << M][N]; 
void solve() {
    dp[0][0] = 1; 
    rep(sta, 0, (1 << n) - 1) rep(j, 0, __builtin_popcount(sta)) {
        if (!dp[sta][j]) continue; 
        int val = dp[sta][j]; 
        int i = __builtin_popcount(sta) + 1; 
        rep(p, 1, n) if (!((sta >> (p - 1)) & 1)) {
            int gl = sta ^ (1 << (p - 1)); 
            if (c[p] <= i - 1 - j || s[i] == '0') 
                (dp[gl][j] += val) %= mod; 
            else (dp[gl][j + 1] += val) %= mod; 
        }
    } 
    int ans = 0, nds = (1 << n) - 1; 
    rep(i, m, n) (ans += dp[nds][i]) %= mod; 
    printf ("%lld\n", ans); 
}

} // namespace Sub2; 

void ERoRain() {
    scanf ("%lld%lld", &n, &m); 
    scanf ("%s", s + 1); 
    rep(i, 1, n) 
        scanf ("%lld", c + i); 
    if (n <= 10) return Sub1::solve(); 
    if (n <= 18) return Sub2::solve(); 
    if (m == n) {
        puts("0"); 
        return; 
    }
    int ans = 1; 
    rep(i, 1, n) {
        (ans *= i) %= mod; 
    } 
    printf ("%lld\n", ans); 
}

signed main() {
    ld start_time = clock(); 
    int T = 1; 
    while (T --) ERoRain(); 
    fprintf (stderr, "Time : %Lf\n", (clock() - start_time) / CLOCKS_PER_SEC); 
    return 0; 
}

} signed main() {
    freopen("employ.in", "r", stdin); 
    freopen("employ.out", "w", stdout); 
    Main::main(); 
    return 0; 
}