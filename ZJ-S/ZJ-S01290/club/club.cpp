#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;
int a[N][3], n;
vector<int> g[3];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t --)
    {
        g[0].clear(), g[1].clear(), g[2].clear();
        scanf("%d", &n);
        int ans = 0;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
            int p = 0;
            if(a[i][1] > a[i][p]) p = 1;
            if(a[i][2] > a[i][p]) p = 2;
            int res = 1e9;
            if(p != 0) res = min(res, a[i][p] - a[i][0]);
            if(p != 1) res = min(res, a[i][p] - a[i][1]);
            if(p != 2) res = min(res, a[i][p] - a[i][2]);
            g[p].push_back(res);
            ans += a[i][p];
        }
        int p = -1;
        if(g[0].size() > n / 2) p = 0;
        if(g[1].size() > n / 2) p = 1;
        if(g[2].size() > n / 2) p = 2;
        if(p != -1)
        {
            int k = g[p].size() - n / 2;
            sort(g[p].begin(), g[p].end());
            for(int i = 0; i < k; i ++) ans -= g[p][i];
        }
        printf("%d\n", ans);
    }
    return 0;
}