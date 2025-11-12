#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e2 + 5;
const int MOD = 998244353;

int n, m;
char s[MAXN];
int aa[MAXN], c[MAXN];
int res = 0;

void Solve(int dep, int a[], bool vis[])
{
    if (dep == n)
    {
        int mm = 0, cc = 0;
        for (int i = 1; i <= n; i++)
        {
            //cout << a[i] << ' ';
            if (s[i] == '0')
            {
                cc++;
                continue;
            }
            if (cc >= c[a[i]])
            {
                cc++;
                continue;
            }
            mm++;
        }
        //cout << '\n';
        //cout << mm << '\n';
        if (mm >= m) res = (res + 1) % MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            a[dep + 1] = aa[i];
            vis[i] = true;
            Solve(dep + 1, a, vis);
            vis[i] = false;
        }
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    int INIT_A[MAXN];
    bool INIT_VIS[MAXN];
    for (int i = 1; i <= n; i++)
    {
        aa[i] = i;
        INIT_A[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        INIT_VIS[i] = false;
    }
    Solve(0, INIT_A, INIT_VIS);

    cout << res;
    return 0;
}
