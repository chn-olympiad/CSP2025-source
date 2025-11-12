#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
struct uvw
{
	int u,v,w;
}now;
bool cmp(uvw a,uvw b) 
{
	return a.w<b.w;
}
int f[10004];
int szf[10004];
int gf(int a)
{
	if(f[a]!=a)
		return f[a]=gf(f[a]);
	return a;
}
uvw a[1000006];/* */
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	/**/
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		szf[i]=1;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&now.u,&now.v,&now.w);
		a[i]=now;
	}/* 
	vector<uvw>x[10];
	int xi;
	for(int i=0;i<k;i++)
	{
		cin>>xi;
		for(int i=0;i<xi;i++)
		{
			scanf("%d %d %d",&now.u,&now.v,&now.w);
			x[i].push_back(now);
		}
	}*/ 
	sort(a,a+m,cmp);
	long long ans=0;
	for(int i=0;i<m;i++)
	{
		if(gf(a[i].u)!=gf(a[i].v))
		{
			ans+=a[i].v;
			f[a[i].u]=f[a[i].v];
			if(szf[a[i].u]>szf[a[i].v])
			{
				szf[a[i].v]+=szf[a[i].u];
			}
			else
			{
				szf[a[i].u]+=szf[a[i].v];
			}
		}
	}
	cout<<ans;
	return 0; 
}
