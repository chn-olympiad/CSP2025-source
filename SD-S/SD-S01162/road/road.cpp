#include <bits/stdc++.h>
#define Ios(a) ios::sync_with_stdio(a); cin.tie(a)
#define rep(i, e, p) for(int i = (e); i <= (p); ++i)
using namespace std;
typedef long long lint;
const int N = 1e6 + 10;
const int INF = INT_MAX;
int n, m, k, c; bool vis[N];
struct Node{
	int v, w;
	bool operator < (const Node &other) const {
		return w < other.w;
	}
} tmp;
struct Edge{
	int to, nxt, val;
} edge[N];
lint ans = INF, dis[N], sum;
int head[N], cnt = 0, a[11][N];
void add(int u, int v, int k){
	edge[++cnt].to = v;
	edge[cnt].val = k;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}
void Prim(){
	rep(i, 1, n) dis[i] = INF;
	dis[1] = 0;
	priority_queue<Node> q;
	tmp.v = 1; tmp.w = 0; q.push(tmp);
	while(!q.empty()){
		int u = q.top().v;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u]; i; i = edge[i].nxt){
			rep(kk, 1, k) if(a[kk][u] + a[kk][edge[i].to] < edge[i].val)
				edge[i].val = a[kk][u] + a[kk][edge[i].to];
			if(dis[edge[i].to] > dis[u] + edge[i].val){
				dis[edge[i].to] = dis[u] + edge[i].val;
				tmp.v = edge[i].to, tmp.w = dis[edge[i].to];
				sum++;
				if(sum == n) ans = min(ans, dis[edge[i].to]);
			}
		}
	}
}
int main(){
	freopen("road3.in", "r", stdin);
	freopen("road3.out", "w", stdout);
	cin >> n >> m >> k;
	rep(i, 1, m){
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w); add(v, u, w);
	}
	cin >> c;
	rep(i, 1, k) rep(j, 1, n) cin >> a[i][j];
	Prim();
	cout << ans << "\n";
	return 0;
}
