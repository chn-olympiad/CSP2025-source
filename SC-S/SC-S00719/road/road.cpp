#include<bits/stdc++.h>
#define ll long long
using namespace std;
int fa[100001],tot,totbf,n,m,k,dis[11][100001],c[11];
struct road{int x,y,z;}a[2000001],bf[2000001];
int f(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=f(fa[x]);
}
bool cmp(road x,road y)
{
	return x.z<y.z;
}
ll kru(int p)
{
	ll ans=0;
	int cnt=0;
	for(int j=1;j<=p;j++) fa[j]=j;
	sort(a+1,a+tot+1,cmp);
	for(int j=1;j<=tot;j++)
	{
		int f1=f(a[j].x),f2=f(a[j].y);
		if(f1!=f2)
		{
			fa[f1]=f2;
			ans+=a[j].z;
			cnt++;
			if(cnt==p-1) break;
		}
	}
	return ans;
}
int solve()
{
	ll minn=1e18;
	for(int i=0;i<(1<<k);i++)
	{
		int ct=0;ll ans=0;tot=totbf;
		for(int j=1;j<=totbf;j++)
		{
			a[j].x=bf[j].x;a[j].y=bf[j].y;a[j].z=bf[j].z;
		}
		for(int j=1;j<=k;j++)
		{
			if((i>>(k-j))&1)
			{
				ct++;ans+=c[j];
				for(int p=1;p<=n;p++)
					a[++tot].x=n+ct,a[tot].y=p,a[tot].z=dis[j][p];
			}
		}
		ans+=kru(n+ct);
		minn=min(minn,ans);
	}
	return minn;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		bf[++totbf].x=x,bf[totbf].y=y,bf[totbf].z=z;
	}
	if(k==0)
	{
		tot=totbf;
		for(int j=1;j<=totbf;j++)
		{
			a[j].x=bf[j].x;a[j].y=bf[j].y;a[j].z=bf[j].z;
		}
		cout<<kru(n);
		return 0;
	}
	bool flag=0;
	for(int i=1;i<=k;i++)
	{
		bool tmp=1;
		cin>>c[i];
		if(c[i]>0) tmp=0;
		for(int j=1;j<=n;j++)
		{
			cin>>dis[i][j];
			if(dis[i][j]>0) tmp=0;
		}
		flag|=tmp;
	}
	if(flag) cout<<0;
	else cout<<solve();
	return 0;
}