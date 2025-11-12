#include <bits/stdc++.h>
#define int long long
using namespace std;
struct xxx{int u,v,w;}E[1000005],e[2000005];
int n,m,k,f[10015],a[15][10005],l,s,ans;
bool cmp(xxx x,xxx y){return x.w<y.w;}
bool cmpp(xxx x,xxx y){return x.u<y.u;}
int find(int u){if(f[u]==u)return u;return f[u]=find(f[u]);}
int kruskal(int n,int m)
{
	int sum=0;
	for(int i=1;i<=n;i++)f[i]=i;sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv)continue;f[fu]=fv;sum+=e[i].w;
	}
	sort(e+1,e+m+1,cmpp);return sum;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;l=m;
	for(int i=1;i<=m;i++)cin>>E[i].u>>E[i].v>>E[i].w;
	for(int i=1;i<=m;i++)e[i]=E[i];ans=kruskal(n,m);
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)cin>>a[i][j];
	}
	for(int i=0;i<(1<<k);i++)
	{
		for(int j=1;j<=m;j++)e[j]=E[j];l=m;int x=0;
		for(int j=1;j<=10;j++)if((i>>j-1)&1)
		{
			x+=a[j][0];
			for(int k=1;k<=n;k++)e[++l]={n+j,k,a[j][k]};
		}
		x+=kruskal(n+10,l);ans=min(ans,x);
	}
	cout<<ans;
	return 0;
}
//32pts TLE
/*
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct xxx{int u,v,w;}E[1000005],e[2000005];
int n,m,k,f[10015],a[15][10005],l,s,ans;
bool cmp(xxx x,xxx y){return x.w<y.w;}
bool cmpp(xxx x,xxx y){return x.u<y.u;}
int find(int u){if(f[u]==u)return u;return f[u]=find(f[u]);}
int kruskal(int n,int m)
{
	int sum=0;
	for(int i=1;i<=n;i++)f[i]=i;sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv)continue;f[fu]=fv;sum+=e[i].w;
	}
	sort(e+1,e+m+1,cmpp);return sum;
}
signed main()
{
	freopen("road4.in","r",stdin);
	freopen("xxx.txt","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;l=m;
	for(int i=1;i<=m;i++)cin>>E[i].u>>E[i].v>>E[i].w;
	for(int i=1;i<=m;i++)e[i]=E[i];ans=kruskal(n,m);
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)cin>>a[i][j];
	}
	for(int i=0;i<(1<<k);i++)
	{
		for(int j=1;j<=m;j++)e[j]=E[j];l=m;int x=0;
		for(int j=1;j<=10;j++)if((i>>j-1)&1)
		{
			x+=a[j][0];//if(i==5)cout<<j<<" ";
			for(int k=1;k<=n;k++)e[++l]={n+j,k,a[j][k]};
		}
		x+=kruskal(n+10,l);
		cout<<i<<" "<<x<<"\n";
		ans=min(ans,x);//5
	}
	cout<<ans;
	return 0;
}

*/
