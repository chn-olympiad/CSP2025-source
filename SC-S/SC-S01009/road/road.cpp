#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans;
int f[1000010];
int c[1000010];
bool vis[1000010];
struct edge{
	int u,v,w;
	bool operator<(const edge& other) const{
		return w<other.w;
	}
};
int find(int x){
	if(f[x]==x) return f[x];
	return f[x]=find(f[x]);
}
void merge(int u,int v){
	f[find(u)]=find(v);
}
bool check(){
	for(int i=2;i<=n;i++){
		if(find(1)!=find(i)) return 0;
	}
	return 1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	vector<edge> e(m);
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[n+i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			e.push_back({n+i,j,c[n+i]+w});
		}
	}
	for(int i=0;i<=n+k;i++) f[i]=i;
	sort(e.begin(),e.end());
	for(auto i:e){
		int u=i.u,v=i.v,w=i.w;
		if(find(u)!=find(v)){
			merge(u,v);
			if(vis[u]) ans-=c[u];
			if(vis[v]) ans-=c[v];
			ans+=w;
			if(u>n&&!vis[u]) vis[u]=1;
			if(v>n&&!vis[v]) vis[v]=1;
			if(check()) break;
		}
	}
	cout<<ans;
	return 0;	
}