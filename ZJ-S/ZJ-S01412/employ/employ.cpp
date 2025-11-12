#include<bits/stdc++.h>
#define int long long
#define void inline void
using namespace std;
const int maxn = 550, mod = 998244353;
int n, m;
char s[maxn];
int c[maxn], a[maxn];
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    int czs = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if (!c[i])
        {
            czs--;
        }
        a[i] = i;
    }
    if (n > 10)
    {
        if (czs < m)
        {
            cout << 0 << '\n';
            return 0;
        }
        int pdt = 1;
        for (int i = 2; i <= n; i++)
        {
            pdt = pdt * i % mod;
        }
        cout << pdt << '\n';
        return 0;
    }
    int ans = 0;
    do
    {
        int o = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '0' || o >= c[a[i]])
            {
                o++;
            }
        }
        if (o <= n - m)
        {
            ans++;
        }
    } while (next_permutation(a + 1, a + n + 1));
    cout << ans;
    return 0;
}

