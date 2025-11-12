#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef double lf;
const int maxn = 2e4 + 5, maxm = 1.1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int lowbit(const int &x) { return x & -x; }
int CountBit(int x) {
	int reply = 0;
	for (; x; x -= lowbit(x)) ++reply;
	return reply;
}

struct Edge {
	int from, to;
	ll dis;
	bool operator <(const Edge &b) const & {
		return dis < b.dis;
	}
} edge[maxm];

int u[maxm], v[maxm], fa[maxn], len;
ll w[maxm], a[15][maxn], finalReply = inf, reply;
int find(const int &x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

int n, m, k, K;
void Kruskal(const int &S) {
	sort(edge + 1, edge + len + 1);
	int now = n + CountBit(S), cnt = 0;
	ll w;
	for (int i = 1, x = now; i <= x; ++i) fa[i] = i;
	for (int i = 1, x, y; i <= len; ++i) {
		x = find(edge[i].from), y = find(edge[i].to), w = edge[i].dis;
		if (x != y) {
			reply += w, fa[x] = y;
			if (++cnt == now - 1) return;
		}
	}
}

ll A = 0;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k), K = 1 << k;
	for (int i = 1; i <= m; ++i) scanf("%d%d%lld", u + i, v + i, w + i);
	for (int i = 1; i <= k; ++i) 
		for (int j = 0; j <= n; ++j) scanf("%lld", a[i] + j);
	for (int i = 1; i <= k; ++i) A = max(a[i][0], A);
	if (A) {
		for (int S = 0; S < K; ++S) {
			reply = 0;
			for (int i = 1; i <= m; ++i) edge[i] = {u[i], v[i], w[i]};
			len = m;
			for (int i = 1; i <= k; ++i)
				if (S & (1 << (i - 1))) {
					for (int j = 1; j <= n; ++j)
						edge[++len] = {i + n, j, a[i][j]};
					reply += a[i][0];
				}
			Kruskal(S);
			finalReply = min(finalReply, reply);
		}				
	} else {
		int S = K - 1;
		reply = 0;
		for (int i = 1; i <= m; ++i) edge[i] = {u[i], v[i], w[i]};
		len = m;
		for (int i = 1; i <= k; ++i)
			if (S & (1 << (i - 1))) {
				for (int j = 1; j <= n; ++j)
					edge[++len] = {i + n, j, a[i][j]};
				reply += a[i][0];
			}
		Kruskal(S);
		finalReply = min(finalReply, reply);		
	}
	printf("%lld", finalReply);
	return 0;
}
