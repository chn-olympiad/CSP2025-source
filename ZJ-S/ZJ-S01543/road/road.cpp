#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=1e4+5;
const int K=15;
struct DSU{
	vector<int> parent;
	DSU(int n):parent(n+K){
		for(int i=0;i<n+K;i++)
			parent[i]=i;
	}
	
	int find(int x){
		if(parent[x]!=x) 
			return parent[x]=find(parent[x]);
		return parent[x];
	}
	
	void merge(int x,int y){
		int rx=find(x),ry=find(y);
		if(rx!=ry){
			int u=min(rx,ry),v=max(rx,ry);
			parent[v]=u;
		}
	}
	
	bool is_merge(int x,int y){
		return find(x)==find(y);
	}
};
int n,m,k;
//vector<vector<pair<int,int> > >adj(N);
int c[N+K];
int a[K][N];

struct edge{
	int u,v;
	ll w;
};
vector<edge> edges;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
bool vis[N+K];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
//		adj[u].push_back({v,w});
//		adj[v].push_back({u,w});
		edges.push_back({u,v,w});
	}

//	for(int i=1;i<=k;i++){
//		cin>>c[i];
//		for(int j=1;j<=n;j++)
//			cin>>a[i][j];
//	}
//	
//	bool c_zero=true;
//	for(int i=1;i<=k;i++){
//		if(c[i]!=0){
//			c_zero=false;
//			break;
//		}
//	}
	

//	for(int it=1;it<=k;it++){
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				
//			}
//		}
//	}
	
	bool c_zero=true;
	for(int i=1;i<=k;i++){
		cin>>c[n+i];
		if(c[n+i]!=0)
			c_zero=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
//			int u=j,v=n+i,w=a[i][j];
//			adj[u].push_back({v,w});
//			adj[v].push_back({u,w});
//			edges.push_back({u,v,w});
		}
	}
	
	if(k==0){
		DSU dsu(n);sort(edges.begin(),edges.end(),cmp);
		ll res=0,num=0;
		for(int i=0;i<edges.size();i++){
			edge e=edges[i];
			int u=e.u,v=e.v;
			ll w=e.w;
			if(!dsu.is_merge(u,v)){
				dsu.merge(u,v);
				res+=w;num++;
			}
			if(num==n-1)
				break;
		}
		if(k==0) cout<<res<<"\n";
	}
	
	if(c_zero){
		DSU dsu(n);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int u=i,v=j;
				int w=LLONG_MAX;
				for(int it=1;it<=k;it++)
					w=min(w,a[it][i]+a[it][j]);
				edges.push_back({u,v,w});
			}
		}
		
		sort(edges.begin(),edges.end(),cmp);
		ll res=0,num=0;
		for(int i=0;i<edges.size();i++){
			edge e=edges[i];
			int u=e.u,v=e.v;
			ll w=e.w;
			if(!dsu.is_merge(u,v)){
				dsu.merge(u,v);
				res+=w;num++;
				if(num==n-1)
					break;
			}
		}
		
		cout<<res<<"\n";
		return 0;
	}
	
	ll ans=LLONG_MAX;
	for(int it=0;it<=k;it++){
		
	for(int j=1;j<=n;j++){
		int u=j,v=n+it,w=a[it][j];
//		adj[u].push_back({v,w});
//		adj[v].push_back({u,w});
		edges.push_back({u,v,w});
	}
	
	ll sum=0;
	for(int i=1;i<=it;i++)
		sum+=c[n+i];
		
	DSU dsu(n);
	cerr<<edges.size()<<"\n";
	sort(edges.begin(),edges.end(),cmp);
	ll res=0;
	int num=0;
	int L=edges.size();
	for(int i=0;i<L;i++){
		edge e=edges[i];
		int u=e.u,v=e.v;
		ll w=e.w;
		if(!dsu.is_merge(u,v)){
			dsu.merge(u,v);
			res+=w;
			num++;
			if(num==n+it-1)
				break;
//			if(!vis[u]){
//				res+=c[u];
//				vis[u]=true;
//				if(u<=n)
//					num++;
//			}
//			if(!vis[v]){
//				res+=c[v];
//				vis[v]=true;
//				if(v<=n)
//					num++;
//			}
//			if(num>n)
//				break;
		}
	}
	ans=min(ans,res+sum);
	
	}
	cout<<ans<<"\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
