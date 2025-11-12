#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,fa[11000],c[15];
long long ans;
struct node{
	int u,v,w;
}a[1200000];
vector<int>b[11000];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merger(int x,int y)
{
	int tx=find(x),ty=find(y);
	fa[tx]=ty;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
void kruskal()
{
	ans=cnt=0;
	sort(a+1,a+m+1,cmp);
	for(int i=0;i<=n+k;i++)
	  fa[i]=i;
	bool fk[15];
	memset(fk,0,sizeof(fk));
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].u)!=find(a[i].v))
		{
			ans+=a[i].w;
			if(a[i].u>n&&!fk[a[i].u-n])
			{
				ans+=c[a[i].u-n];
				fk[a[i].u-n]=1;
			}
			merger(a[i].u,a[i].v);
			if(a[i].u<=n)cnt++;
			if(a[i].u>n)b[a[i].u].push_back(a[i].w);
			if(cnt==n-1)break;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	kruskal();
	long long ansx=ans;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]>=ans)
		{
			for(int j=1;j<=n;j++)
			{
				int x;
				cin>>x;
			}
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			a[++m].u=n+i,a[m].v=j;
			scanf("%d",&a[m].w);
		}
	}
	kruskal();
	for(int i=1;i<=k;i++)
	{
		if(b[i].size()==1)ans-=(b[i][0]+c[i-n]);
	}
	ans=min(ans,ansx);
	printf("%lld",ans);
	return 0;
}
