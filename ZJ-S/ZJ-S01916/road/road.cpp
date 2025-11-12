#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long
const int maxn=1<<14;
const int Inf=20220125ll*0x9999FF;
int n,m,k,ans=Inf;
struct edge {
	int v,w;
	bool operator<(const edge &n2)const {
		return w<n2.w;
	}
};
vector<edge>g[maxn];
int a[20][maxn];
int c[20];
struct Ed {
	int u,v,w;
	bool operator<(const Ed &n2)const {
		return w>n2.w;
	}
};
inline int Kruskal(set<int> &village) {
	int cnt=0;
	//去农村化
	for(register int u:village) {
		for(register int v=1; v<=n; v++) {
			g[u+n].push_back({v,a[u][v]});
			g[v].push_back({u+n,a[u][v]});
		}
		cnt+=c[u];
	}
	//Kruskal
	set<int>pt;
	priority_queue<Ed>ed;
	pt.insert(1);
	for(register auto i:g[1])ed.push({1,i.v,i.w});
	while(pt.size()<n+village.size()) {
		Ed e=ed.top();
		while(pt.count(e.u)&&pt.count(e.v)){
			ed.pop();
			e=ed.top();
		}
		ed.pop();
		cnt+=e.w;
		register int u;
		if(!pt.count(e.u))u=e.u;
		else u=e.v;
		pt.insert(u);
		for(register auto i:g[u]) {
			if(!pt.count(i.v))ed.push({u,i.v,i.w});
		}
	}
	//去城市化
	for(register int i=n+1;i<=n+k;i++)g[i].clear();
	return cnt;
}
void spj();
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	while(m--) {
		register int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	if(k==0) {//退化为Kruskal求最小生成树问题
		spj();
		return 0;
	}
	for(register int i=1; i<=k; i++) {
		cin>>c[i];
		for(int v=1; v<=n; v++){
			cin>>a[i][v];
		}
	}
	//状压01dfs去农村化地区
	for(register int i=0; i<1<<k; i++) {
		set<int>lang3nuo4;
		lang3nuo4.clear();
		for(register int j=1; j<=k; j++)
			if((i>>j-1)&1)lang3nuo4.insert(j);
		ans=min(ans,Kruskal(lang3nuo4));
	}
	cout<<ans;
	return 0;
}
void spj() {
	set<int>pt;
	priority_queue<Ed>ed;
	int ans=0;
	pt.insert(1);
	for(auto i:g[1])ed.push({1,i.v,i.w});
	while(pt.size()<n) {
		Ed e=ed.top();
		while(pt.count(e.u)&&pt.count(e.v)){
			ed.pop();
			e=ed.top();
		}
		ed.pop();
		ans+=e.w;
		int u;
		if(!pt.count(e.u))u=e.u;
		else u=e.v;
		pt.insert(u);
		for(auto i:g[u]) {
			if(!pt.count(i.v))ed.push({u,i.v,i.w});
		}
	}
	cout<<ans;
}
