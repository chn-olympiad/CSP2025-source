#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long dis[10005][10005];
long long c[15],a[15][10005];
struct node
{
	int u,v,c;
};
vector<node>t;
bool cmp(node x,node y)
{
	return x.c<y.c;
}
int f[10005];
int find(int i)
{
	if(f[i]==i) return i;
	f[i]=find(f[i]);
	return f[i];
}
void make(int x,int y)
{
	int l=find(x);
	int r=find(y);
	if(l!=r) f[l]=r;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		t.push_back({u,v,c});
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{         
			for(int u=1;u<=k;u++)
			{
				 dis[i][j]=min(dis[i][j],a[u][i]+a[u][j]+c[u]);
			}
			t.push_back({i,j,dis[i][j]});
		}
	} 
	sort(t.begin(),t.end(),cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	long long ans=0;
	for(int i=1;i<=t.size();i++)
	{
		if(find(t[i].u)!=find(t[i].v))
		{
			make(t[i].u,t[i].v);
			ans+=t[i].c;
		}
	}
	cout<<ans;
}