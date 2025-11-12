#include<bits/stdc++.h>
using namespace std;
const long long N = 1003004;
long long fa[N],c[N];
bool vis[N];
long long n,m,k,ans;
//vector <pair <long long,long long> > g[N];
long long fnd(long long u) {
	if(fa[u] == u) return u;
	return fa[u] = fnd(fa[u]);
}
void mg(long long u,long long v) {
	u = fnd(u);
	v = fnd(v);
	if(u == v) return;
	fa[u] = v;
}
bool chk(long long u,long long v) {
	u = fnd(u),v = fnd(v);
	return u == v;
}
void init_(long long x) {
	for(long long i = 1;i <= x;i ++) {
		fa[i] = i;
	}
}
priority_queue <pair <long long,pair <long long,long long> > ,vector <pair <long long,pair <long long,long long> > >,greater <pair <long long,pair <long long,long long> > > > q;
//priority_queue <Q ,vector <Q>,greater <Q> > q;
void kru() {
	init_(n + k);
	
	while(q.size()) {
		auto t = q.top();
		long long w = t.first,u = t.second.first,v = t.second.second;
		q.pop();
		if(chk(u,v)) continue;
		mg(u,v);
		ans += w;
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road1.in","r",stdin);
//	freopen("road2.in","r",stdin);
//	freopen("road3.in","r",stdin);
//	freopen("road4.in","r",stdin);
	cin>>n>>m>>k;
	k = 0;
	for(long long i = 1;i <= m;i ++) {
		long long u,v,w;
		cin>>u>>v>>w;
		q.push({w,{u,v}});
		q.push({w,{v,u}});
//		g[u].push_back({v,w});
//		g[v].push_back({u,w});
	} 
	
	for(long long i = 1;i <= k;i ++) {
		long long w;
		cin>>c[i];
		for(long long j = 1;j <= n;j ++) {
			cin>>w;
			q.push({w,{i + n,j}});
			q.push({w,{j,i + n}});
//			g[i + n].push_back({j,w});
//			g[j].push_back({i + n,w});
		}
	}
	
	kru();
	cout<<ans<<"\n";
	return 0;
}
