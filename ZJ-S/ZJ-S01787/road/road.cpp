#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0;
    char ch=getchar();
    while(!isdigit(ch))
    {
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

struct edge
{
    int u,v,w;
}e1[1000005],e2[100005];
inline bool operator < (edge x,edge y)
{
    return x.w<y.w;
}

int n,m,k;
long long ans;
int c[15];

int fa[10015];
int find(int x)
{
    if(fa[x]==x)
    {
        return x;
    }
    return fa[x]=find(fa[x]);
}
int main ()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();k=read();
    for(int i=1;i<=m;i++)
    {
        e1[i].u=read();e1[i].v=read();e1[i].w=read();
    }
    sort(e1+1,e1+m+1);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    int now=0;
    for(int i=1;i<=m;i++)
    {
        if(now==n-1)
        {
            break;
        }
        int fu=find(e1[i].u),fv=find(e1[i].v);
        if(fu!=fv)
        {
            now++;
            e1[now]=e1[i];
            ans+=e1[i].w;
            fa[fu]=fv;
        }
    }
    for(int i=1;i<=k;i++)
    {
        c[i]=read();
        for(int j=1;j<=n;j++)
        {
            int id=(i-1)*n+j;
            e2[id].u=i;e2[id].v=j;e2[id].w=read();
        }
    }
    sort(e2+1,e2+k*n+1);
    for(int S=1;S<(1<<k);S++)
    {
        for(int i=1;i<=n+k;i++)
        {
            fa[i]=i;
        }
        int cnt=0;
        long long s=0;
        for(int i=1;i<=k;i++)
        {
            if((S>>(i-1))&1)
            {
                cnt++;
                s+=c[i];
            }
        }
        int i=1,j=1;
        now=0;
        while(now<n+cnt-1)
        {
            if(i>n-1)
            {
                if((S>>(e2[j].u-1))&1)
                {
                    int fu=find(e2[j].u+n),fv=find(e2[j].v);
                    if(fu!=fv)
                    {
                        now++;
                        s+=e2[j].w;
                        fa[fu]=fv;
                    }
                }
                j++;
                continue;
            }
            if(j>n*k)
            {
                int fu=find(e1[i].u),fv=find(e1[i].v);
                if(fu!=fv)
                {
                    now++;
                    s+=e1[i].w;
                    fa[fu]=fv;
                }
                i++;
                continue;
            }
            if(e1[i].w<=e2[j].w)
            {
                int fu=find(e1[i].u),fv=find(e1[i].v);
                if(fu!=fv)
                {
                    now++;
                    s+=e1[i].w;
                    fa[fu]=fv;
                }
                i++;
            }
            else
            {
                if((S>>(e2[j].u-1))&1)
                {
                    int fu=find(e2[j].u+n),fv=find(e2[j].v);
                    if(fu!=fv)
                    {
                        now++;
                        s+=e2[j].w;
                        fa[fu]=fv;
                    }
                }
                j++;
            }
        }
        ans=min(ans,s);
    }
    printf("%lld\n",ans);
}