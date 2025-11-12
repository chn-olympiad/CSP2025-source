#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;
using pii=pair<int,int>;
const int N=1e4+3;
vector<pii> mp[N];
int c[13],a[13][N];
int fa[N];
int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
struct node {
	int u,v,w;
	friend bool operator<(node a,node b) {
		return a.w<b.w;
	}
}mps[1000003];
ll kruskal(int n,int m) {
	for(int i=1;i<=n;i++) fa[i]=i;
	int cnt=0;
	ll sum=0;
	sort(mps+1,mps+1+m);
	for(int i=1;i<=m;i++) {
		int fu=find(mps[i].u),fv=find(mps[i].v);
		if(fu==fv) continue;
		fa[fu]=fv;
		cnt++, sum+=mps[i].w;
		if(cnt==n-1) break;
	}
	if(cnt!=n-1) return -1;
	return sum;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		mp[u].push_back({v,w});
		mp[v].push_back({u,w});
		mps[i]={u,v,w};
	}
	bool fg=1;
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		if(c[i]) fg=0;
		for(int j=1;j<=n;j++) cin>>a[i][j],fg&=(!a[i][j]);
	}
	if(fg) {
		cout<<0;
		return 0;
	}
	ll ans=kruskal(n,m);
	cout<<ans;
	return 0;
}
