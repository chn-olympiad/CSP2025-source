#include <bits/stdc++.h>
#define MAXN 500001
using namespace std;
int g[MAXN], n, k, ans = 0;
int qiuquan(int l, int r)
{
    int res = g[l];
    for (int i = l + 1; i <= r; ++ i)
        res ^= g[i];
    return res;
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) cin >> g[i];
    for (int i = 1; i <= n; ++ i)
        for (int j = i; j <= n; ++ j)
            if (qiuquan(i, j) == k)
                ++ ans, i = j;
    cout << ans << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
