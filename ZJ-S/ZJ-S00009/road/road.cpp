#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node{
    int u,v,w;
}e[N],s[11][10010];
bool cmp(node x,node y){return x.w<y.w;}
int n,m,k,tot,a[11],hd[11],f[N],xz[11];
long long ans;
int find(int x)
{
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1,x,y;i<=m&&tot<n-1;i++)
    {
        x=find(e[i].u),y=find(e[i].v);
        if(x==y)continue;
        f[x]=y;
        e[++tot]=e[i];
    }
    for(int i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
        for(int j=1;j<=n;j++)scanf("%d",&s[i][j].w),s[i][j].u=n+i+1,s[i][j].v=j;
        sort(s[i]+1,s[i]+1+n,cmp);
    }
    ans=1e18;
    for(int i=0,h,cnt,ec,minn,x,y;i<(1<<k);i++)
    {
        h=1,cnt=0,ec=0;
        long long sum=0;
        for(int j=0;j<k;j++)if((i>>j)&1)xz[++cnt]=j,sum+=a[j];
        for(int j=1;j<=cnt;j++)hd[j]=1;
        for(int j=1;j<=n+k;j++)f[j]=j;
        while(1)
        {
            if(ec>=n+cnt-1)break;
            minn=1e9;
            if(h<n)minn=min(minn,e[h].w);
            for(int j=1;j<=cnt;j++)if(hd[j]<=n)minn=min(minn,s[xz[j]][hd[j]].w);
            if(h<n&&e[h].w==minn)
            {
                x=find(e[h].u),y=find(e[h].v);
                if(x!=y)
                {
                    ec++;
                    f[x]=y;
                    sum+=minn;
                }
                h++;
                continue;
            }
            for(int j=1;j<=cnt;j++)
            {
                if(hd[j]<=n)
                {
                    if(s[xz[j]][hd[j]].w==minn)
                    {
                        x=find(s[xz[j]][hd[j]].u),y=find(s[xz[j]][hd[j]].v);
                        if(x!=y)
                        {
                            ec++;
                            f[x]=y;
                            sum+=minn;
                        }
                        hd[j]++;
                        break;
                    }
                }
            }
        }
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}