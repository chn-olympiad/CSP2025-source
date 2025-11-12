#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int n = 0,m = 0,k = 0,ans = 0;
struct node
{
    int u,v,w;
}a[N];
bool cmp(node c,node d) { return c.w < d.w;}

int fa[N];
int find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void Union(int x,int y)
{
    int f_x = find(x),f_y = find(y);
    fa[f_x] = f_y;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
        fa[i] = i;
    }
    for(int i = 1;i <= k;i++)
    {
        int app = 0;
        for(int j = 1;j <= n+1;j++) scanf("%d",a[j]);
    }
    sort(a + 1,a + m + 1,cmp);
    for(int i = 1;i <= m;i++)
    {
        if(find(a[i].u) == find(a[i].v)) continue;
        ans += a[i].w;
        Union(a[i].u,a[i].v);
    }
    cout << ans;
    return 0;
}