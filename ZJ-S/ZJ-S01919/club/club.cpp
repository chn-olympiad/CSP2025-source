#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e5+10;

int n;

typedef struct node{
    int a[4],idx;
}node;
node nd[maxn];

int cnt[4]={0,0,0,0};
int ans=0;

void dfs(int i,int now_val)
{
    if(i==n)
    {
        ans=max(ans,now_val);
        return;
    }
    for(int j=1;j<=3;++j)
    {
        if(cnt[j]<n/2)
        {
            cnt[j]++;
            dfs(i+1,now_val+nd[i+1].a[j]);
            cnt[j]--;
        }
    }
    dfs(i+1,now_val);
}

void solve()
{
    ans=0;
    scanf("%lld",&n);
    memset(vis,0,sizeof vis);
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;++i)
    {
        int x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        nd[i].a[1]=x,nd[i].a[2]=y,nd[i].a[3]=z;
        nd[i].idx=i;
    }
    dfs(0,0);
    printf("%lld\n",ans);
}

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%lld",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}

