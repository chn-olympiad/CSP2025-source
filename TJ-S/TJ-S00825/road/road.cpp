//嗯...感觉这个东西比较奇怪。。。
//预期得分80~100pts
//CCF少爷机应该能1秒1e9吧...
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
	int u,v,dis;
	bool operator <(node other)
	{
		return dis<other.dis;
	}
};
node e[1000005],t[1000005];
int cur;
int a[15][10005],c[15];
int f[10005];
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
long long ans=1e16;
void slove(int status)
{
	cur=0;//清空 
	long long cost=0;//long long
	int k_=0;
	for(int i=1;i<=k;i++)
		if(status&(1<<(i-1)))
		{
			cost+=c[i];
			k_++;
			for(int j=1;j<=n;j++)
				t[++cur]=node{n+i,j,a[i][j]};
		}
	sort(t+1,t+cur+1);
	for(int i=1;i<=n+k;i++)
		f[i]=i;
	int c1=1,cnt=0;
	for(int i=1;i<=m;i++)
	{
		while(c1<=cur&&t[c1].dis<=e[i].dis)
		{
			if(find(t[c1].u)!=find(t[c1].v))
			{
				f[find(t[c1].v)]=t[c1].u;
				cost+=t[c1].dis;
				cnt++;
				if(cnt==n+k_-1)
					break;
			}
			c1++;
		}
		if(find(e[i].u)!=find(e[i].v))
		{
			f[find(e[i].v)]=e[i].u;
			cost+=e[i].dis;
			cnt++;
		}
		if(cnt==n+k_-1)
			break;
	}
	ans=min(ans,cost);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].dis);
	sort(e+1,e+m+1);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	for(int i=0;i<(1<<k);i++)
		slove(i);
	printf("%lld",ans);
	return 0; 
}
