#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn = 1e5+10;

typedef struct node
{
    int w,id,now;
    bool operator<(const node& o)const
    {
        return w>o.w;
    }
}node;

int n,tal;
node ai[maxn][3];

priority_queue<node> q1;
priority_queue<node> q2;
priority_queue<node> q3;

void add(int);

bool add_rit(int id,int now)
{
    if(ai[id][now].id==0)
    {
        if(q1.size()==n/2)
        {
            if(q1.top().w<ai[id][now].w)
            {
                q1.pop();
                q1.push({ai[id][now].w,id,now});
                add(q1.top().id);

            }
            else if(q1.top().w==ai[id][now].w)
            {
                if(ai[q1.top().id][q1.top().now+1].w>ai[id][now+1].w)
                {
                    q1.pop();
                    q1.push({ai[id][now].w,id,now});
                    add(q1.top().id);

                }
                else
                {
                    return 0;// ?
                }
            }
        }
        else
        {
            q1.push({ai[id][now].w,id,now});
        }
    }
    else if(ai[id][now].id==1)
    {
        if(q2.size()==n/2)
        {
            if(q2.top().w<ai[id][now].w)
            {
                q2.pop();
                q2.push({ai[id][now].w,id,now});
                add(q2.top().id);
            }
            else if(q2.top().w==ai[id][now].w)
            {
                if(ai[q2.top().id][q2.top().now+1].w>ai[id][now+1].w)
                {
                    q2.pop();
                    q2.push({ai[id][now].w,id,now});
                    add(q2.top().id);

                }
                else
                {
                    return 0;// ?
                }
            }
        }
        else
        {
            q2.push({ai[id][now].w,id,now});
        }
    }
    else if(ai[id][now].id==2)
    {
        if(q3.size()==n/2)
        {
            if(q3.top().w<ai[id][now].w)
            {
                q3.pop();
                q3.push({ai[id][now].w,id,now});
                add(q3.top().id);
            }
            else if(q3.top().w==ai[id][now].w)
            {
                if(ai[q3.top().id][q3.top().now+1].w>ai[id][now+1].w)
                {
                    q3.pop();
                    q3.push({ai[id][now].w,id,now});
                    add(q3.top().id);

                }
                else
                {
                    return 0;// ?
                }
            }
        }
        else
        {
            q3.push({ai[id][now].w,id,now});
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

void solve()
{
    tal=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld%lld%lld",&ai[i][0].w,&ai[i][1].w,&ai[i][2].w);
        ai[i][0].id=0;
        ai[i][1].id=1;
        ai[i][2].id=2;
        sort(ai[i],ai[i]+3);
        add(i);
    }
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
