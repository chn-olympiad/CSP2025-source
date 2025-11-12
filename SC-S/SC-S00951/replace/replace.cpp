#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define ll long long
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
const int N = 4e5+5,M = 5.5e6+5;
const ll mod = (1ll<<61)-1,B = 1e6+7;
int ans[N],id1[N],id2[N],n,q,len1,len2,m,tot;
int t[M][26],rt[N][2],dfn[M],siz[M],tim;
char s1[M],s2[M];
map<ll,int> mp;
struct node{int x,l,r,v;}p[N];
int ins(int r,char *s,int n)
{
    for(int i = 1;i <= n;i++)
    {
        int &x = t[r][s[i]-'a'];
        if(!x)x = ++tot;
        r = x;
    }
    return r;
}
int fd(int r,char *s,int n)
{
    for(int i = 1;i <= n;i++)
        if(t[r][s[i]-'a'])r = t[r][s[i]-'a'];
        else return r;
    return r;
}
inline ll mul(ll x,ll y){return ((__int128)x*1145141919810ll+y)%mod;}
ll get(char *s,int l,int r)
{
    ll sum = 0;
    for(int i = l;i <= r;i++)
        sum = ((__int128)sum*B+s[i])%mod;
    return sum;
}
void dfs(int u)
{
    dfn[u] = ++tim;siz[u] = 1;
    for(int i = 0,v;i < 26;i++)if(v = t[u][i])
        dfs(v),siz[u] += siz[v];
}
struct tree
{
    int t[M];
    inline void up(int i,int v){for(;i < M;i += i&-i)t[i] += v;}
    inline int get(int i){int s = 0;for(;i;i -= i&-i)s += t[i];return s;}
}tr;
inline void add(int l1,int r1,int l2,int r2)
{
    // cout << "add " << l1 << ' '<< r1 << ' ' <<l2 << ' ' << r2 << endl;
    p[++tim] = {l1,l2,r2,1};p[++tim] = {r1+1,l2,r2,-1};
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
inline void rds(char *s,int &n)
{
    char c;while((c = getchar()) <= ' ');
    s[n = 1] = c;
    while((c = getchar()) > ' ')s[++n] = c;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n = rd();q = rd();
    for(int i = 1;i <= n;i++)
    {
        rds(s1,len1);rds(s2,len2);
        int l = 1,r = len1;
        while(l <= len1&&s1[l] == s2[l])l++;
        while(r&&s1[r] == s2[r])r--;
        if(l > r)continue;
        int &x = mp[mul(get(s1,l,r),get(s2,l,r))];
        if(!x)x = ++m,rt[x][0] = ++tot,rt[x][1] = ++tot;
        reverse(s1+1,s1+l);
        id1[i] = ins(rt[x][0],s1,l-1);
        id2[i] = ins(rt[x][1],s1+r,len1-r);
        // cout << l << ' ' << r << endl;
        // cout << i << ' ' << x << ' ' << id1[i] << ' ' << id2[i] << endl;
    }
    for(int i = 1;i <= m;i++)
    {
        dfs(rt[i][0]),dfs(rt[i][1]);
        // cout << "fuck   " << i << ' ' << siz[rt[i][0]] << ' ' << siz[rt[i][1]] << endl;
    }
    tim = 0;
    for(int i = 1;i <= n;i++)if(id1[i])
    {
        int x = id1[i],y = id2[i];
        add(dfn[x],dfn[x]+siz[x]-1,dfn[y],dfn[y]+siz[y]-1);
    }
    for(int i = 1;i <= q;i++)
    {
        rds(s1,len1);rds(s2,len2);
        if(len1 != len2)continue;
        int l = 1,r = len1;
        while(l <= len1&&s1[l] == s2[l])l++;
        while(r&&s1[r] == s2[r])r--;
        int x = mp[mul(get(s1,l,r),get(s2,l,r))];
        if(!x)continue;
        reverse(s1+1,s1+l);
        int u = fd(rt[x][0],s1,l-1),v = fd(rt[x][1],s1+r,len1-r);
        if(u&&v)p[++tim] = {dfn[u],dfn[v],-1,i};
    }
    sort(p+1,p+tim+1,[](node x,node y){return x.x != y.x?x.x < y.x:x.r > y.r;});
    // for(int i = 1;i <= tim;i++)
    //     cerr << p[i].x << ' ' << p[i].l << ' ' << p[i].r << ' ' << p[i].v << endl;
    for(int i = 1;i <= tim;i++)
        if(~p[i].r)tr.up(p[i].l,p[i].v),tr.up(p[i].r+1,-p[i].v);
        else ans[p[i].v] = tr.get(p[i].l);
    for(int i = 1;i <= q;i++)printf("%d\n",ans[i]);
    return 0;
}