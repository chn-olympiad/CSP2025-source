#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;

int n, m;
char ti[510];
int c[510];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", ti + 1);
    int yes = 1;
    for (int i = 1; i <= n; i++) {
        if (ti[i] == '0') {
            yes = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    if (yes) {
        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            ans *= i;
            ans %= mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
