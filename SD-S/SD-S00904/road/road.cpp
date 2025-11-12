#include<bits/stdc++.h>
//#define int long long
using namespace std;
//xian da yi bian mst de banzi
//wo yunqi feichang cha wangle fuxi mst le 555
const int N=1e4+20;
int n,m,k,c[15],a[15][N],vis[N];
long long ans=0x3f3f3f3f3f3f3f3f;
struct lyl {
	int v,w;
	bool operator < (const lyl &a)const {
		if(w==a.w) return v<a.v;
		return w<a.w;
	}
};
vector<lyl>to[N],g[N];
long long res;
queue<int> q;
void mst(int st) {
	vis[st]=1;
	while(!q.empty()) q.pop();
	q.push(st);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int i=0; i<g[u].size(); i++) {
			int v=g[u][i].v,w=g[u][i].w;
			if(vis[v]) {
				res+=w;
				vis[u]=1;
				break;
			}
		}
		for(int i=0; i<g[u].size(); i++) {
			int v=g[u][i].v,w=g[u][i].w;
			if(!vis[v]) {
				q.push(v);
				break;
			}
		}
		//	cout<<u<<' '<<res<<'\n';
	}
}
long long solve(int S) {
	res=0;
	int cntn=0;
	for(int i=1; i<=n+k; i++) g[i]=to[i];
	/*if(S==0) {
		for(int i=1; i<=n; i++) {
			for(int j=0;j<to[i].size();j++){
				//cout<<i<<' '<<j<<' '<<g[i][j].v<<' '<<g[i][j].w<<'\n';
			}
		}
	}*/
	for(int i=1; i<=k; i++) {
		if((S>>(i-1))&1) {
			cntn++;
			res+=c[i];
			for(int j=1; j<=n; j++) g[n+cntn].push_back({j,a[i][j]}),g[j].push_back({n+cntn,a[i][j]});
		}
	}
	for(int i=1; i<=cntn+n; i++) sort(g[i].begin(),g[i].end());
	memset(vis,0,sizeof vis);
	mst(1);
//	cout<<S<<' '<<res<<'\n';
	return res;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int U,V,W;
		cin>>U>>V>>W;
		to[U].push_back({V,W});
		to[V].push_back({U,W});
	}
	int check1=1;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		if(c[i]) check1=0;
		for(int j=1; j<=n; j++) cin>>a[i][j];
	}
	if(k==0){
		for(int i=1; i<=n; i++) g[i]=to[i];
		for(int i=1; i<=n; i++) sort(g[i].begin(),g[i].end());
		mst(1);
		cout<<res;
		return 0;
	}
	if(check1){
		for(int i=1; i<=n+k; i++) g[i]=to[i];
		for(int i=1; i<=k; i++) {
			for(int j=1; j<=n; j++) {
				g[i+n].push_back({j,a[i][j]});
				g[j].push_back({i+n,a[i][j]});
			}
		}
		for(int i=1; i<=n+k; i++) sort(g[i].begin(),g[i].end());
		mst(1);
		cout<<res;
		return 0;
	}
	for(int S=0; S<(1<<k); S++) ans=min(ans,solve(S));
	cout<<ans;
	return 0;
}

