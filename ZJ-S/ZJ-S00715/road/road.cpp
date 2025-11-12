#include <bits/stdc++.h>
using namespace std;
int n,m,t;
long long ans,cw[10010];
struct node{
	int a,b;
	long long c;	
}edge[2000010];
int bs=0,fa[200010];
int find(int x){
	return ((fa[x]==x)?(x):(fa[x]=find(fa[x])));
}
bool cmp(node xx,node yy){
	return xx.c<yy.c;
}
int  main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		long long w;
		++bs;
		cin>>edge[bs].a>>edge[bs].b>>edge[bs].c;
	}
	for(int i=0;i<200010;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=t;i++)
	{
		cin>>cw[i];
		for(int j=1;j<=n;j++)
		{
			long long w;
			++bs;
			cin>>edge[bs].c;
			edge[bs].a=0;edge[bs].b=j;
		}
	}
	sort(edge+1,edge+1+n,cmp);
	int sum0=0,sum1=0;
	long long ans=0,l=0;
	for(int i=1;i<=bs;i++)
	{
		if(sum1>=n)break;
		int x=edge[i].a;
		int y=edge[i].b;
		int fx=find(x);
		int fy=find(y);
		if(fx==fy)continue;
		else
		{
			fa[fx]=fa[fy];
			ans+=edge[i].c;
			if(x==0||y==0)
			{
				sum0++;
				l+=edge[i].c;
			}
			sum1++;
		}
	}
	if(sum0)
	{
		ans-=l;
	}
	cout<<ans;
}

