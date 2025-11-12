#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n, q;
pair<pair<ll,ll>,ll> p[200010];

ll base = 31, mod = 1000000007;
ll b[200010];
ll Hash1(string s, ll len) {
    ll ret = 0;
    for (int i = 1; i <= len; i++) {
        ret *= base;
        ret += (s[i] - 'a' + 1);
        ret %= mod;
    }
    return ret;
}
void Hash2(vector<ll>& h, string s, ll len) {
    for (int i = 1; i <= len; i++) {
        h[i] = h[i - 1] * base;
        h[i] += (s[i] - 'a' + 1);
        h[i] %= mod;
    }
}
ll geth(vector<ll>& h, ll l, ll r, ll len) {
    ll x = h[l - 1] * b[r - l + 1];
    ll y = ((h[r] - x) % mod + mod) % mod;
    return y;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    b[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        b[i] = (b[i - 1] * base) % mod;
    }
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        ll len = s1.length();
        s1 = " " + s1;
        s2 = " " + s2;
        p[i] = {{Hash1(s1, len), Hash1(s2, len)}, len};
    }
    while (q--) {
            ll ans =0;
        string t1, t2;
        cin >> t1 >> t2;
        ll len = t1.length();
        t1 = " " + t1, t2 = " " + t2;
        vector<ll> h1(len + 2), h2(len + 2);
        Hash2(h1, t1, len);
        Hash2(h2, t2, len);
        for (int i = 1; i <= n; i++) {
            ll l = p[i].second;
            ll od = p[i].first.first, nw = p[i].first.second;
            for (int i = 1; i + l - 1 <= len; i++) {
                ll a = geth(h1, i, i + l - 1, len);
                ll c = geth(h2, i, i + l - 1, len);
                if (a == od && c == nw && ((h1[len] - a * b[len - (i + l - 1)] + c * b[len - (i + l - 1)]) % mod+ mod)%mod == h2[len]) {
                    ans++;
                }
            }
        }
    cout << ans << "\n";
    }
    return 0;
}
