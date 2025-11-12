#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define GL return
#define HF 0

const int N = 20100;

struct info {
	int x, y, z;
};

bool operator < (info a, info b) {
	return a.z < b.z;
}

int test, n, m, k, fa[N], d[N];
bool b[N];
vector<info> edge, s;
vector<pair<int, int> > edges[N];
ll ans = 0ll, w;

int findset (int x) {
	return x == fa[x] ? x : fa[x] = findset(fa[x]);
}

ll Kruskal () {
	for (int i = 0; i <= n + k; i++) {
		fa[i] = i;
	}
	ll res = 0ll;
	sort(s.begin(), s.end());
	int len = s.size();
	for (int i = 0; i < len; i++) {
		int x = s[i].x, y = s[i].y, z = s[i].z;
		int fx  = findset(x), fy = findset(y);
		if (fx != fy) {
			res += z;
			fa[fx] = fy;
		}
	}
	return res;
}

void solve () {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		info t;
		t.x = x, t.y = y, t.z = z;
		edge.push_back(t);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &d[i]);
		for (int j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			edges[i].push_back(make_pair(j, x));
		}
	}
	ans = 1ll << 59ll;
	for (int i = 0; i < 1 << k; i++) {
		s = edge;
		w = 0ll;
		if (i) {
			for (int j = 1; j <= k; j++) {
				if (i >> (j - 1) & 1) {
					w += d[j];
					int len = edges[j].size();
					for (int t = 0; t < len; t++) {
						info e;
						e.x = edges[j][t].first, e.y = n + j;
						e.z = edges[j][t].second;
						s.push_back(e);
					}
				}
			}
		}
		ans = min(ans, Kruskal() + w);
	}
	printf("%lld\n", ans);
	GL;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	solve();
	GL HF;
}
//key Ren5Jie4Di4Ling5%
