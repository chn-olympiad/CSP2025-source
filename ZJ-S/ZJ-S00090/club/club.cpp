#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5;

int T, n, w[N][4], b[N], ans;
int f[205][105][105];

void tp()
{
    for (int i = 1; i <= n; i++)
    {
        b[i] = w[i][1];
    }
    sort(b + 1, b + n + 1);
    ans = 0;
    for (int i = n; i >= n / 2 + 1; i--) ans += b[i];
    cout << ans << "\n";
}

void baoli()
{
    bool fl = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> w[i][1] >> w[i][2] >> w[i][3];
        if (w[i][2] != 0 || w[i][3] != 0) fl = 0;
    }
    
    if (fl)
    {
        tp();
        return;
    }
        
    memset(f, 0, sizeof f);
    f[1][1][0] = w[1][1];
    f[1][0][1] = w[1][2];
    f[1][0][0] = w[1][3];
    for (int i = 2; i <= n; i++)
    {
        for (int a = 0; a <= i; a++)
        {
            for (int b = 0; b <= i; b++)
            {
                int c = i - a - b;
                if (c < 0) continue;
                if (a <= n / 2 && b <= n / 2 && c <= n / 2)
                {
                    f[i][a][b] = max(f[i][a][b], f[i-1][a-1][b] + w[i][1]);
                    f[i][a][b] = max(f[i][a][b], f[i-1][a][b-1] + w[i][2]);
                    f[i][a][b] = max(f[i][a][b], f[i-1][a][b] + w[i][3]);
                    //cout << i << " "<<  a << " " << b << " "<< c << ":" << f[i][a][b]<< "\n";
                }
                
            }
        }
    }

    ans = 0;
    for (int a = 0; a <= n / 2; a++)
        for (int b = 0; b <= n / 2; b++)
        {
            int c = n - a - b;
            if (a <= n / 2 && b <= n / 2 && c <= n / 2 && c >= 0)
            {
                // if (f[n][a][b] > ans) 
                // {
                //     cout << f[n][a][b] << ":" << a << " " << b  << " " << n - a - b << "\n";
                // }
                ans = max(ans, f[n][a][b]);
            }
        }
    cout << ans << "\n";
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        baoli();
    }
    return 0;
}