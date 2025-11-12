#include <bits/stdc++.h>
using namespace std;

const int N = 500;
int n , m , c[N] , f[20][20][300005];
string s;

signed main()
{
    freopen("employ.in" , "r" , stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s; s = '#' + s;
    for(int i = 1 ; i <= n ; i++)
        cin >> c[i];
    for (int i = 1; i <= n ; i++) for(int k = 1 ; k <= i ; k++)
    {
        for (int j = 0; j < (1 << n) ; j++)
        {
            if(s[i] == '1')
            {
                for (int id = 1; id <= n ; id++) if(j & (1 << id - 1))
                {
                    if(c[id] <= k - 1)
                        f[i][k][j] += f[i][k - 1][j - (1 << id - 1)];
                    else if(c[id] > k)
                        f[i][k][j] += f[i][k][j - (1 << id - 1)];
                }
            }
            else
            {
                for (int id = 1; id <= n ; id++) if(j & (1 << id - 1))
                {
                    f[i][k][j] += f[i][k - 1][j - (1 << id - 1)];
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i <= n - m ; i++) ans += f[n][i][(1 << n) - 1];
    cout << ans << '\n';
    return 0;
}