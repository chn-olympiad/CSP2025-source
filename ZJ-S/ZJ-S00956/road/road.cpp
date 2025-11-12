#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int M=1e8+10;
struct bian
{
	int u,v;
	bool operator <(const bian &x) const
	{
		return x.u>u;
	}
};
map<bian,int> mp;
struct node
{
	int x,y,w;
}q[M];
int pre[N];
int cha(int x)
{
	if(pre[x]!=x) return pre[x]=cha(pre[x]);
	return pre[x];
}
int a[15][N];
struct data
{
	int val,tt;
	//int vis[M]={0};
}d[15];
int cmp(node o,node p)
{
	return o.w<p.w;
}
/*
int cmp1(data o,data p)
{
	return o.tt-o.val>p.tt-p.val;
}
int f[M];*/
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,k,flag=1;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) pre[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].x>>q[i].y>>q[i].w;
		bian p={min(q[i].x,q[i].y),max(q[i].x,q[i].y)};
		mp[p]=i;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>d[i].val;
		if(d[i].val) flag=0;
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(flag)
	{
		int cnt=m;
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(!mp[{j,k}]) mp[{j,k}]=++cnt,q[cnt].x=j,q[cnt].y=k,q[cnt].w=a[i][j]+a[i][k];
					else q[mp[{j,k}]].w=min(q[mp[{j,k}]].w,a[i][j]+a[i][k]);
				}
			}
		}
		sort(q+1,q+1+cnt,cmp);
		int ans=0;
		for(int i=1;i<=cnt;i++)
		{
			int u=q[i].x,v=q[i].y;
			int fu=cha(u),fv=cha(v);
			if(fv==fu) continue;
			pre[fv]=fu;
			ans+=q[i].w;
		}
		cout<<ans;
	}
	else
	{
		sort(q+1,q+1+m,cmp);
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int u=q[i].x,v=q[i].y;
			int fu=cha(u),fv=cha(v);
			if(fv==fu) continue;
			pre[fv]=fu;
			ans+=q[i].w;
		}
		cout<<ans;
	}
	//sort(d+1,d+1+k,cmp1);
	//cout<<k<<endl;
	/*
	for(int i=1;i<=k;i++)
	{
		cout<<d[i].val<<" "<<d[i].tt<<endl;
		for(int j=1;j<=m;j++) cout<<d[i].vis[j]<<" ";
		cout<<'\n';
	}
	for(int i=1;i<=k;i++)
	{
		
		if(d[i].val>=d[i].tt) break;
		ans-=(d[i].tt-d[i].val);
		for(int j=1;j<=m;j++) if(d[i].vis[j]) f[j]=1;
		for(int t=i+1;t<=k;t++)
		{
			for(int j=1;j<=m;j++)
			{
				if(f[j]&&d[t].vis[j]) d[t].tt-=(q[j].w-(a[t][q[j].x]+a[t][q[j].y])),d[t].vis[j]=0;
			}
		}
		sort(d+1+i,d+1+i+k,cmp1);
	}*/
	return 0;
}
