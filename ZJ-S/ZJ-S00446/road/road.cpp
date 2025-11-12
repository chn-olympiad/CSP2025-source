#include<bits/stdc++.h>
using namespace std;
const int N=1e4+50;
const int M=2e6+10;
struct Edge
{
	int u,v,w;
	bool vis;
};
Edge a[M];
int val[N];
int f[N];
bool use[N];
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	f[fx]=fy;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].vis=false;
	}
	bool allvalz=true;
	for(int i=n+1;i<=n+k;i++)
	{
		cin>>val[i];
		if(val[i]>0) allvalz=false;
		for(int j=1;j<=n;j++)
		{
			//m+(i-n-1)*n+1 ~ m+(i-n)*n
			int w;
			cin>>w;
			int edgecount=m+(i-n-1)*n+j;
			a[edgecount].u=i,a[edgecount].v=j,a[edgecount].w=w+val[i];
		}
	}
	sort(a+1,a+m+k*n+1,cmp);
	if(k==0)
	{
		for(int i=1;i<=n+k;i++) f[i]=i;
		long long ans=0;
		int cnt=0;
		for(int i=1;i<=m+k*n;i++)
		{
			if(cnt==n-1) break;
			int u=a[i].u,v=a[i].v,w=a[i].w;
			if(find(u)!=find(v))
			{
				cnt++;
				ans+=1ll*w;
				merge(u,v);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(allvalz)
	{
		long long ans=1e18;
		for(int town=0;town<=k;town++)
		{
			memset(use,false,sizeof(use));
			for(int i=1;i<=n+k;i++) f[i]=i;
			int towncnt=0,cnt=0;
			long long sum=0;
			for(int i=1;i<=m+k*n;i++)
			{
				if(cnt==n+town-1) break;
				int u=a[i].u,v=a[i].v,w=a[i].w;
				if(u>n)//town
				{
					if(!use[u])
					{
						if(towncnt>=town) continue;
						use[u]=true;
						towncnt++;
					}	
				}
				if(find(u)!=find(v))
				{
					cnt++;
					sum+=1ll*w;
					merge(u,v);
				}
			}
			ans=min(ans,sum);
		}
		cout<<ans<<endl;
		return 0;
	}
	else
	{
		long long ans=1e18;
		for(int town=0;town<=k;town++)
		{
			memset(use,false,sizeof(use));
			for(int i=1;i<=n+k;i++) f[i]=i;
			int towncnt=0,cnt=0,last=1;
			long long sum=0;
			for(int i=last;i<=m+k*n;i++)
			{
				if(!a[i].vis)
				{
					a[i].vis=true;
					if(cnt==n+town-1) break;
					int u=a[i].u,v=a[i].v,w=a[i].w;
					if(u>n)//town
					{
						if(!use[u])
						{
							if(towncnt>=town) continue;
							use[u]=true;
							towncnt++;
							for(int ed=i+1;ed<=m+k*n;ed++)
							{
								if(a[ed].u==u) a[ed].w-=val[u];
							}
							sort(a+1,a+m+k*n+1,cmp);
							last=1;
						}	
					}
					if(find(u)!=find(v))
					{
						cnt++;
						sum+=1ll*w;
						merge(u,v);
					}
				}
			}
			ans=min(ans,sum);
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
