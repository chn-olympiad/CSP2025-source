#include <bits/stdc++.h>
using namespace std;
int n, a[5005], ans = 0;
void dfs(int x, int sum, int maxn)
{
    if (x > n)
    {
        if (sum > maxn * 2) ans = (ans + 1) % 998244353;
        return;
    }
    dfs(x + 1, sum, maxn);
    dfs(x + 1, sum + a[x], a[x]);
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    dfs(1, 0, 0);
    printf("%d\n", ans);
    return 0;
}