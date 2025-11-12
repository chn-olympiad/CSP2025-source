#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 510, mod = 998244353;

int n, m;
string s;
int c[N];
int p[N];

bool check() {
    int cnt0 = 0, cnt1 = 0;
    bitset<N> st;  
    for (int i = 1; i <= n; i ++) {
        if (st[p[i]]) continue;
        if (s[i - 1] == '0') cnt0 ++;
        else cnt1 ++;
        for (int j = i + 1; j <= n; j ++)
            if (cnt0 >= c[p[j]])
                cnt0 ++,
                st[p[j]] = 1;
    }
    return cnt1 >= m && cnt0 <= n - m;
}

int main() {
    freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i ++)
        cin >> c[i],
        p[i] = i;
    ll ans = 0;
    do {
        if (check()) {
            ans = (ans + 1) % mod;
        }
    } while (next_permutation(p + 1, p + n + 1));
    cout << ans;
    return 0;
}