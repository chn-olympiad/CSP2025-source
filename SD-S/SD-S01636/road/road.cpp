#include<bits/stdc++.h>
#define pr pair<int,int>
using namespace std;
using llt=long long;
const int maxn=1e4+10+5,maxm=1e6+1e5+5;
int n,m,k,fa[maxn],f[maxn][14],dep[maxn];//13
bool vis[15];
llt c[15],mn[15],lmn[15],a[15][maxn],ans=0,mx[maxn][14];
//unordered_map<pr,llt> mp;
struct edge
{
	int u,v;
	llt w;
};
struct node
{
	int u;
	llt w;
};
vector<node> g[maxn];
edge e[maxm];
vector<int> h[15];
int getfa(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=getfa(fa[x]);
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
void dfs(int u,int ft)
{
	f[u][0]=ft;
	dep[u]=dep[ft]+1;
	for(auto v:g[u])
	{
		if(v.u!=ft)
		{
			mx[v.u][0]=v.w;
			dfs(v.u,u);
		}
	}
}
llt lca(int u,int v)
{
//	cout<<u<<" "<<v<<'\n';
	llt res=0;
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=13;i>=0;i--)
	{
		if(dep[f[u][i]]>=dep[v])
		{
			res=max(res,mx[u][i]);
			u=f[u][i];
		}
	}
	if(u==v) return res;
	for(int i=13;i>=0;i--)
	{
		if(f[u][i]!=f[v][i])
		{
			res=max({res,mx[u][i],mx[v][i]});
			u=f[u][i];
			v=f[v][i];
		}
	}
	return max({res,mx[u][0],mx[v][0]});
}
void kur()
{
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v;
		llt w=e[i].w;
		if(getfa(u)==getfa(v)) continue;
		fa[getfa(u)]=getfa(v);
//		cout<<u<<" "<<v<<" "<<w<<"\n";
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		ans+=w;
	}
//	cout<<"\n";
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
//	double ppp=clock();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		a[i][0]=1e9+7;
		mn[i]=lmn[i]=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][mn[i]]>a[i][j])
			{
				lmn[i]=mn[i];
				mn[i]=j;
			}
			else if(a[i][lmn[i]]>a[i][j]) lmn[i]=j;
		}
	}
	//
	kur();
	
	ans=0;
	dfs(1,1);
	
	for(int j=1;j<=13;j++)
	{
		for(int i=1;i<=n;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
			mx[i][j]=max(mx[f[i][j-1]][j-1],mx[i][j-1]);
		}
	}
	for(int i=1;i<=k;i++)
	{
		llt s1=0,s2=c[i];
		for(int j=1;j<=n;j++)
		{
			int p=mn[i];
			if(j==mn[i]) p=lmn[i];
//			if(j>p) swap(j,p);
//			s1+=min(lca(j,p),mp[{j,p}]);
			llt t=lca(j,p);
			if(t>a[i][j]+a[i][p])
			{
				s1+=t;
				s2+=a[i][j]+a[i][p];
			}
		}
		if(s1>s2)
		{
			
			for(int j=1;j<=n;j++)
			{
				int p=mn[i];
				if(j==mn[i]) p=lmn[i];
//				if(j>p) swap(j,p);
//				mp[{j,p}]=min(mp[{j,p}],a[i][j]+a[i][j]);
				e[++m]={j,p,a[i][j]+a[i][p]};
			}
			ans+=c[i];
		}
	}
	kur();
	cout<<ans;
//	cout<<"\n"<<clock()-ppp;
	return 0;
}
//why #4 is WA.
//i almost cry out.
//hope it works, qwq.
