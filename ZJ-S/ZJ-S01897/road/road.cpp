#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=2e5+10;
vector<int> g[maxn];
struct gqh
{
	int u,v,w,id;
};
bool cmp(gqh a,gqh b)
{
	return a.w<b.w;
}
const int maxm=2e6+10;
gqh b[maxm];
gqh c[maxm];
int tot,id;
int f[maxn];
int n,m,k;
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
bitset<maxm> used;
ll Winner()
{
	for(int i=1;i<=tot;i++) c[i]=b[i];
	sort(c+1,c+1+tot,cmp);
	for(int i=1;i<=id;i++) f[i]=i;
	ll res=0;
	int num=0;
	for(int i=1;i<=tot;i++)
	{
		if(find(c[i].u)==find(c[i].v)) continue;
		f[find(c[i].u)]=find(c[i].v);
		res+=c[i].w;
		if(num==id-1) break;
	}
	return res;
}
int cs=0;
void wk()
{
	for(int i=1;i<=tot;i++) c[i]=b[i];
	stable_sort(c+1,c+1+tot,cmp);
	for(int i=1;i<=id;i++) f[i]=i;
	int num=0,u=0;
	for(int i=1;i<=tot;i++)
	{
		//cs++;
		if(find(c[i].u)==find(c[i].v)) continue;
		f[find(c[i].u)]=find(c[i].v);
		used[c[i].id]=1;
		b[++u]=c[i];
		num++;
		if(num==id-1) break;
	}
	tot=u;
}
ll C[11];
int w[11][10005];
bool get(int x,int w)
{
	return (x>>w)&1;
}
void read(int &x)
{
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
}
ll ans=1e18;
void dfs(int x,ll ad)
{
	if(x>k)
	{
		ans=min(ans,Winner()+ad);
		return;
	}
	dfs(x+1,ad);
	id++;
	for(int j=1;j<=n;j++)
	{
		tot++,b[tot].u=id,b[tot].v=j,b[tot].w=w[x][j];
	}
	ad+=C[x];
	dfs(x+1,ad);
	tot-=n,id--;
}
int main()
{
//	cerr<<(1024*1e4*log2(1e4))<<"\n";
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Ios();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		tot++;
//		read(b[tot].u);
//		read(b[tot].v);
//		read(b[tot].w);
		cin>>b[tot].u>>b[tot].v>>b[tot].w;
		b[tot].id=i;
	}
	bool p=0;
	for(int d=1;d<=k;d++)
	{
		cin>>C[d];
		p|=C[d];
		for(int j=1;j<=n;j++) cin>>w[d][j];
	}
	tot=m,id=n;
	wk();
	id=n;
	if(!p)
	{
		ll ans=1e18;
		int beg=0;
		if(!p) beg=(1<<k)-1;
		for(int i=beg;i<(1<<k);i++)
		{
			//cerr<<i<<"/"<<(1<<k)<<"\n";
			tot=m,id=n;
			ll ad=0;
			for(int p=1;p<=k;p++)
			if(get(i,p-1))
			{
				id++;
				for(int j=1;j<=n;j++)
				tot++,b[tot].u=id,b[tot].v=j,b[tot].w=w[p][j];
				ad+=C[p];
			}
			ans=min(ans,Winner()+ad);
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
	//cerr<<cs<<"\n";
}
//I really want to win!
//luogu uid 734379
//winwiwnwinwniwinwinws