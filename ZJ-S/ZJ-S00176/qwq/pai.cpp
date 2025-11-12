#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn = 1e4+10;
constexpr int maxm = 2e6+10;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
bool Mst;

typedef struct node
{
    int w,id,nex,now;
    bool operator<(const node& o)const
    {
        return nex>o.nex;
    }
}node;

int n,tal;
node ai[maxn][3];
priority_queue<node> q1;
priority_queue<node> q2;
priority_queue<node> q3;

void add(int);

void sub1()
{
    int a[2][3];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<3;++j)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    int ans=0;
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            if(i==j) continue;
            ans=max(ans,a[0][i]+a[1][j]);
        }
    }
    printf("%lld",ans);
}

bool add_rit(int id,int now)
{
    if(ai[id][now].id==0)
    {
        if(q1.size()==n/2)
        {
            if(q1.top().nex<ai[id][now].nex)
            {
                int ii=q1.top().id;
                q1.pop();
                q1.push({ai[id][now].w,id,ai[id][now].nex,now});
                add(ii);
            }
            else if(q1.top().nex==ai[id][now].nex)
            {
                if(ai[q1.top().id][q1.top().now+1].nex<ai[id][now+1].nex)
                {
                    int ii=q1.top().id;
                    q1.pop();
                    q1.push({ai[id][now].w,id,ai[id][now].nex,now});
                    add(ii);
                }
                else
                {
                    return 0;// ?
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            q1.push({ai[id][now].w,id,ai[id][now].nex,now});
        }
    }
    else if(ai[id][now].id==1)
    {
        if(q2.size()==n/2)
        {
            if(q2.top().nex<ai[id][now].nex)
            {
                int ii=q2.top().id;
                q2.pop();
                q2.push({ai[id][now].w,id,ai[id][now].nex,now});
                add(ii);
            }
            else if(q2.top().nex==ai[id][now].nex)
            {
                if(ai[q2.top().id][q2.top().now+1].nex<ai[id][now+1].nex)
                {
                    int ii=q2.top().id;
                    q2.pop();
                    q2.push({ai[id][now].w,id,ai[id][now].nex,now});
                    add(ii);
                }
                else
                {
                    return 0;// ?
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            q2.push({ai[id][now].w,id,ai[id][now].nex,now});
        }
    }
    else if(ai[id][now].id==2)
    {
        if(q3.size()==n/2)
        {
            if(q3.top().nex<ai[id][now].nex)
            {
                int ii=q2.top().id;
                q3.pop();
                q3.push({ai[id][now].w,id,ai[id][now].nex,now});
                add(ii);
            }
            else if(q3.top().nex==ai[id][now].nex)
            {
                if(ai[q3.top().id][q3.top().now+1].nex<ai[id][now+1].nex)
                {
                    int ii=q2.top().id;
                    q3.pop();
                    q3.push({ai[id][now].w,id,ai[id][now].nex,now});
                    add(ii);
                }
                else
                {
                    return 0;// ?
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            q3.push({ai[id][now].w,id,ai[id][now].nex,now});
        }
    }
    return 1;
}

void add(int id)
{
    for(int i=0;i<3;++i)
    {
        if(add_rit(id,i))
        {
            break;
        }
    }
}

int ans2;
int cnt[3];
int a2[15][4];

void dfs(int dep,int tal)
{
    if(dep>n)
    {
        ans2=max(ans2,tal);
        return;
    }
    for(int i=0;i<3;++i)
    {
        if(cnt[i]==n/2) continue;

        ++cnt[i];
        dfs(dep+1,tal+a2[dep][i]);
        --cnt[i];
    }
}


void sub2()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<3;++j)
        {
            scanf("%lld",&a2[i][j]);
        }
    }
    ans2=0;
    cnt[0]=cnt[1]=cnt[2]=0;
    dfs(1,0);
    printf("%lld\n",ans2);
}

void solve()
{
    scanf("%lld",&n);
    if(n<=2)
    {
        sub1();
        return;
    }
    if(n<=10)
    {
        sub2();
        return ;
    }


    for(int i=1;i<=n;++i)
    {
        scanf("%lld%lld%lld",&ai[i][0].w,&ai[i][1].w,&ai[i][2].w);
        ai[i][0].id=0;
        ai[i][1].id=1;
        ai[i][2].id=2;
        if(ai[i][0].w<ai[i][1].w)
        {
            swap(ai[i][0],ai[i][1]);
        }
        if(ai[i][1].w<ai[i][2].w)
        {
            swap(ai[i][1],ai[i][2]);
        }
        if(ai[i][0].w<ai[i][1].w)
        {
            swap(ai[i][0],ai[i][1]);
        }
        ai[i][0].nex=ai[i][0].w-ai[i][1].w;
        ai[i][1].nex=ai[i][1].w-ai[i][2].w;
        ai[i][2].nex=INF;
        add(i);
    }


    int tal=0;

    while(!q1.empty())
    {
        tal+=q1.top().w;
        q1.pop();
    }
    while(!q2.empty())
    {
        tal+=q2.top().w;
        q2.pop();
    }
    while(!q3.empty())
    {
        tal+=q3.top().w;
        q3.pop();
    }
    printf("%lld\n",tal);
}

bool Med;
signed main()
{
    freopen("club.in","r",stdin);
    freopen("pai.out","w",stdout);

    // cerr<<1.0*(&Med-&Mst)/1024/1024<<" M\n";

    int t;
    scanf("%lld",&t);
    while(t--)
    {
        solve();
    }

    return 0;
}
