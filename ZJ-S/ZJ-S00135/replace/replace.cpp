#include<bits/stdc++.h>
#define int long long
#define FL(i, a, b) for(int i = (a), i##end = (b); i <= i##end; ++i)
#define FR(i, a, b) for(int i = (a), i##end = (b); i >= i##end; --i)
using namespace std;
constexpr int N = 1e6 + 10, base = 97, mod = 1e9 + 7;
int n, q, s1[N], s2[N], S1[N], S2[N], len[N];
inline void cmin(int&a, int b){if(a > b)a = b;}
int qpow(int a, int b, int ans = 1){
    for(;b; (a *= a) %= mod, b >>= 1)
        if(b & 1)(ans *= a) %= mod;
    return ans;
}
void ___(){
    cin >> n >> q;
    string a, b;
    FL(i, 1, n){
        cin >> a >> b, len[i] = a.size();
        FL(j, 0, a.size() - 1)s1[i] = (s1[i] * base + (a[j] - 'a' + 1)) % mod;
        FL(j, 0, a.size() - 1)s2[i] = (s2[i] * base + (b[j] - 'a' + 1)) % mod;
    }
    while(q--){
        cin >> a >> b;int l = a.size(), r = 0, ans = 0;
        if(a.size() != b.size()){cout << 0 << endl;continue;}
        FL(i, 0, a.size() - 1)if(a[i] != b[i])r = i, cmin(l, i);
        FL(i, 0, a.size() - 1)S1[i] = (S1[i - 1] * base + (a[i] - 'a' + 1)) % mod;
        FL(i, 0, a.size() - 1)S2[i] = (S2[i - 1] * base + (b[i] - 'a' + 1)) % mod;
        FL(i, 1, n)if(len[i] >= r - l + 1)
            FL(j, max(0ll, r - len[i] + 1), l)if(len[i] + j <= a.size()){
                int f1 = (S1[j + len[i] - 1] - qpow(base, len[i], S1[j - 1]) + mod) % mod;
                int f2 = (S2[j + len[i] - 1] - qpow(base, len[i], S2[j - 1]) + mod) % mod;
                if(f1 == s1[i] && f2 == s2[i]){ans++;break;}
            }
            else break;
        cout << ans << endl;
    }
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int t = 1;
    while(t--)___();
    return 0;
}