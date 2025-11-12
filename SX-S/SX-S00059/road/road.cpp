#include<bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int, pair<int, int> > PII;

int n, m, k, ans;
priority_queue<PII, vector<PII>, greater<PII> > p;
queue<PII> q;
PII pq[11][2000001];
int cnt[11];
int fa[10050], c[11], d[10050], sz[10050], a[11][10050], cc[12];
bool vis[11][11], vv[11];

int find(int x){ return x == fa[x] ? x : fa[x] = find(fa[x]); }

pair<int, int> calc(){
	for(int i = 1; i <= n; i ++) d[i] = -1, fa[i] = i, sz[i] = 1;
	for(int i = n + 1; i <= n + k; i ++) d[i] = -1, fa[i] = i, sz[i] = 0;
	int res = 0;
	int ff = 0;
	while(!p.empty()){
		int u = p.top().second.first, v = p.top().second.second, w = p.top().first; q.push(p.top()); p.pop();
		ff ++;
		int x = find(u), y = find(v);
		if((u > n and !vv[u - n]) or (v > n and !vv[v - n]) or x == y) continue;
		res += w;
		if(d[u] == -1) d[u] = w;
		else d[u] = 0;
		if(d[v] == -1) d[v] = w;
		else d[v] = 0;
		sz[y] += sz[x];
		fa[x] = y;
		if(sz[find(1)] == n) break;
	}
	while(!q.empty()) p.push(q.front()), q.pop();
	for(int i = 1; i <= k; i ++) if(vv[i] and d[i + n] != 0){
		res -= c[i];
		if(d[i + n] > 0) res -= d[i + n];
	}
	return {res, ff};
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i = 1, u, v, w; i <= m; i ++){
		cin>>u>>v>>w;
		p.push({w, {u, v}});
	}
	auto kkk = calc(); ans = kkk.first, cnt[0] = kkk.second;
	for(int i = 1; i <= cnt[0]; i ++) pq[0][i] = p.top(), p.pop();
	for(int i = 1; i <= k; i ++){
		cin>>c[i];
		for(int j = 1; j <= n; j ++) cin>>a[i][j];
		int mn = 1e14 + 1;
		for(int l = 0; l < i; l ++){
			while(!p.empty()) p.pop();
			for(int j = 1; j <= cnt[l]; j ++) p.push(pq[l][j]);
			for(int j = 1; j <= n; j ++) p.push({a[i][j], {i + n, j}});
			for(int j = 1; j <= k; j ++) vv[j] = vis[l][j];
			vv[i] = 1;
			auto kkk = calc(); int t = kkk.first;
			if(t + cc[l] + c[i] < mn){
				mn = t + cc[l] + c[i];
				cc[i] = cc[l] + c[i];
				cnt[i] = kkk.second;
				for(int j = 1; j <= cnt[i]; j ++) pq[i][j] = p.top(), p.pop();
				for(int j = 1; j <= i; j ++) vis[i][j] = vv[j];
				for(int j = 1; j <= i; j ++) if(vis[i][j] && d[j + n] != 0) vis[i][j] = 0, cc[i] -= c[j];
			}
		}
		ans = min(ans, mn);
	}
	cout<<ans;
	return 0;
}