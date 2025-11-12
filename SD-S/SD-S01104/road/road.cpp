#include<bits/stdc++.h>
#define int long long
#define node pair<int, pair<int, int> > 
using namespace std;
int n, m, k;
int c[11], a[11][11000], fa[11000], ans = 0x7fffffffffffffff, sz[11000], flag[11], sum[11], vis[11000]; 
vector<node > g;
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
int res = 0;
priority_queue<node> q;
void solve(){
	int cnt = 0;
	for(int i = 1;i <= k;i++) flag[i] = 0, sum[i] = 0;
	for(int i = 1;i <= n + k;i++) fa[i] = i, sz[i] = 1;
	for(int i = 0;i < g.size();i++){
		q.push(g[i]);
	}
	while(!q.empty()){
		int w = -q.top().first;
		int u = q.top().second.first;
		int v = q.top().second.second;
		q.pop();
		int fu = find(u), fv = find(v);
		if(fu != fv){
			if(v > n) flag[v]++;
			if(v > n && flag[v] == 1){
				for(int j = 1;j <= n;j++){
					if(j == u) continue;
					q.push(make_pair(-(a[v - n][j]), make_pair(j, v)));
				}
				sum[v] = w;
			}
			if(sz[fu] < sz[fv]) swap(fu, fv);
			fa[fu] = fv;
			sz[fu] += sz[fv];
			res += w;
			if(u <= n && !vis[u]) cnt++, vis[u] = 1;
			if(v <= n && !vis[v]) cnt++, vis[v] = 1;
			if(cnt == n) break;
		}
	}
	for(int i = 1;i <= k;i++){
		if(flag[i] == 1){
			res -= sum[i];
		}
	}
	ans = min(ans, res);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		node temp;
		cin >> temp.second.first >> temp.second.second >> temp.first;
		temp.first = -temp.first;
		g.push_back(temp);
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		} 
		for(int j = 1;j <= n;j++){
			g.push_back(make_pair(-(a[i][j] + c[i]), make_pair(j, i + n)));
		}
	}
	solve();
	cout << ans;
	return 0;
}
