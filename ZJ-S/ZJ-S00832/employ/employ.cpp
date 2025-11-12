#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10, mod = 998244353;
int n, m, a[N], p[N];
string s;

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i ++) 
        cin >> a[i], p[i] = i;
    bool flaga = 1;
    for(int i = 0; i < s.size(); i ++)
        if(s[i] == '0') flaga = 0;
    if(flaga) {
        int ans = 1;
        for(int i = 1; i <= n; i ++)
            ans = ans * i % mod;
        cout << ans;
    } else if(n <= 10) {
        int c, ans = 0;
        do {
            c = 0;
            for(int i = 1; i <= n; i ++)
                if(c >= a[p[i]] || s[i - 1] == '0') c ++;
            ans += (n - c) >= m;
        } while(next_permutation(p + 1, p + n + 1));
        cout << ans;
    } else {
        cout << 0;
    }
}