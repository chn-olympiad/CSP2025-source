#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N=1e4+20;
const int M=1e6+10;
int n,m,k;
struct EDGE{
	int u,v,w;
	bool operator <(EDGE &y){
		return w<y.w;
	}
};
vector<EDGE> adj;
int poi[15];
bool vis[15];
int fa[N];
void init(int x){
	for (int i=1; i<=x; i++){
		fa[i]=i;
	}
}
int find(int x){
	if (x!=fa[x]){
		return fa[x]=find(fa[x]);
	}else{
		return x;
	}
}
bool join(int x,int y){
	x=find(x);
	y=find(y);
	if (x==y){
		return 0;
	}
	fa[x]=y;
	return 1;
}
int ans=0;
void prim(){
	for (const auto &x:adj){
		int u=x.u;
		int v=x.v;
		int w=x.w;
		if (!join(u,v)){
			continue;
		}else{
			ans+=w;
			if (u>=n){
				if (!vis[u-n]){
					ans+=poi[u-n];
					vis[u-n]=1;
				}
			}
			if (v>=n){
				if (!vis[v-n]){
					ans+=poi[v-n];
					vis[v-n]=1;
				}
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	init(n+k);
	for (int i=1; i<=m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj.push_back({u,v,w});
		adj.push_back({v,u,w});
	}
	for (int i=1; i<=k; i++){
		cin>>poi[i];
		for (int j=1; j<=n; j++){
			int w;
			cin>>w;
			adj.push_back({n+i,j,w});
			adj.push_back({j,n+i,w});
		}
	}
	sort(adj.begin(),adj.end());
	prim();
	cout<<ans<<"\n";
	return 0;
}