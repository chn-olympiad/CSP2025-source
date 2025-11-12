#include<bits/stdc++.h>
#define ll long long
#define reg register
#define ls u<<1
#define rs u<<1|1
#define PII pair<int,int>
#define fi first 
#define se second 
#define _128 __int128
using namespace std;
inline int inint()
{
    int x = 0, f = 1;
    char c = getchar();
    while((c < '0') || (c > '9'))
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while((c >= '0') && (c <= '9'))
    {
        x = x*10 + (c^'0');
        c = getchar();
    }
    return f*x;
}
inline ll inll()
{
    ll x = 0, f = 1;
    char c = getchar();
    while((c < '0') || (c > '9'))
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while((c >= '0') && (c <= '9'))
    {
        x = x*10 + (c^'0');
        c = getchar();
    }
    return f*x;
}
inline _128 read()
{
    __int128 x = 0, f = 1;
    char c = getchar();
    while((c < '0') || (c > '9'))
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while((c >= '0') && (c <= '9'))
    {
        x = x*10 + (c^'0');
        c = getchar();
    }
    return f*x;
}
void print(__int128 x)
{
    if(x < 0) 
    {
        putchar('-');
        x = -x;
    }
    if(x > 9) print(x/10);
    putchar(x%10+'0');
}
int n, m, k;  
bool st[6050];
int f[6050], sz[6050];
ll ans = 1e18;
struct node
{
    int u, v;
    ll val;
    bool operator < (const node &a) const
    {
        return val < a.val;
    }
}edge[1000010];
int find(int x)
{
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}
namespace P10
{
    void solve()
    {
        int a, b;
        ll w;
        for(int i =1; i <= m; i++)
        {
            a = inint(), b = inint(), w = inll();
            edge[i].u = a, edge[i].v = b, edge[i].val = w;
        }
        for(int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
        sort(edge+1, edge+1+m);
        ll sum = 0;
        for(int i = 1; i <= m; i++) 
        {
            int u = edge[i].u, v =edge[i].v;
            int fu = find(u), fv = find(v);
            if(fu != fv)
            {
                if(sz[fu] > sz[fv]) swap(fu, fv);
                f[fu] = fv;
                sum += edge[i].val;
                sz[fv] += sz[fu];
            }
        }
        printf("%lld", sum);
    }
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = inint(), m = inint(), k =  inint();
    P10::solve();
    return 0;
}