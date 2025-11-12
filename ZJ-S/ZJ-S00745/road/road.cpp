#include<bits/stdc++.h>
#define int long long
#define debug cout<<"***"<<endl;
using namespace std;
struct node{
	int u,v,w;
}f[2000011];
struct node1
{
	int u,v,w;
}a[1000011];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
bool cmp1(node1 a,node1 b)
{
	return a.w<b.w;
}
int k,n,m,c[15],b[15][1000011];
int minn=LONG_LONG_MAX;
bool use[11];
int fa[2000011];
int find(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>b[i][j];
	}
	if(k==0)
	{
		int ans=0,cnt=0;
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			int uu=find(a[i].u),vv=find(a[i].v);
			//cout<<uu<<" "<<vv<<endl;
			if(uu!=vv)
			{
				ans+=a[i].w;
				cout<<a[i].u<<" "<<a[i].v<<endl;
				fa[vv]=uu;
				cnt++;
			}
			//cout<<find(6)<<endl;
			if(cnt==n-1)
			{
				cout<<ans;
				//return 0;
			}
		}
		//for(int i=1;i<=n;i++)cout<<fa[i]<<" ";
		//cout<<fa[6]<<endl;
		//cout<<endl;
		//cout<find(5);
		return 0;
	}
	for(int j=0;j<(1<<k);j++)
	{
		int cnt=0;
		int t=j;
		int id=0;
		int nim=n;
		int sum=m;
		int ans=0;
		for(int i=1;i<=k;i++)use[i]=0;
		for(int i=1;i<=n;i++)
		f[i].u=a[i].u,f[i].v=a[i].v,f[i].w=a[i].w;
		while(t)
		{
			id++;
			if(t%2)
			{
				use[id]=1;
			}
			t=t/2;
		}
		for(int i=1;i<=k;i++)
		{
			if(use[i])
			{
				nim++;
				ans+=c[i];
				for(int l=1;l<=n;l++)
				{
					f[++sum].u=nim;
					f[sum].v=l;
					f[sum].w=b[i][l];
				}
			}
		}
		for(int i=1;i<=nim;i++)fa[i]=i;
		sort(f+1,f+sum+1,cmp);
		for(int i=1;i<=sum;i++)
		{
			int uu=find(f[i].u),vv=find(f[i].v);
			if(uu!=vv)
			{
				fa[vv]=uu;
				ans+=f[i].w;
				cnt++;
			}
			if(cnt==nim-1)
			{
				minn=min(minn,ans);
				break;
			}
		}
	}
	cout<<minn;
	return 0;
}
//dark_knight_ak_all
//×·Ñ°ÃÎµÄÂûÑÓ 
