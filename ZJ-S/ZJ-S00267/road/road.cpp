#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+1;
int num,fa[maxn];
long long n,n1,m,k,ans,mp[maxn][maxn],c[maxn],a[maxn][maxn];
bool flag[maxn];
struct edge{
	int from,to;
	long long w;
}e[maxn*maxn];
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
void unionn(int x,int y)
{
	fa[x]=find(x);
	fa[y]=find(y);
	fa[y]=fa[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	n1=n;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) mp[i][j]=1e9+1,mp[j][i]=1e9+1;
	}
	for(int i=0;i<m;i++)
	{
		int u,v;
		long long w;
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=w;
		e[num].from=u;
		e[num].to=v;
		e[num].w=w;
		num++;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]==0) flag[i]=1,n1++,fa[n1]=n1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(flag[i])
			{
				e[num].from=n1;
				e[num].to=j;
				e[num].w=a[i][j];
				num++;
			}
		}
	}
	if(n1>n)
	{
		sort(e,e+num,cmp);
		num=1;
		while(num<n1)
		{
			int x=e[num-1].from,y=e[num-1].to;
			if(find(x)!=find(y))
			{
				ans+=e[num-1].w;
				unionn(x,y);
				num++;
			}
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			n1++;
			for(int j=1;j<=n;j++)
			{
				e[num].from=n1;
				e[num].to=j;
				e[num].w=a[i][j];
				num++;
			}
		}
		sort(e,e+num,cmp);
		num=1;
		while(num<n1)
		{
			int x=e[num-1].from,y=e[num-1].to;
			if(find(x)!=find(y))
			{
				ans+=e[num-1].w;
				unionn(x,y);
				num++;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
