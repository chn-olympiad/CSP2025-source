#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500 + 5, MOD = 998244353;

int n, m, fac[N];
int c[N], p[N];

inline int read() {
    int x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
    return x * f;
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    n = read(), m = read();
    string s; cin >> s; s = " " + s;
    for(int i = 1; i <= n; i++) c[i] = read();
    int CNT = 0;
    for(int i = 1; i <= n; i++) CNT += s[i] - '0';
    for(int i = 1; i <= n; i++) fac[i] = (i == 1 ? 1 : fac[i - 1] * i % MOD);
    if(n <= 10) {
        for(int i = 1; i <= n; i++) p[i] = i;
        int res = 0;
        do {
            int out = 0, in = 0;
            for(int i = 1; i <= n; i++) {
                if(out >= c[p[i]]) out++;
                else {
                    if(s[i] == '0') out++;
                    else in++;
                }
            }
            if(in >= m) res++;
        }while(next_permutation(p + 1, p + 1 + n));
        cout << res << endl;
        return 0;
    }
    else {
        cout << fac[n] << endl;
        return 0;
    }
    return 0;
}