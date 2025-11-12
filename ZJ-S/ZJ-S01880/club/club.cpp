#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e5+10;
typedef struct node
{
    int va,id,a;
    bool operator<(const node &a)const
    {
        return this->va>a.va;
    }
} node;
int n;
int a[maxn][5];
int ma[maxn];
int idx[maxn];
int cnt[5];
int vis[maxn];
priority_queue<node> qi[5];
queue<node> q;
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(int i=1; i<=n; ++i)
        {
            ma[i]=0;
            idx[i]=0;
            vis[i]=0;
        }
        for(int j=1; j<=3; ++j)
        {
            cnt[j]=0;
        }
        int l=n/2;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=3; ++j)
            {
                scanf("%lld",&a[i][j]);
                if(a[i][j]>ma[i])
                {
                    ma[i]=a[i][j];
                    idx[i]=j;

                }
            }
            q.push({ma[i],idx[i],i});
        }
        while(!q.empty())
        {
            int x=q.front().va;
            int id=q.front().id;
            int i=q.front().a;
            q.pop();
            if(vis[i])
            {
                continue;
            }
            if(cnt[id]==l)
            {
                if(x<qi[id].top().va)
                {
                    int x2=0;
                    int id2=0;
                    int i2=qi[id].top().a;
                    for(int j=1; j<=3; ++j)
                    {
                        if(a[i2][j]>x2&&j!=id)
                        {
                            x2=a[i2][j];
                            id2=j;
                        }
                    }
                    if(x2+x>qi[id].top().va&&cnt[id2]<l)
                    {
                        qi[id2].push({x2,id2,i2});
                        qi[id].pop();
                        ++cnt[id2];
                        --cnt[id];
                    }
                    else
                    {
                        int x3=0;
                        int id3=0;
                        for(int j=1; j<=3; ++j)
                        {
                            if(a[i][j]>x3&&j!=id)
                            {
                                x3=a[i][j];
                                id3=j;
                            }
                        }
                        ma[i]=x3;
                        idx[i]=id3;
                        q.push({x3,id3,i});
                        continue;
                    }

                }
                else
                {
                    q.push({qi[id].top().va,id,qi[id].top().a});
                    vis[qi[id].top().a]=0;
                    qi[id].pop();
                    --cnt[id];
                }
            }
            qi[id].push({x,id,i});
            vis[i]=1;
            ++cnt[id];
        }
        int ans=0;
        for(int i=1; i<=3; ++i)
        {
            while(!qi[i].empty())
            {
                ans+=qi[i].top().va;
                //printf("%lld ",qi[i].top().va);
                qi[i].pop();
            }
            //printf("\n");
        }
        printf("%lld\n",ans);
    }
    return 0;
}

