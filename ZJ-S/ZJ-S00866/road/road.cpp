#include<bits/stdc++.h>
using namespace std;
const int M=1.1e6+20;
const int N=1e4+15;
int n,m,k,vis[N],dis[N],ans,c[N],cnt,Q,w[N];
struct Node {
	int u,v,w;
} a[M];
struct edge {
	int v,w;
};
vector<edge> e[N];
struct node {
	int u,dis;
	bool operator >(const node& a)const {
		return dis>a.dis;
	}
};
priority_queue<node,vector<node>,greater<node> > q;
void Prim() {
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	q.push({1,0});
	while(!q.empty()) {
		auto h=q.top();
		q.pop();
		if(cnt>=n)break;
		int u=h.u;
		if(vis[u])continue;
		vis[u]=1;
		ans+=h.dis;
		cnt++;
		for(auto k:e[u]) {
			int to=k.v,w=k.w;
			if(w<dis[to]) {
				dis[to]=w;
				q.push({to,dis[to]});
			}
		}
	}
	cout<<ans;
}
bool cmp(Node a,Node b) {
	return a.w<b.w;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	if(!k) {
		Prim();
		return 0;
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		Q+=(!c[i]);
		for(int j=1; j<=n; j++) {
			cin>>w[j];
			for(int l=1;l<=n;l++){
				if(l^j){
					e[l].push_back({j,w[j]+w[l]});
					e[j].push_back({l,w[j]+w[l]});
				}
			}
		}
	}
	if(Q==k) {
		Prim();
		return 0;
	}
	return 0;
}

