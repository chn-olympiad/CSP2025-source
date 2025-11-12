#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e5+10;
int t;
int n;
int a[maxn][5];
int flag[maxn];
int cnt[5];
int ans;
typedef struct node
{
    int idx,w,type;
    node (int x,int y,int c)
    {
        this->idx=x;
        this->w=y;
        this->type=c;
    }
    bool operator<(const node &other)const
    {
        return this->w<other.w;
    }
}node;
priority_queue<node> dq;
void solve()
{
    while(!dq.empty())
    {
        dq.pop();
    }
    int k=n/2;
    for(int i=1;i<=n;++i)
    {
        dq.push({i,a[i][1],1});
        dq.push({i,a[i][2],2});
        dq.push({i,a[i][3],3});
    }
    while(!dq.empty())
    {
        int idx=dq.top().idx;
        int w=dq.top().w;
        int c=dq.top().type;
        dq.pop();
       // printf("%lld %lld %lld\n",idx,w,c);
        if(flag[idx]||cnt[c]>=k)
        {
            //printf("%lld %lld",flag[idx],cnt[c]);
           // printf("?\n");
            continue;
        }
        else
        {
            //printf("!\n");
           // printf("%lld %lld %lld\n",idx,w,c);
            ans+=w;
            flag[idx]=1;
            ++cnt[c];
        }
    }
    printf("%lld",ans);
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
        }
        ans=0;
        cnt[1]=0;
        cnt[2]=0;
        cnt[3]=0;
        memset(flag,0,sizeof(flag));
        solve();
        printf("\n");
    }
    return 0;
}
