#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read() {
	ll res = 0, neg = 1; char ch = getchar();
	while(ch<'0' or ch>'9') { if(ch == '-') neg = -1; ch = getchar(); }
	while(ch>='0' and ch<='9') res = res*10 + ch-'0', ch = getchar();
	return res * neg;
}

void write(ll x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x+'0');
	else write(x/10), putchar(x%10+'0');
}

const int N = 1e4+50;
const int M = 1e6+50;
const int K = 15;

int n,m,k;
struct Dir_Edge {
	int v; ll w;
} ; vector<Dir_Edge> g[N];
ll a[K][N];

ll ans = 1e15;

bool flag[K];

int f[N];

void init() { for(int i=1; i<=n+k; i++) f[i] = i; }

int find(int x) {
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

void join(int x, int y) {
	f[find(y)] = find(x);
	return ;
}

struct Edge {
	int u,v; ll w;
	bool operator > (const Edge& tx) const {
		return w > tx.w;
	}
	bool operator < (const Edge& tx) const {
		return w < tx.w;
	}
} edges[M];

ll kruskal() {
	priority_queue<Edge, vector<Edge>, greater<Edge> > que;
	init();
	
	int cnt_edge = n-1, cnt = 0;
	ll res = 0;
	
	for(int j=1; j<=k; j++) {
		if(!flag[j]) continue ;
		for(int i=1; i<=n; i++) {
			int u=j+n, v=i; ll w = a[j][i];
			que.push((Edge){u,v,w});
		}
		cnt_edge++;
		res += a[j][0];
	}
	
	for(int i=1; i<=m+(cnt_edge-n+1)*k; ) {
		int u,v; ll w; bool tmpflag = 1;
		u = edges[i].u, v = edges[i].v, w = edges[i].w;
		
		if(que.size() > 0 and que.top().w < w) {
			u = que.top().u, v = que.top().v, w = que.top().w;
			que.pop(); tmpflag = 0;
			if(find(u) == find(v)) {
				continue ;
			}
		}
		else i++;
		
		if(find(u) == find(v)) {
			continue ;
		}
		
		join(v, u);
		res += w;
		cnt++;
		
		if(cnt == cnt_edge) break;
	}
	
	return res;
}

void dfs(int x) {
	if(x > k) {
		ans = min(ans, kruskal());
		return ;
	}
	
	dfs(x+1);
	
	flag[x] = 1;
	dfs(x+1);
	flag[x] = 0;
	
	return ;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read(), m = read(), k = read();
	for(int i=1; i<=m; i++) {
		int u = read(), v = read(); ll w = read();
		g[u].push_back((Dir_Edge){v,w});
		g[v].push_back((Dir_Edge){u,w});
		edges[i] = (Edge){u,v,w};
	}
	
	sort(edges+1, edges+1+m);
	
	for(int t=1; t<=k; t++)
		for(int i=0; i<=n; i++)	a[t][i] = read();
	
	dfs(1);
		
	write(ans);
	
	return 0;
}