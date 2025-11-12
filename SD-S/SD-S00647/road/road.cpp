#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
struct node
{
	long long u,v,w;
};
long long n,m,k,ans,mm;
long long g[100050];
node num[1000006];
node nums[100004];
node numss[2000005];
node qtx[15][100005];
long long jian[15];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int Find(int x)
{
	if(x==g[x])
	{
		return x;
	}
	return g[x]=Find(g[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
	{
		g[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		long long a,b,c;
		cin>>a>>b>>c;
		num[i]={a,b,c};
	}
	for(int i=1;i<=k;i++)
	{
		cin>>jian[i];
		for(int j=1;j<=n;j++)
		{
			int a;
			cin>>a;
			qtx[i][j]={n+i,j,a};
		}
	}
	sort(num+1,num+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int tou1=Find(num[i].u);
		int tou2=Find(num[i].v);
		if(tou1!=tou2)
		{
			g[tou1]=g[tou2];
			ans+=num[i].w;
			mm++;
			nums[mm].u=num[i].u;
			nums[mm].v=num[i].v;
			nums[mm].w=num[i].w;
		}
	}
	int ci=pow(2,k)-1;
	while(ci)
	{
		for(int i=1;i<=n+k;i++)
		{
			g[i]=i;
		}
		int mmm=mm;
		long long zl=ci,ans1=0,we=1;
		while(zl)
		{
			if(zl%2==1)
			{
				ans1+=jian[we];
				for(int i=1;i<=n;i++)
				{
					mmm++;
					numss[mmm].u=qtx[we][i].u;
					numss[mmm].v=qtx[we][i].v;
					numss[mmm].w=qtx[we][i].w;
				}
			}
			we++;
			zl/=2;
		}
		for(int i=1;i<=mm;i++)
		{
			numss[i].u=nums[i].u;
			numss[i].v=nums[i].v;
			numss[i].w=nums[i].w;
		}
		sort(numss+1,numss+mmm+1,cmp);
		for(int i=1;i<=mmm;i++)
		{
			int tou1=Find(numss[i].u);
			int tou2=Find(numss[i].v);
			if(tou1!=tou2)
			{
				g[tou1]=g[tou2];
				ans1+=numss[i].w;
			}
		}
		ans=min(ans,ans1);
		for(int i=1;i<=mmm;i++)
		{
			numss[i].u=0;
			numss[i].v=0;
			numss[i].w=0;
		}
		ci--;
	}
	cout<<ans<<endl;
	return 0;
}
/*


*/

