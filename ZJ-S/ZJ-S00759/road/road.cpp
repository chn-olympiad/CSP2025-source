#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+25;
const int M = 1e6+5;
const int K = 15;
const long long INF = 0x3f3f3f3f3f3f3f3f;
using ll = long long;

ll ans = INF;
int a[K][N];
int c[K];
int n, m, k;
ll dis[N+K];

struct e{
    int to;
    ll w;
}; vector<e> g[N];

struct cmp{
	bool operator() (const e& a, const e& b) {
		return a.w > b.w;
	}
};

void solve(int cond) {
//	cerr << cond << endl;
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	ll res = 0;
	for (int i=1;(1<<(i-1))<=cond;i++) {
		if (cond & (1<<(i-1))) {
			res += c[i];
			for (int u=1;u<=n;u++) {
				g[u].push_back({n+i, a[i][u]});
				g[n+i].push_back({u, a[i][u]});
			}
		}
	}
	
    bool vis[N];
    memset(vis, 0, sizeof(vis));
    priority_queue<e, vector<e>, cmp> q;
    q.push({1, 0});
//    q.push({2, 5});
    while (!q.empty()) {
        int u = q.top().to;
        int w = q.top().w;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        res += w;
//        cerr << "->" << u << "(" << w << ")";////////////////////////////////////
        
		for (e edge : g[u]) {
//            int to = edge.to;
//            w = edge.w;
//            if (cond==1) {
////            	cerr << "to:" << to << " dis[to]:" << dis[to] << " u:" << u << " dis[u]:" << dis[u] << " w:" << w << endl;
//				cerr << u << "->" << to << " , " << w << endl;
//				if (u==4 && to==2) cerr << dis[u] << " " << dis[to] << endl;
//			}
//            if (dis[to] > dis[u]+w){
//				dis[to] = dis[u]+w;
				q.push(edge);
//    		}
		}
    }
//    cerr << endl << res << endl;/////////////////////////////
    ans = min(ans, res);
}

int main() {
	freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++) {
        int u, v;
		ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i=1;i<=k;i++) {
    	cin >> c[i];
        for(int j=1;j<=n;j++) {
            cin >> a[i][j];
        }
    }	
	for (int i=0;i<(1<<k);i++) {
		solve(i);
	}
	cout << ans;
}

