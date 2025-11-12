#include<bits/stdc++.h>
using namespace std;
struct V
{
	int u,v,w;
}yb[1000005],a[1100005];
int n,m,k;
int c[11],kb[11][10005];
int f[10015];
int find(int x)
{
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
bool cmp(V x,V y)
{
	return x.w<y.w;
}
long long kru(int S)
{
	int num=m,tn=n;
	long long sum=0,cnt=0;
	for(int i=1;i<=m;i++)
	{
		a[i]=yb[i];
	}
	for(int i=0;i<k;i++)
	{
		if((S>>i)&1)
		{
			sum+=c[i+1];
			tn++;
			for(int j=1;j<=n;j++)
			{
				a[++num]={tn,j,kb[i+1][j]};
			}
		}
	}
	for(int i=1;i<=tn;i++)f[i]=i;
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++)
	{
		int x=a[i].u,y=a[i].v;
		if(cnt==tn-1)break;
		if(find(x)==find(y))continue;
		cnt++;
		f[find(y)]=find(x);
		sum+=a[i].w;
	}
	return sum;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&yb[i].u,&yb[i].v,&yb[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&kb[i][j]);
		}
	}
	long long ans=1e18;
	int S=(1<<k)-1;
	for(int i=1;i<=S;i++)
	{
		ans=min(kru(i),ans);
	}
	printf("%d",ans);
	return 0;
}