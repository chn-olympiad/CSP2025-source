#include <bits/stdc++.h>

#define inf 0x7f7f7f7f

#define N ((int)1e4 + 20 + 10)
#define M ((int)1e6 + 10 * N + 10)
#define K (10 + 10)

using namespace std;

int n, m, k;

struct edge {
	int to, nxt;
	int w;
}e[2 * M];
int head[N];

int tot;
inline void adde(int u, int v, int w) {
	++tot;
	e[tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
	e[tot].w = w;
#ifdef XYX
//	cout << "adde : " << u << " -> " << v << " " << w << endl;
#endif
}

struct node {
	int val;
	bool is_use;
}nd[K];

struct ttt {
	int id;
	int w;
	
	inline bool operator < (const ttt &t2) const {
		return w > t2.w;
	}
};
priority_queue<ttt> pq;

int vis[N], cnt, _ans, _n;
inline void prim(int s) {
	for(int i = 1;i <= n;i++) {
		vis[i] = 0;
	}
	cnt = _ans = 0;
	pq.push(ttt{s, 0});
	
	while(!pq.empty()) {
		int u = pq.top().id;
		int w = pq.top().w;
		pq.pop();
		
		if(vis[u]) continue;
		vis[u] = 1;
		
		_ans += w;
#ifdef XYX
//		cout << u << " " << _ans << endl;
#endif
		
		++cnt;
		if(cnt == n + _n) break;
		
		for(int i = head[u];i;i = e[i].nxt) {
			int v = e[i].to;
			if(v > n && !nd[v - n].is_use) continue;
			if(vis[v]) continue;
			
			pq.push(ttt{v, e[i].w});
		}
	}
}

inline bool check_A();
inline void solve1();
inline void solve2();

int main() {
#ifdef XYX
	freopen("road2.in", "r", stdin);
//	freopen("road2.out", "w", stdout);
#else 
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
#endif 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	
	int u, v, w;
	for(int i = 1;i <= m;i++) {
		cin >> u >> v >> w;
		adde(u, v, w);
		adde(v, u, w);
	}
	
	for(int i = 1;i <= k;i++) {
		nd[i].is_use = 0;
		cin >> nd[i].val;
		for(int j = 1;j <= n;j++) {
			cin >> w;
			adde(n + i, j, w);
			adde(j, n + i, w);
		}
	}
	
//	prim(1);
//	cout << _ans;

	if(check_A()) {
		solve1();
	}
	else {
		solve2(); 
	}
	
	return 0;
}

inline bool check_A() {
	for(int i = 1;i <= k;i++) {
		if(nd[i].val != 0) return 0;
	}
	return 1;
}
inline void solve1() {
	for(int i = 1;i <= k;i++) {
		nd[i].is_use = 1;
		++_n;
	}
	
	prim(1);
	cout << _ans;
}

inline void solve2() {
	int ans = inf, cnt;
	for(int key = 0;key < (1 << k);key++) {
		_n = cnt = 0;
		for(int i = 0;i <= k;i++) {
			if(key & (1 << i)) {
				nd[i].is_use = 1;
				cnt += nd[i].val;
				++_n;
			}
		}
		
		prim(1);
		ans = min(ans, cnt + _ans);
		
		for(int i = 0;i <= k;i++) {
			if(key & (1 << i)) {
				nd[i].is_use = 0;
			}
		}
	}
	
	cout << ans;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
100 1 3 2 4
*/