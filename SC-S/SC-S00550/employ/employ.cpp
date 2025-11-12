#include <bits/stdc++.h>

const int N = 505, mod = 998244353;
int n, m, ans = 0;
int a [N], p [N];
char c [N];

void dfs (int step)
{
    if (step > n)
    {
        int cnt = 0, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (c [i] == '0' || (a [p [i]] <= sum))
            {
                sum++;
            }
            else
            {
                cnt++;
            }
        }
        ans += (cnt >= m);
        return ;
    }
    for (int i = 1; i <= n - step + 1; i++)
    {
        std::swap (p [i], p [n - step + 1]);
        dfs (step + 1);
        std::swap (p [i], p [n - step + 1]);
    }
}

int main ()
{
    freopen ("employ.in", "r", stdin);
    freopen ("employ.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    scanf ("%s", c + 1);
    bool flag = 1;
    for (int i = 1; i <= n; i++)
    {
        p [i] = i;
        scanf ("%d", a + i);
        if (c [i] == '0')
        {
            flag = 0;
        }
    }
    if (flag)
    {
        int mul = 1;
        for (int i = 1; i <= n; i++)
        {
            mul = 1ll * mul * i % mod;
        }
        printf ("%d\n", mul);
        return 0;
    }
    dfs (1);
    printf ("%d\n", ans);
    return 0;
}