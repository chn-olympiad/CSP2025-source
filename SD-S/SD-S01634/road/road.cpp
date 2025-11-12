#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[15][10010];
int c[10010];
int fa[11020];
struct Road
{
	int u;
	int v;
	long long w;
};
Road rds[1100010];
bool cmp(Road a,Road b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void solve1()
{
	sort(rds,rds+m,cmp);
	for (int i=1;i<=n;++i)
		fa[i]=i;
	int sum=1;
	long long res=0;
	for (int i=0;i<m;++i)
	{
		if(find(rds[i].u)!=find(rds[i].v))
		{
			fa[find(rds[i].u)]=find(rds[i].v);
			++sum;
			res+=rds[i].w;
		}
		if(sum==n) break;
	}
	cout<<res;
}
void solve2()
{
	for (int i=1;i<=k;++i)
		for (int j=1;j<=n;++j)
		{
			rds[m+(i-1)*n+j-1].u=i+n;
			rds[m+(i-1)*n+j-1].v=j;
			rds[m+(i-1)*n+j-1].w=a[i][j];
		}
	m+=k*n;
	n+=k;
	sort(rds,rds+m,cmp);
	for (int i=1;i<=n;++i)
		fa[i]=i;
	int sum=1;
	long long res=0;
	for (int i=0;i<m;++i)
	{
		if(find(rds[i].u)!=find(rds[i].v))
		{
			fa[find(rds[i].u)]=find(rds[i].v);
			++sum;
			res+=rds[i].w;
		}
		if(sum==n) break;
	}
	cout<<res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool tx=1,tmp;
	cin>>n>>m>>k;
	for (int i=0;i<m;++i)
		cin>>rds[i].u>>rds[i].v>>rds[i].w;
	for (int i=1;i<=k;++i)
	{
		cin>>c[i];
		tmp=0;
		for (int j=1;j<=n;++j)
		{
			cin>>a[i][j];
			if(!a[i][j]) tmp=1; 
		}
		if((!tmp)||(c[i]!=0)) tx=0;
	}
	if(k==0) solve1();
	else if(tx) solve2();
	return 0;
}
