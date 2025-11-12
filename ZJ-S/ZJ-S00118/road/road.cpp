#include<bits/stdc++.h>
using namespace std;
int n,m,k,vis[1000010],cntn,cntm,c[20],f[20][10010],fa[10010],cnt;
long long ans;
struct node{
	int x,y,z;
}a[2000010],tmp[1000010];
bool cmp(node x,node y)
{
	return x.z<y.z;
}
int getf(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=getf(fa[x]);
}
void solve()
{
	cntn=n;cntm=m;long long ret=0;cnt=0;
	for(int i=1;i<=m;i++) a[i].x=tmp[i].x,a[i].y=tmp[i].y,a[i].z=tmp[i].z;
	for(int i=1;i<=k;i++) 
	{
		if(vis[i]==1) 
		{
			cntn++;ret+=c[i];
			for(int j=1;j<=n;j++)
			{
				a[++cntm]={cntn,j,f[i][j]};
			}
		}
	}for(int i=1;i<=cntn;i++) fa[i]=i;
	sort(a+1,a+cntm,cmp);
	for(int i=1;i<=cntm;i++)
	{
		int u=getf(a[i].x),v=getf(a[i].y);
		if(u!=v)
		{
			fa[u]=v;
			ret+=a[i].z;
			cnt++;
		}
		if(cnt==cntn-1) break;
	}
	ans=min(ans,ret);
}
void dfs(int x)
{
	if(x==k+1)
	{
		solve();
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;ans=1e18;
	for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	for(int i=1;i<=m;i++) tmp[i].x=a[i].x,tmp[i].y=a[i].y,tmp[i].z=a[i].z;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>f[i][j];
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}//fc road2.out road2.ans
