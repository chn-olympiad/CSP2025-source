#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 505;
const ll Mod = 998244353;

ll f[MAXN][MAXN];
char s[MAXN];
ll n, m;
int sum[MAXN];
int c[MAXN];
int r[MAXN];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    scanf("%s", s+1);
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '0') sum[i]++;
        sum[i] += sum[i-1];
        scanf("%d", &c[i]);
    }
    sort(c + 1, c + n + 1);
    for(int i = 1, it = 1; i <= n; i++)
    {
        for(; sum[it] < c[i] && it <= n; ) it++;
        r[i] = it-1;
    }
    f[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j > 0 && r[i] - sum[r[i]] - j + 1 > 0)
            {
                f[i][j] += f[i-1][j-1] * (r[i] - sum[r[i]] - j + 1 - ((n - j - (n - r[i-1] + sum[r[i-1]])) > 0 ? (n - j - (n - r[i-1] + sum[r[i-1]])) : 0)) % Mod;
            }
            if(r[i] - sum[r[i]] - j >= 0 && n - r[i] + sum[r[i]] - (i-1-j) > 0) 
            {
                f[i][j] += f[i-1][j] * (n - r[i] + sum[r[i]] - (i-1-j)) % Mod;
            }
            f[i][j] %= Mod;
        }
    }
    ll ans = 0;
    for(int i = m; i <= n; i++) ans = (ans + f[n][i]) % Mod;
    printf("%lld", ans);

    return 0;
}