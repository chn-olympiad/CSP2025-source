#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+11,maxm=1.2e6+1,maxk=11;
struct road
{
	int u,v,w;
}r[maxm];
bool cmp(road x,road y)
{
	return x.w<y.w;
}
int f[maxn];
int find(int x)
{
	if(x==f[x])
	{
		return x;	
	} 
	else
	{
		return f[x]=find(f[x]);
	}
}
void add(int x,int y)
{
	f[find(x)]=find(y);
}
int n,m,k;
void init()
{
	for(int i=1;i<=n+k;i++)
	{
		f[i]=i;
	}
}
int a[maxk][maxn];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++)
	{
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	int cnt=m;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>a[i][j];
		}
		if(a[i][0]==0)
		{
			for(int j=1;j<=n;j++)
			{
				cnt++;
				r[cnt].u=n+i;
				r[cnt].v=j;
				r[cnt].w=a[i][j];
			}
		}
	}
	sort(r+1,r+cnt+1,cmp);
	int ans=0;
	for(int i=1;i<=cnt;i++)
	{
		int u=r[i].u,v=r[i].v,w=r[i].w;
		if(find(u)!=find(v))
		{
			add(u,v);
			ans+=w;
		}
	}
	cout<<ans<<"\n";
	return 0;
}


