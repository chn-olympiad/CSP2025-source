#include <bits/stdc++.h>
using namespace std;
long long n,m,k,len=0,fff=0;
long long res[2000010];
long long num[111],cnt[20][10010],b[2000010];
long long h[101],f[2000010],sum=0;
long long ans=0;
struct edge
	{
		long long u,v,w,val;
	}g[2000010];
bool cmp(edge x,edge y)
	{
		return x.w<y.w;
	}
long long find(long long x)
	{
		if(f[x]!=x) f[x]=find(f[x]);
		return f[x];
	}
void merge(long long x,long long y)
	{
		long long a=find(x),b=find(y);
		if(a!=b) f[a]=b;
		return ;
	}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n+k+1;i++) f[i]=i;
	for(long long i=1,u,v,w;i<=m;i++)
		{
			len++;
			scanf("%lld%lld%lld",&u,&v,&w);
			g[len].u=u,g[len].v=v,g[len].w=w;
			g[len].val=0;
		}
	for(long long i=1;i<=k;i++)
		{
			scanf("%d",&num[i]);
			if(num[i]!=0) fff=1;
			for(long long j=1;j<=n;j++)
				{
					scanf("%lld",&cnt[i][j]);
					len++;
					g[len].u=n+i,g[len].v=j,g[len].w=cnt[i][j]+num[i];
					g[len].val=i;
				}
		}
	if(fff==0)
		{
			sort(g+1,g+1+len,cmp);
			for(long long i=1,u,v,w,kk;i<=len;i++)
				{
					u=g[i].u,v=g[i].v,w=g[i].w,kk=g[i].val;
					if(sum==n) break;
					if(find(u)!=find(v))
						{
							if(u<=n&&b[u]==0) sum++,b[u]++;
							if(v<=n&&b[v]==0) sum++,b[v]++;
							if(u>n) b[u]++,res[u]=w;
							if(v>n) b[v]++,res[v]=w;
							merge(u,v);
							ans+=w;
						}
				}
			for(int i=n+1;i<=n+k;i++)
				if(b[i]==1)
					{
						ans-=res[i];
						ans-=num[i];
					}
			printf("%lld\n",ans);
			return 0;
		}
	sort(g+1,g+1+len,cmp);
	for(long long i=1,u,v,w,kk;i<=len;i++)
		{
			u=g[i].u,v=g[i].v,w=g[i].w,kk=g[i].val;
			if(sum==n) break;
			if(find(u)!=find(v))
				{
					if(u<=n&&b[u]==0) sum++,b[u]++;
					if(v<=n&&b[v]==0) sum++,b[v]++;
					if(u>n) b[u]++,res[u]=w;
					if(v>n) b[v]++,res[v]=w;
					merge(u,v);
					ans+=w;
					if(kk!=0&&h[kk]==0)
						{
							for(int j=1;j<=n;j++)
								{
									len++;
									g[len].u=kk+n;
									g[len].v=j;
									g[len].w=cnt[kk][j];
									g[len].val=0;
								}
							sort(g+i+1,g+len,cmp);
						}
				}
		}
	for(int i=n+1;i<=n+k;i++)
		if(b[i]==1)
			{
				ans-=res[i];
				ans-=num[i];
			}
	printf("%lld\n",ans);
	return 0;
}