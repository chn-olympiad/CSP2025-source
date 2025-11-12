#include <bits/stdc++.h>

#define int long long

#define all(A) A.begin(), A.end()

#define pb push_back

#define rep(A, B, C) for (int A = B; A <= C; ++A)

#define rep2(A, B, C, D) for (int A = B; A <= C; A += D)

using namespace std;

inline int read() {
	int x = 0, f = 1;

	char ch = getchar();

	while (!isdigit(ch)) {
		if (ch == '-') f = -1;

		ch = getchar();
	}

	while (isdigit(ch))
		x = x * 10 + (ch - '0'), ch = getchar();

	return x * f;
}

typedef pair<int, int> PII;

const int N = 1e4 + 15, M = 1e6 + 15, K = 15, inf = 1e18;

int n, m, k, ans = inf;

int u[M], v[M], w[M];

int c[K], a[K][N], fa[N];

struct node { int x, y, z; };

vector<node> vec, ve;

int now[K], tot;

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

bool cmp(node p, node q) { return p.z < q.z; }

void chk() {	
	rep(i, 1, n + tot) fa[i] = i;
	
	rep(i, 0, vec.size() - 1) ve.pb(vec[i]);
	
	rep(i, 1, tot) rep(j, 1, n) ve.pb({ n + now[i], j, a[now[i]][j] });
	
	sort(all(ve), cmp);
	
	int cnt = n + tot, res = 0;
	
	rep(i, 1, tot) res += c[now[i]];
	
	rep(i, 0, ve.size() - 1) {
		int x = ve[i].x, y = ve[i].y, z = ve[i].z;
		
		int fx = find(x), fy = find(y);
		
		if (fx == fy) continue;
		
		cnt --, res += z, fa[fx] = fy;
		
		if (cnt == 1) break;
	}
	
	ve.clear();
	
	ans = min(ans, res);
}

void dfs(int x) {
	if (x == k + 1) { chk(); return; }
	
	dfs(x + 1);
	
	now[++tot] = x;
	
	dfs(x + 1);
	
	now[tot--] = 0;
}

signed main() {
	freopen("road.in", "r", stdin);

	freopen("road.out", "w", stdout);

	n = read(), m = read(), k = read();
	
	rep(i, 1, m) u[i] = read(), v[i] = read(), w[i] = read();
	
	rep(i, 1, k) {
		c[i] = read();
		
		rep(j, 1, n) a[i][j] = read();
	} 
	
	rep(i, 1, m) vec.pb({ u[i], v[i], w[i] });
	
	dfs(1);
	
	printf("%lld\n", ans);

	return 0;
}

