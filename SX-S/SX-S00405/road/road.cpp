#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,a,b,c,cty[20][10010],p[20010],sum,ans,cst[20],cnt;
struct node
{
    ll a,b,c;
    bool operator<(const node &x) const
    {
        return c<x.c;
    }
}ed[2000010],ne[2000010];
int find(int x)
{
    return p[x]==x?p[x]:p[x]=find(p[x]);
}
ll kruskal(int tnc)
{
    ll res = 0;
    for (int i = 1;i <= n+k;i++) p[i] = i;
    for (int i = 0;i < tnc;i++)
    {
        ll pa = find(ed[i].a),pb = find(ed[i].b),w = ed[i].c;
        if (pa != pb)
        {
            p[pa] = pb;
            res += w;
        }
    }
    return res;
}
inline int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while(ch<'0'||ch>'9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x = (x<<1)+(x<<3)+(ch^48);
        ch = getchar();
    }
    return x*f;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n = read(); m = read(); k = read();
    for (int i = 0;i < m;i++)
    {
        a = read(); b = read(); c = read();
        ed[i] = {a,b,c};
    }
    for (int i = 1;i <= n;i++) p[i] = i;
    sort(ed,ed+m);
    // ans = 1e18;
    // for (int i = 0;i < m;i++) ne[cnt++] = ed[i];
    //497138407
    for (int i = 0;i < m;i++)
    {
        ll pa = find(ed[i].a),pb = find(ed[i].b),w = ed[i].c;
        if (pa != pb)
        {
            ne[cnt++] = ed[i];
            p[pa] = pb;
            ans += w;
        }
    }
    for (int i = 0;i < k;i++)
    {
        cst[i] = read();
        for (int j = 1;j <= n;j++)
            cty[i][j] = read();
    }
    for (int st = 1;st < (1<<k);st++)
    {
        sum = 0; cnt = 0;
        for (int i = 0;i < n;i++) ed[cnt++] = ne[i];
        for (int i = 0;i < k;i++)
            if ((st>>i)&1)
            {
                sum += cst[i];
                for (int j = 1;j <= n;j++)
                    ed[cnt++] = {n+i+1,j,cty[i][j]};
            }
        sort(ed,ed+cnt);
        ans = min(ans,kruskal(cnt)+sum);
        // cout << ans << " " << cnt << " " << sum << "\n";
    }
    cout << ans << "\n";
    return 0;
}