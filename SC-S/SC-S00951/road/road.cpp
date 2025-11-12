#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
const int N = 1e4+15,M = 1e6+5;
int f[N],a[15][N],w[15],n,m,k,tot;
ll ans = 1e18;
int fd(int x){return x==f[x]?x:f[x] = fd(f[x]);}
struct node{int x,y,w;}e[M];
ll solve(int S)
{
    for(int i = 1;i <= n+k;i++)f[i] = i;
    ll sum = 0;int cnt = n;
    for(int i = 0;i < k;i++)
        if(S>>i&1)sum += w[i],cnt++;
    for(int i = 1;i <= m&&cnt > 1;i++)if(e[i].x <= n||S>>e[i].x-n-1&1)
    {
        int x = fd(e[i].x),y = fd(e[i].y);
        if(x != y)f[x] = y,sum += e[i].w,cnt--;
    }
    return sum;
}
char buf[1<<21],*p1,*p2;
inline int rd()
{
    char c;int f = 1;
    while(!isdigit(c = getchar()))if(c=='-')f = -1;
    int x = c^48;
    while(isdigit(c = getchar()))x = x*10+(c^48);
    return x*f;
}
inline char gc()
{char c;while((c = getchar()) <= ' ');return c;}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n = rd();m = rd();k = rd();
    for(int i = 1;i <= n;i++)f[i] = i;
    for(int i = 1;i <= m;i++)e[i] = {rd(),rd(),rd()};
    sort(e+1,e+m+1,[](node x,node y){return x.w < y.w;});
    for(int i = 1;i <= m;i++)
    {
        int x = fd(e[i].x),y = fd(e[i].y);
        if(x != y)e[++tot] = e[i],f[x] = y;
    }
    m = tot;
    for(int i = 0;i < k;i++)
    {
        w[i] = rd();
        for(int j = 1;j <= n;j++)e[++m] = {n+i+1,j,rd()};
    }
    sort(e+1,e+m+1,[](node x,node y){return x.w < y.w;});
    // for(int i = 1;i <= m;i++)
    //     cout << e[i].x << ' ' << e[i].y << ' ' << e[i].w << ' ' << e[i].id << endl;
    for(int S = 0;S < (1<<k);S++)ans = min(ans,solve(S));
    cout << ans << endl;
    return 0;
}