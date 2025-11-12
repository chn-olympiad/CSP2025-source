#include<bits/stdc++.h>
using namespace std;
#define maxn 503
#define mod 998244353

ifstream is("employ.in", ios::in);
ofstream os("employ.out", ios::out);
#define cin is
#define cout os

int c[maxn];
int sum[maxn];

int tot=0, n, m;
string a;
bool vis[maxn];
int ans[maxn][1<<18];
int dfs(int td=0, int s=0, int S=0)
{
    if(td==n) {return s>=m; }
    if(ans[s][S]!=-1) return ans[s][S];
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        if(S&(1<<(i-1))) continue;
        vis[i]=1;
        if(a[td]=='0') ret=(ret+dfs(td+1, s, S|(1<<(i-1))))%mod;
        else ret=(ret+dfs(td+1, s+(c[i]>td-s), S|(1<<(i-1))))%mod;
        vis[i]=0;
    }
    return ans[s][S]=ret;
}

signed main()
{
    memset(ans, -1, sizeof ans);
    cin>>n>>m;
    cin>>a;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i-1]=='0';
    cout<<dfs();
}