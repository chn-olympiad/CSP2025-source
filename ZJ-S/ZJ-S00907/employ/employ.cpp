#include <bits/stdc++.h>
using namespace std;
const int N = 20;
const int mod = 998244353;

int n, m, c[N];
string s;
int f[1 << N][N], bcnt[1 << N];

void Main()
{
    cin >> n >> m >> s;
    s = " " + s;
    for (auto &x : s)
        x = (x - '0') ^ 1;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int S = 1; S < (1 << n); S++)
    {
        bcnt[S] = bcnt[S >> 1] + (S & 1);
    }
    f[0][0] = 1;
    for (int S = 0; S < (1 << n) - 1; S++)
    {
        // cerr << "qq ";
        // for (int i = 0; i <= 3; i++)
        //     cerr << f[S][i] << ' ';
        // cerr << "qq\n";
        int B = s[bcnt[S] + 1];
        int cnt = bcnt[S];
        for (int i = 0; i < n; i++)
        {
            if (!(S & (1 << i)))
            {
                int k = min(cnt, c[i] - 1);
                auto &F = f[S | (1 << i)];
                for (int j = 0; j <= k; j++)
                {
                    F[j + B] += f[S][j];
                    // cerr << (S | (1 << i)) << ' ' << S << ' ' << j << ' ' << j + B << endl;
                    if (F[j + B] >= mod)
                        F[j + B] -= mod;
                }
                for (int j = k + 1; j <= cnt; j++)
                {
                    F[j + 1] += f[S][j];
                    // cerr << (S | (1 << i)) << ' ' << S << ' ' << j << ' ' << j + 1 << endl;
                    if (F[j + 1] >= mod)
                        F[j + 1] -= mod;
                }
            }
        }
        // cerr << endl;
    }
    int res = 0;
    for (int i = 0; i <= n - m; i++)
    {
        res += f[(1 << n) - 1][i];
        if (res >= mod)
            res -= mod;
    }
    cout << res << endl;
}

signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    Main();
    return 0;
}