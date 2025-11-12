#include<bits/stdc++.h>
#define int long long
#define void inline void
using namespace std;
const int maxn = 5e+6 + 6, N = 2e+5 + 5, base = 137, mod = 999999999999989;
int n, T, l1, l2;
string s1, s2;
int hs1[N], hs2[N], f[maxn], g[maxn], len1[N], len2[N];
int ret_hsh(int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    // cout << "R: " << f[r] << '\n';
    return (f[r] - f[l - 1] * g[r - l + 1] % mod + mod) % mod;
}
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> T;
    g[0] = 1;
    for (int i = 1; i <= 5e+6; i++)
    {
        g[i] = g[i - 1] * base % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> s1;
        l1 = s1.length();
        s1 = '@' + s1;
        cin >> s2;
        l2 = s2.length();
        s2 = '@' + s2;
        // cout << s1 << ' ' << s2 << '\n'; 
        for (int j = 1; j <= l1; j++)
        {
            hs1[i] = (hs1[i] * base % mod + s1[j] - 'a' + 1) % mod;
        }
        for (int j = 1; j <= l2; j++)
        {
            hs2[i] = (hs2[i] * base % mod + s2[j] - 'a' + 1) % mod;
        }
        len1[i] = l1, len2[i] = l2;
//        cout << len[i] << ' ' << hs1[i] << ' ' << hs2[i] << '\n';
    }
    while (T--)
    {
        cin >> s1;
        l1 = s1.length();
        s1 = '@' + s1;
        cin >> s2;
        l2 = s2.length();
        s2 = '@' + s2;
        // cout << "l1: " << l1 << '\n';
        for (int i = 1; i <= l1; i++)
        {
            f[i] = (f[i - 1] * base % mod + s1[i] - 'a' + 1) % mod;
        }
        int hs = 0;
        for (int i = 1; i <= l2; i++)
        {
            hs = (hs * base % mod + s2[i] - 'a' + 1) % mod;
        }
        // cout << "hs: " << hs << '\n';
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = len1[i]; j <= l1; j++)
            {
                if (ret_hsh(j - len1[i] + 1, j) == hs1[i])
                {
                    // cout << "i: " << i << " j: " << j << '\n';
                    int R = l1 - j;
                    int w = (ret_hsh(1, j - len1[i]) * g[R + len2[i]] % mod + hs2[i] * g[R] % mod + ret_hsh(j + 1, l1)) % mod;
                    // cout << "j - len[i]: " << j - len[i] << '\n';
                    // cout << ret_hsh(1, j - len[i]) << '\n';
                    // cout << "w: " << w << '\n';
                    if (w == hs)
                    {
                    	// cout << "gogo" << '\n';
                        ans++;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

