#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+50;
int n,m,k,fa[N],c[15],a[N][15],res=1e18+10,mx=0;
inline int find(int x)
{
//	cout<<x<<"\n";
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
struct S{
	int u,v,w;
};
vector<S>g;
bool cmp(S x,S y)
{
	return x.w<y.w;
}
bool vis[15];
multiset<pair<int,pair<int,int> > >s;
void dfs(int now)
{
	if(now>k)
	{
//		G=g;
		int cnt=n;
		int ans=0;
//		multiset<S>s;
		for(int i=1;i<=k;i++)
		{
			if(vis[i])
			{
				cnt++;
				ans+=c[i];
				for(int j=1;j<=n;j++)
				{
//					G.push_back({i+n,j,a[j][i]});
					s.insert({a[j][i],{i+n,j}});
				}
			}
		}
		if(cnt==0)return ;
//		cout<<"ran\n";
		for(int i=1;i<=n+cnt;i++)fa[i]=i;
		int i=0,le=g.size();
		
		while(i<le)
		{
			if(!s.size() || (*s.begin()).first>=g[i].w)
			{
				int u=g[i].u;
				int v=g[i].v;
				int w=g[i].w;
				i++;
				if(find(u)==find(v))continue;
				ans+=w;
				fa[find(v)]=find(u);
				cnt--;
				if(cnt==1)break;
				continue;
			}
			auto tp=*(s.begin());
			s.erase(s.begin());	
			int u=tp.second.first;
			int v=tp.second.second;
			int w=tp.first;
			if(find(u)==find(v))continue;
			ans+=w;
			fa[find(v)]=find(u);
			cnt--;
			if(cnt==1)break;
		}
//		cout<<ans<<"\n";
		res=min(res,ans);
		s.clear();
		return ;
	}
	vis[now]=1;
	dfs(now+1);
	vis[now]=0;
	dfs(now+1);
	return ;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	bool flagA=true;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g.emplace_back(S{u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)flagA=false; 
		bool flag=false;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][i];
			if(a[j][i]==0)flag=true;
		}
		if(!flag)flagA=false;
	}
	if(flagA)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				g.push_back({n+i,j,a[j][i]});
			}
		}
		n+=k;
		
		for(int i=1;i<=n;i++)fa[i]=i;
		sort(g.begin(),g.end(),cmp);
		int ans=0,cnt=n;
		for(auto k:g)
		{
			int u=k.u;
			int v=k.v;
			int w=k.w;
			if(find(u)==find(v))continue;
			ans+=w;
			fa[find(v)]=find(u);
			cnt--;
			if(cnt==1)break;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(g.begin(),g.end(),cmp);
	int ans=0,cnt=n;
//	cout<<"ran\n";
	for(auto k:g)
	{
		int u=k.u;
		int v=k.v;
		int w=k.w;
		if(find(u)==find(v))continue;
		ans+=w;
		mx=max(mx,w); 
		fa[find(v)]=find(u);
		cnt--;
		if(cnt==1)break;
	}
	res=ans;
	if(k==0) 
	{
		cout<<ans;
		return 0;
	}
//	cout<<"ran\n";
	dfs(1);
	cout<<res;
	
	return 0;
}

//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4