#include<bits/stdc++.h>
#define ll long long
//#define int long long
using namespace std;
const int maxn=2e5+9;
int T;
int n;
struct node1
{
	int w;
	int id;
	int p;
	bool operator<(const node1 b)const
	{
		return w<b.w;
	};
}dd[maxn*4];
bool vis[maxn];
int cnt[4];
struct wp
{
	int w;int id;int p;
	bool operator<(const wp b)const
	{
		return w<b.w;
	};
};
priority_queue<wp,vector<wp> > q[4];
struct node
{
	int w;
	int id;
	bool operator<(const node b)const
	{
		return w<b.w;
	};
}a[4][maxn];
bool cmp(node x,node y)
{
	return x.w>y.w;
}
int tot;
int x[maxn][4];
ll ans=0;
int c[maxn];
void dfs(int xx,int dep)
{
	c[dep]=xx;
	if(dep==n)
	{
		ll res=0;
		for(int i=1;i<=n;i++) res+=x[i][c[i]];
		ans=max(ans,res);
		return;
	}
	for(int i=1;i<=3;i++) 
	{
		if(cnt[i]>=n/2) continue;
		cnt[i]++;
		dfs(i,dep+1);
		cnt[i]--;
	}
}
int dfs1(int id,int p)
{
	int w=x[id][p];
	auto v=q[p].top();
	int tmp=0;int f=0;
	for(int j=1;j<=3;j++)
	{
		if(j==v.p) continue;
		if(cnt[j]>=n/2) 
		{
			continue;
		}
		if(x[v.id][j]>tmp) tmp=x[v.id][j],f=j;
	}
	if(tmp+w>v.w)
	{
		q[v.p].pop();
		q[p].push({w,id,p});
		vis[v.id]=1;
		q[f].push({tmp,v.id,f});
		cnt[f]++;
		ans+=w;
		ans+=tmp;
		ans-=v.w;
		return 1;
	}
	return -1;
}
void solve()
{
	cin>>n;
	bool fl=1;
	tot=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>x[i][j];
			fl&=(x[i][j]==0);
			a[j][i].w=x[i][j];
			a[j][i].id=i;
			tot++;
			dd[tot].w=x[i][j];
			dd[tot].id=i;dd[tot].p=j;
		}
	}
	ans=0;
	if(fl)
	{
		sort(a[1]+1,a[1]+n+1,cmp);
		for(int i=1;i<=n/2;i++) ans+=a[1][i].w;
		cout<<ans<<'\n';
		return;
	}
	if(n<20)
	{	
		dfs(0,0);
		cout<<ans<<'\n';
		return;
	}
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int j=1;j<4;j++){
		while(!q[j].empty()) q[j].pop();
		cnt[j]=0;
	}
	sort(dd+1,dd+tot+1);
	ans=0;
	for(int i=tot;i>=1;i--)
	{
		int w=dd[i].w,id=dd[i].id,p=dd[i].p;
		if(vis[id]) continue;
		if(cnt[p]>=n/2) 
		{
			dfs1(id,p);
			continue;			
		}
		ans+=w;
		q[p].push({w,id,p});
		vis[id]=1;cnt[p]++;
	}
	cout<<ans<<'\n';
}
signed main()
{
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}