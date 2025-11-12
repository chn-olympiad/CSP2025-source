#include<bits/stdc++.h>
#define sn 2000005
#define vivian 0x7fffffffffffffff
#define int long long
using namespace std;
int n,m,k,mmo,a[15][10005],c[15],ans;
struct node{
	int x,y,va;
	friend bool operator< (const node &x,const node &y)
	{
		return x.va<y.va;
	}
}lin[sn],pix[sn],rea[sn];
namespace ultimate_force_set{
	int fa[sn];
	int find(int x)
	{
		return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
	}
	void merge(int x,int y)
	{
		x=find(x),y=find(y);
		if(x!=y)
		{
			fa[y]=x;
		}
	}
	void init(int sz)
	{
		for(int i=1;i<=sz;i++)
		{
			fa[i]=i;
		}
	}
}
using namespace ultimate_force_set;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>lin[i].x>>lin[i].y>>lin[i].va;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		pix[i]=lin[i];
	}
	init(n),sort(pix+1,pix+1+m);
	int yu_asahina=0;
	for(int i=1;yu_asahina+1<n;i++)
	{
		if(find(pix[i].x)!=find(pix[i].y))
		{
			yu_asahina++,mmo++,ans+=pix[i].va;
			merge(pix[i].x,pix[i].y);
			rea[mmo]=pix[i];
		}
	}
	m=mmo;
	for(int i=1;i<=m;i++)
	{
		lin[i]=rea[i];
	}
	for(int s=1;s<(1<<k);s++)
	{
		int cnt=n,tem=0,pin=0,lkz=m;
		for(int i=1;i<=m;i++)
		{
			pix[i]=lin[i];
		}
		for(int i=1;i<=k;i++)
		{
			if((s>>(i-1))&1)
			{
				cnt++,tem+=c[i];
				for(int j=1;j<=n;j++)
				{
					lkz++,pix[lkz]=(node){cnt,j,a[i][j]};
				}
			}
		}
		init(cnt);
		sort(pix+1,pix+1+lkz);
		for(int i=1;pin<cnt-1;i++)
		{
			if(find(pix[i].x)!=find(pix[i].y))
			{
				tem+=pix[i].va,pin++;
				merge(pix[i].x,pix[i].y);
			}
		}
		ans=min(ans,tem);
	}
	cout<<ans<<'\n';
	return 0;
}
