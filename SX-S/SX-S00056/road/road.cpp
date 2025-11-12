#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cnt,fa[200005],is[200005],xz[105],ans=0;
struct edge{
	long long u,v,w,z;
}ed[2000005];
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
bool cmp2(edge a,edge b)
{
	long long aw=a.w,bw=b.w;
	if(is[a.z]==1)
	{
		aw-=xz[a.z];
	}
	if(is[b.z]==1)
	{
		bw-=xz[b.z];
	}
	return aw<bw;
}
long long find(long long x)
{
	if(fa[x]!=x)
	{
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		cin>>ed[i].u>>ed[i].v>>ed[i].w;
		ed[i].z=0;
	}
	for(long long i=1;i<=n+50;i++)
	{
		fa[i]=i;
	}
	cnt=m;
	long long cntx=0,cnty=n,ansx=0;
	for(long long i=1;i<=k;i++)
	{
		cin>>xz[i];
		for(long long j=1;j<=n;j++)
		{
			long long y;
			cin>>y;
			cnt++;
			ed[cnt].u=n+i;
			ed[cnt].v=j;
			ed[cnt].w=xz[i]+y;
			ed[cnt].z=i;
		}
	}
	sort(ed+1,ed+1+cnt,cmp);
//	long long cntx=0,cnty=n;
	for(long long i=1;i<=cnt;i++)
	{
		long long nx=find(ed[i].u),ny=find(ed[i].v);
		if(nx!=ny)
		{
			fa[nx]=ny;
			cntx++;
			ans+=ed[i].w;
			if(!is[ed[i].z]&&ed[i].z!=0)
			{
				is[ed[i].z]=1;
				cnty++;
			}
			else
			{
				ans-=xz[ed[i].z];
			}
			if(cntx==cnty-1)
			{
				break;
			}
		}
	}
	cout<<ans;
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

3 3 1
1 2 1
2 3 100
1 3 100
10 2 2 2

*/
