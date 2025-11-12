#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int maxn = 1e4+5;
int n,m,k;
vector<pii> G[maxn+23];
int ans,vc;
bool vis[maxn+23];
void K(int u){
	vis[u] = 1;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	for (pii e:G[u]){
		pq.push(e);
	}
	while (!pq.empty()){
		pii v = pq.top();
//		cout<<"get "<<v.second<<" "<<v.first<<"\n";
		pq.pop();
		if (vis[v.second]) continue;
		vis[v.second] = 1;
		ans+=v.first;
		for (pii e:G[v.second]){
			if (!vis[e.second]) pq.push(e);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (int i = 1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({w,v});
		G[v].push_back({w,u});
	}
	for (int i = 1;i<=k;i++){
		int c,w;
		cin>>c;
		G[n+k+i].push_back({c,n+i});
		G[n+i].push_back({c,n+k+i});
		for (int j = 1;j<=n;j++){
			cin>>w;
			G[n+i].push_back({w,j});
			G[j].push_back({w,n+i});
		}
	}
	K(1);
	cout<<ans<<endl;
	return 0;
}