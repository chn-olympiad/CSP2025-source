#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, mod = 998244353;

int n, m, c[N], ans;
string s;

signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s; s = " " + s;
    for (int i = 1; i <= n; i++) cin >> c[i];
    
    if (m == n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '0')
            {
                cout << "0\n"; return 0;
            }
        }
    }

    ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * i % mod;
    }
    cout << ans << "\n";
    return 0;
}