#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2e6+5;
long long n,m,k,step,ans=1e18;
int val[N],a[15][N],fa[N];
bool vis[N];
bool flag=1,flag2;
struct edge
{
	int x,y,w;
}e[M],E[M];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]!=x) return find(fa[x]);
	return x;
}
int read()
{
	int ans=0;
	char ch;
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
long long work(int n,int m)
{
	long long ans=0;
	for(int i=1;i<=n;++i) fa[i]=i;
	sort(e+1,e+1+m,cmp);
	int cnt=0;
	for(int i=1;i<=m;++i)
	{
		if(cnt==n-1) return ans;
		int x=find(e[i].x);
		int y=find(e[i].y);
		step+=m/100;
		if(x!=y)
		{
			cnt++;
			fa[x]=y;
			ans+=e[i].w;
		}
	}
	return ans;
}
void dfs(int x)
{
	if(flag2) return;
	if(x==k+1)
	{
		int p=m,idx=n;
		for(int i=1;i<=m;++i) E[i]=e[i];
		long long sum=0;
		for(int i=1;i<=k;++i)
		if(vis[i])
		{
			sum+=val[i];
			idx++;
			for(int j=1;j<=n;++j) e[++p]=edge{idx,j,a[i][j]};
		}
		ans=min(ans,work(idx,p)+sum);
		for(int i=1;i<=m;++i) e[i]=E[i];
		if(step>=70000000) flag2=1;
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	getchar();
	if(m<=100000)
	{
		for(int i=1;i<=m;++i) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	}
	else
	{
		for(int i=1;i<=m;++i) e[i].x=read(),e[i].y=read(),e[i].w=read();
	}
	for(int i=1;i<=k;++i)
	{
		scanf("%d",&val[i]);
		bool flag1=0;
		if(val[i]) flag=0;
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&a[i][j]);
			if(!a[i][j]) flag1=1;
		}
		if(!flag1) flag=0;
	}
	if(flag)
	{
		for(int i=1;i<=k;++i)
		for(int j=1;j<=n;++j) e[++m]=edge{n+i,j,a[i][j]};
		n+=k;
		cout<<work(n,m);
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
