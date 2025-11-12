#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin (), (x).end ()
#define vec vector
#define MAXN 10005
#define MAXM 1000005
#define pli pair <ll, int>

template <typename T> inline void read (T &x) {
	x = 0; T f = 1; char ch = getchar ();
	while (!isdigit (ch)) { if (ch == '-') f = -1; ch = getchar (); }
	while (isdigit (ch)) { x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar (); }
	x *= f;
}

template <typename T, typename ...Arp> inline void read (T &x, Arp &...arp) {
	read (x), read (arp...);
}

int n, m, k;
ll c[15];
pli a[15][MAXN];

int fa[MAXN];
int find (int x) {
	if (x == fa[x]) return x;
	return fa[x] = find (fa[x]);	
}

struct Edge {
	int u, v;
	ll w;	
	bool operator < (const Edge o) const {
		return w < o.w;
	}
} e[MAXM], tr[12][MAXN];

ll ksk1 () {
	sort (e + 1, e + m + 1);
	
	for (int i = 1; i <= n; ++i) fa[i] = i;
	
	int V = 0; ll ans = 0;
	for (int i = 1; i <= m; ++i) {
		int u = find (e[i].u);
		int v = find (e[i].v);
		
		if (u != v) {
			tr[0][++V] = e[i], fa[u] = v, ans += e[i].w;
		}
		
		if (V >= n)
			break;
	}
	
	return ans;
}

bool vis[15];

ll ksk2 (int M) {
	sort (e + 1, e + M + 1);
	
	for (int i = 1; i <= n; ++i) fa[i] = i;
	
	int V = 0; ll ans = 0;
	for (int i = 1; i <= M; ++i) {
		int u = find (e[i].u);
		int v = find (e[i].v);
		
		if (u != v) {
			fa[u] = v, ans += e[i].w;
		}
		
		if (V >= n)
			break;
	}
	
	return ans;
}

signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	read (n, m, k);
	
	for (int i = 1; i <= m; ++i) {
		read (e[i].u, e[i].v, e[i].w);
	}
	
	for (int i = 1; i <= k; ++i) {
		read (c[i]);
		for (int j = 1; j <= n; ++j) {
			read (a[i][j].x), a[i][j].y = j;
		}
	}

	for (int i = 1; i <= k; ++i) {
		sort (a[i] + 1, a[i] + n + 1);
		
		int u, v;
		for (int j = 2; j <= n; ++j) {
			u = a[i][1].y;
			v = a[i][j].y;
			
			tr[i][j - 1] = {u, v, a[i][1].x + a[i][j].x};
		}
	}
	
	ll ans = ksk1 ();
	// tr[0] 是原图的 mst
	ll sum = 0;
	
	function <void (int)> dfs = [&] (int x) {
		if (x > k) {
			int M = n - 1;
			for (int i = 1; i < n; ++i) 
				e[i] = tr[0][i];
				
			sum = 0;
			for (int i = 1; i <= k;  ++i) 
				if (vis[i]) {
					for (int j = 1; j < n; ++j) 
						e[++M] = tr[i][j];
					sum += c[i]; 
				}
			ans = min (ans, ksk2 (M) + sum);
			return ;
		}
		
		dfs (x + 1);
		vis[x] = 1, dfs (x + 1), vis[x] = 0;
	};
	
	dfs (1);
	
	printf ("%lld\n", ans);
	return 0;
}

/*
目前期望，-inf 分 
注意：

1. 开 ll 
2. 若 c_k = 0，直接改造城市 
3. 目前想了一个貌似可行的解，如果写了之后过不了大样例，就直接写暴力，扔了 
*/

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
