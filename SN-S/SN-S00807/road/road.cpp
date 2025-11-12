#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Revi{
	const int N=1e6+5;
	int n,m,k;
	struct edge{
		int u,v,w;
	}e[N];
	struct cr{
		int c;
		int a[N];
	}v[12];
	int id[N],dep[N];
	int finds(int x){
		if(x==id[x]) return id[x];
		return id[x]=finds(id[x]);
	}
	bool cmp(edge a,edge b){
		return a.w<b.w;
	}
	bool cmp2(cr a,cr b){
		return a.c<b.c;
	}
	vector<pair<int,int> > g[N];
	inline void work()
	{
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			e[i]={u,v,w};	
		}
		int ttt=0;
		for(int i=1;i<=k;i++){
			cin>>v[i].c;
			ttt+=v[i].c;
			for(int j=1;j<=n;j++) cin>>v[i].a[j];
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n;i++) id[i]=i,dep[i]=1;
		int ans=0;
		for(int i=1;i<=m;i++){
			//cout<<i<<endl;
			int U=finds(e[i].u),V=finds(e[i].v);
			if(U==V) continue;
			ans+=e[i].w;
			g[e[i].u].push_back(make_pair(e[i].v,e[i].w));
			//g[e[i].v].push_back(make_pair(e[i].u,e[i].w));
			if(dep[U]>=dep[V]) id[V]=U,dep[U]=max(dep[U],dep[V]+1);
			else id[U]=V,dep[V]=max(dep[V],dep[U]+1);
		}
		if(k==0){
			cout<<ans;
			return ;
		}
		int A=((1<<k)-1);
		if(ttt) A=1;
		for(int i=A;i<=(1<<k)-1;i++)
		{
			//cout<<i<<endl;
			int tmp=0;
			vector<edge> E;
			int cnt=n;
			for(int j=1;j<=n;j++)
			{
				for(pair<int,int> r:g[j]) E.push_back({j,r.first,r.second});
			} 
			for(int j=0;j<k;j++)
			{
				if(i&(1<<j))
				{
					cnt++;
					for(int r=1;r<=n;r++)
					{
						E.push_back({cnt,r,v[j+1].a[r]});
					}
					cnt++;
					E.push_back({cnt-1,cnt,v[j+1].c});
				}
			}
			sort(E.begin(),E.end(),cmp);
			//for(edge i:E) cout<<i.u<<" "<<i.v<<" "<<i.w<<"\n";
			//cout<<"\n";
			for(int j=1;j<=cnt;j++) id[j]=j,dep[j]=1;
			for(edge j:E){
				int U=finds(j.u),V=finds(j.v);
				if(U==V) continue;
				tmp+=j.w;
				//g[i.u].push_back(make_pair(e[i].v,e[i].w));
				//g[e[i].v].push_back(make_pair(e[i].u,e[i].w));
				if(dep[U]>=dep[V]) id[V]=U,dep[U]=max(dep[U],dep[V]+1);
				else id[U]=V,dep[V]=max(dep[V],dep[U]+1);
			}
			ans=min(ans,tmp);
		}
		cout<<ans;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Revi::work();
	return 0;
 } 
 
 
 
 /*
 
 Faster Faster Faster!  
 Let me pass it!
 
 */
