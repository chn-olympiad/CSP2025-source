#include "bits/stdc++.h"
#define F(i,x,y) for (int i = (x); i <= (y); ++ i)
#define D(i,x,y) for (int i = (x); i >= (y); -- i)
#define ll long long
#define OPEN freopen ("replace.in", "r", stdin); freopen ("replace.out", "w", stdout);
#define IOS ios :: sync_with_stdio (false); cin.tie (0); cout.tie (0);

constexpr int N = 2e5 + 5, L = 5e6 + 5;

using namespace std;

map <pair <ll, ll>, int> mp; 
constexpr ll mod1 = 993244853LL, mod2 = 1LL * 1e9 + 9LL;
constexpr ll base1 = 129LL, base2 = 131LL;
int n, q;



struct ACAM {
    int tr[L][30], fail[L][30];

    void insert (string s) {
    }
} ;

namespace Hash {
    ll pw[2][L];
    ll h[L][2][2];
    int n, m;
    void init (string s, string t) {
        n = s.size (), m = t.size ();
        pw[0][0] = pw[1][0] = 1LL;
        F (i, 1, max (n, m)) pw[0][i] = pw[1][i - 1] * base1 % mod1;
        F (i, 1, max (n, m)) pw[1][i] = pw[1][i - 1] * base2 % mod2;
        F (i, 1, n) h[i][0][0] = (h[i - 1][0][0] * base1 + s[i - 1]) % mod1;
        F (i, 1, n) h[i][0][1] = (h[i - 1][0][1] * base2 + s[i - 1]) % mod2;
        F (i, 1, m) h[i][1][0] = (h[i - 1][1][0] * base1 + s[i - 1]) % mod1;
        F (i, 1, m) h[i][1][1] = (h[i - 1][1][1] * base2 + s[i - 1]) % mod2;
    }

    ll getVal (int L, int R, int id, int id2) {
        const ll mod[2] = {mod1, mod2};
        return (h[R][id][id2] + mod[id2] - h[L - 1][id][id2] * pw[id2][R - L + 1] % mod[id2]) % mod[id2];
    }

    int LCP () {
        int L = 1, R = min (n, m);
        int res = 0;
        while (L <= R) {
            int m = (L + R) >> 1;
            if (getVal (1, m, 0, 0) == getVal (1, m, 1, 0) && getVal (1, m, 0, 1) == getVal (1, m, 1, 1))
                res = m, L = m + 1;
            else R = m - 1;
        }
        return res;
    }

    int LCS () {
        int L = 1, R = min (n, m);
        int res = 0;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (getVal (n - mid + 1, n, 0, 0) == getVal (m - mid + 1, m, 1, 0)
                && getVal (n - mid + 1, n, 0, 1) == getVal (m - mid + 1, m, 1, 1))
                    res = mid, L = mid + 1;
            else R = mid - 1;
        }
        return res;
    }

    pair <ll, ll> calc () {
        ll _1 = LCP (), _2 = LCS ();
        ll val1 = getVal (_1 + 1, _2 - 1, 0, 0) * base1 % mod1 * base1 % mod1 + getVal (_1 + 1, _2 - 1, 1, 0);
        ll val2 = getVal (_1 + 1, _2 - 1, 0, 1) * base2 % mod2 * base2 % mod2 + getVal (_1 + 1, _2 - 1, 1, 1);

        return {val1, val2};
    }
}

int cnt;

string s[N], t[N];

string _s[N], _t[N];

vector <int> v[N], qs[N];

ll ans[N];

int main () {
    OPEN
    IOS
    cin >> n >> q;

    F (i, 1, n) {
        string s, t;
        cin >> s >> t;
        if (s == t) continue;
        Hash :: init (s, t);
        auto val = Hash :: calc ();
        :: s[i] = s, :: t[i] = t;
        if (mp.find (val) == mp.end ()) mp[val] = ++ cnt;
        v[mp[val]].push_back (i);
    }

    F (i, 1, q) {
        cin >> _s[i] >> _t[i];
        if (_s[i].size () != _t[i].size ()) continue;

        Hash :: init (_s[i], _t[i]);
        auto val = Hash :: calc ();

        if (mp.find (val) == mp.end ()) continue;
        qs[mp[val]].push_back (i);
    }
    
    F (i, 1, cnt) {

    }

    sizeof (ACAM) >> 20;
    return 0;
}