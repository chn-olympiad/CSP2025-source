#include <bits/stdc++.h>
using namespace std;
int n, k, ans = -1;
int s[500005];
int f[500005];
int maxn[500005];
void dfs(int dep, int cnt)
{
    if (cnt <= maxn[dep])
        return;
    if (dep > n)
    {
        ans = max(ans, cnt);
        return;
    }
    maxn[dep] = cnt;
    if (f[dep] != 0) dfs(f[dep] + 1, cnt + 1);
    dfs(dep + 1, cnt);
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        s[i] = s[i - 1] ^ t;
        maxn[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int x = s[j] ^ s[i - 1];
            if (x == k) 
            {
                f[i] = j;
                break;
            }
        }
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}