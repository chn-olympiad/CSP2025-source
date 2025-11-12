#include<bits/stdc++.h>
#define int long long
#define inf 2000000000000000
using namespace std;
const int M=1e6+5;
const int N=1e4+5;
struct node
{
	int u,v,w;
	bool operator<(const node &b)const
	{
		return w<b.w;
	}
}e[M];
int c[12],a[12][N];
int f[N+20];
int find(int u)
{
	if(f[u]==u)return u;
	return f[u]=find(f[u]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[i]={u,v,w};
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	int ans=inf;
	for(int s=0;s<1<<k;s++)
	{
		priority_queue<node>q;
		int tot=0,cntc=n;
		for(int i=1;i<=k;i++)
			if((s>>i-1)&1)
			{
				cntc++;
				tot+=c[i];
				for(int j=1;j<=n;j++)
					q.push({n+i,j,-a[i][j]});
			}
		
		for(int i=1;i<=n+k;i++)f[i]=i;
		int i=1,cnt=1;
		while(cnt<cntc)
		{
			node t;
			if(i>m)
				t=q.top(),q.pop(),t.w=-t.w;
			else
				if(q.empty())
					t=e[i],i++;
				else
				{
					t=e[i];
					if(-q.top().w<t.w)
						t=q.top(),q.pop(),t.w=-t.w;
					else 
						i++;
				}
			int u=t.u,v=t.v,w=t.w;
			u=find(u),v=find(v);
			if(u!=v)
			{
				cnt++;
				tot+=w;
				f[u]=v;
			}
			if(tot>ans)break;
		}
//		printf("%lld %lld\n",s,tot);
		ans=min(ans,tot);
	}
	printf("%lld",ans);
	return 0;
}