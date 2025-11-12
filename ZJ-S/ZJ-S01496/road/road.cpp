#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int to,next;
    long long w;
}a[3000001];
struct node
{
    int u,v;
    long long w;
    bool operator<(const node&x)const
        {return x.w<w;}
};
int n,k,cnt,head[100001];
inline long long read()
{
    char c=getchar();
    while (c<48||c>57)
        c=getchar();
    long long ans=0;
    while (c>47&&c<58)
        ans=ans*10+c-48,c=getchar();
    return ans;
}
inline void addedge(const int u,const int v,const long long w)
{
    a[++cnt].next=head[u];
    head[u]=cnt;
    a[cnt].to=v;
    a[cnt].w=w;
    return;
}
namespace test_1
{
    int main()
    {
        int cnt=1;
        priority_queue<node>q;
        for (int i=head[1];i!=0;i=a[i].next)
            q.push((node){1,a[i].to,a[i].w});
        vector<bool>f(n+k+1,false);
        f[1]=true;
        long long ans=0;
        while (cnt<n+k)
        {
            node t=q.top();
            q.pop();
            if (!f[t.v])
            {
                f[t.v]=true;
                cnt++;
                ans+=t.w;
                for (int i=head[t.v];i!=0;i=a[i].next)
                    if (!f[a[i].to])
                        q.push((node){t.v,a[i].to,a[i].w});
            }
        }
        printf("%lld",ans);
        return 0;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    int m=read();
    k=read();
    while (m--)
    {
        int u=read(),v=read();
        long long w=read();
        addedge(u,v,w);
        addedge(v,u,w);
    }
    if (k==0)
        return test_1::main();
    for (int i=1;i<=k;++i)
    {
        long long c=read();
        for (int j=1;j<=n;++j)
        {
            long long w=read();
            addedge(n+i,j,w);
            addedge(j,n+i,w);
        }
    }
    return test_1::main();
}