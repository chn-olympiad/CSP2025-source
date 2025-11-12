#include <bits/stdc++.h>
using namespace std;
long long n, m, k, ans = 0;
unordered_set<long long> nw_citi;
vector<long long> t_cst, u_pa;
vector<vector<long long>> e_cst;
vector<vector<pair<long long, long long>>> edg;
long long Ufind(long long x)
{
    if (u_pa[x] == -1)
        return x;
    return u_pa[x] = Ufind(u_pa[x]);
}
void Umerge(long long x, long long y)
{
    u_pa[Ufind(y)] = Ufind(x);
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    edg.resize(n + 1);
    u_pa.resize(n + 1, -1);
    t_cst.resize(k + 1);
    e_cst.resize(k + 1, vector<long long>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        edg[u].push_back({v, w});
        edg[v].push_back({u, w});
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> t_cst[i];
        for (int j = 1; j <= n; j++)
            cin >> e_cst[i][j];
    }
    using Ptt = pair<long long, int>;
    priority_queue<Ptt, vector<Ptt>, greater<Ptt>> q;
    q.push({0, 1});
    while (!q.empty())
    {
        auto hd = q.top();
        q.pop();
        for (auto targ : edg[hd.second])
        {
            if (Ufind(hd.second) != Ufind(targ.first))
            {
                Umerge(hd.second, targ.first);
                long long mnx = 0x7f7f7f7f7f7f7f7fLL, midx = -1;
                for (int X = 1; X <= k; X++)
                {
                    if (t_cst[X] * (!nw_citi.count(X)) + e_cst[X][hd.second] + e_cst[X][targ.first] < mnx)
                    {
                        mnx = t_cst[X] * (!nw_citi.count(X)) + e_cst[X][hd.second] + e_cst[X][targ.first];
                        midx = X;
                    }
                }
                nw_citi.insert(midx);
                if (mnx > targ.second)
                {
                    q.push({hd.first + targ.second, targ.first});
                    ans += targ.second;
                }
                else
                {
                    q.push({hd.first + mnx, targ.first});
                    ans += mnx;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}