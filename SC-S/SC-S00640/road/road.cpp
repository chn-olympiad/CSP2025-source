#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N = 1e4+5, M = 1e6+5, K=11;

int n,m,k,a[K][N],c[K],fa[N];
vector<pii> edge[N];
struct Node{
	int u,v,w;
}; 
priority_queue<pii,vector<pii>,greater<pii>> pq;
int findfa(int x) {
	if(fa[x]==x) return x;
	return fa[x] = findfa(fa[x]);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i) {
		cin>>u>>v>>w;
		edge[u].push_back({w,v});
		edge[v].push_back({w,u});
	}
	bool flag = true;
	for(int i=1;i<=k;++i) {
		cin>>c[i];
		if(c[i]!=0) flag = false;
		for(int j=1;j<=n;++j) {
			cin>>a[i][j];
			if(a[i][j]!=0) flag = false;
		}
	}
	if(flag) {
		cout<<0; 
	} else {
		for(auto i : edge[1]) pq.push(i);
		int times = 0, ans = 0;
		while(pq.size() && times<n) {
			auto &p = pq.top(); pq.pop();
			int f = findfa(p.second);
			if(f!=1) {
				fa[p.second] = 1;
				ans += p.first;
				++times;
				for(auto i : edge[p.second]) pq.push(i);
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}