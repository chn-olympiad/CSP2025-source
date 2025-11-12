#include <bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
int n, m, k;
ll ans=0x3f3f3f3f3f3f3f3f;
// LingJieBiao
typedef pair<ll,int>/*w, to*/ pli;
pli table[8000006];
int head[N], nxt[3000006], edd;
void add(int u, int v, ll w) {
	nxt[++edd] = head[u];
	head[u] = edd;
	table[edd] = {w, v};
}
// 
ll dis[N]; bool vis[N], act[N], disact[N];
void Prim(ll tmp) {
	memset(dis, 0x3f, (n+k+10)*sizeof(ll));
	memset(vis, 0, (n+k+10)*sizeof(bool)); dis[1] = 0;
	priority_queue<pair<ll,int>/*dis, v*/> q; q.push({0, 1});
	while(!q.empty()) {
		int u = q.top().second; q.pop();
		if(vis[u]) continue;; vis[u] = 1;
		tmp += dis[u];
		if(tmp >= ans) return;
		for(int p=head[u] ; p ; p=nxt[p]) {
			auto &s = table[p];
			int v = s.second; ll w = s.first;
			if(v > n && !act[v-n]) continue;
			if(!vis[v] && dis[v] > w) {
				dis[v] = w;
				q.push({-dis[v], v});
			}
		}
	} ans = tmp;
}
int c[20], a[N];
void dfs(int kl, ll tmp) {
	if(tmp >= ans) return;
	if(kl > k) {
		Prim(tmp);
		return;
	}
	dfs(kl+1, tmp);
	if(!disact[kl]) {
		act[kl] = 1;
		dfs(kl+1, tmp+c[kl]);
		act[kl] = 0;
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for(int i=0,u,v,w ; i<m ; i++) {
		cin >> u >> v >> w;
		add(u,v,w); add(v,u,w);
	}
	int disactcnt=0;
	for(int i=1,p=-1 ; i<=k ; i++) {
		cin >> c[i];
		for(int j=1 ; j<=n ; j++) {
			cin >> a[j];
			if(!a[j]) p = j;
			add(i+n, j, a[j]); add(j, i+n, a[j]);
		}
		if(!c[i] && p != -1) { // SubtaskA
			disact[i] = 1; disactcnt ++;
			for(int j=1 ; j<=n ; j++) {
				if(j == p) continue;
				add(p, j, a[j]); add(j, p, a[j]);
			}
		}
	}
	if(disactcnt == k) Prim(0);
	else dfs(1, 0);
	printf("%lld", ans);
	return 0;
}
