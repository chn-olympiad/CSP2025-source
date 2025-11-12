#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k;
ll cnt;
int fa[N], a[11][N], aa[11], b[11];
bool bo[11];

struct node {
	int v, w;
};
vector<node> e[N];
vector<node> ee[M];
vector<int> v;

struct node1 {
	int u, v, w;
} p[M];
int ac[M];
map<int, int> mp;
vector<node1> ans;

int find(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

bool cmp(node1 q, node1 e) {
	return q.w > e.w;
}

bool cmp1(node1 q, node1 e) {
	return q.w < e.w;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> p[i].u >> p[i].v >> p[i].w;
//		cout << p[i].u << ' ' << p[i].v;
//		if (p[i].u > 1e6 || p[i].v > 1e6)
//			cout << "KKKK";
	}
	int yzx = m;
	for (int i = 1; i <= k; i++) {
		cin >> aa[i];
		int minn = INT_MAX, id;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] < minn) {
				minn = a[i][j];
				id = j;
			}
		}
		int iid = 0, minnn = INT_MAX;
		for (int j = 1; j <= n; j++) {
			if (j != id) {
				if (a[i][j] < minnn) {
					minnn = a[i][j];
					iid = j;
				}
			}
		}
		p[++yzx].u = id;
		p[yzx].v = iid;
//		cout << id << ' ' << iid << endl;
		p[yzx].w = minn + minnn + aa[i];
	}
	sort(p + 1, p + yzx + 1, cmp1);
	int yyy = 0;
	for (int i = 1; i <= yzx; i++) {
		if (mp[p[i].w] == 0) {
			mp[p[i].w] = ++yyy;
			ac[yyy] = p[i].w;
		}
//		if (p[1].u > 300) {
//			cout << i;
//			return 0;
//		}
	}
//	cout << 1;
	for (int i = 1; i <= yzx; i++) {
//		cout << i << ' ' << p[i].u << ' ' << p[i].v << ' ' << mp[p[i].w] << endl;
		e[p[i].u].push_back({p[i].v, mp[p[i].w]});
		e[p[i].v].push_back({p[i].u, mp[p[i].w]});
		ee[mp[p[i].w]].push_back({p[i].u, p[i].v});
		v.push_back(mp[p[i].w]);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < ee[v[i]].size(); j++) {
			int u = ee[v[i]][j].v, vi = ee[v[i]][j].w;
//			cout << u << ' ' << vi << endl;
			int uu = find(u), vv = find(vi);
			if (uu != vv) {
				fa[uu] = vv;
				cnt += ac[v[i]];
				ans.push_back({u, vi, ac[v[i]]});
//				cout << u << ' ' << vi << endl;
			}
		}
	}
//	cout << cnt << endl;
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
		int u = ans[i].u, v = ans[i].v, w = ans[i].w;
		for (int j = 1; j <= k; j++) {
			int o = a[j][u] + a[j][v];
			if (o < w) {
				b[j] += w - o;
			}
		}
	}
	for (int i = 1; i <= k; i++) {
//		cout << b[i] << ' ';
		if (aa[i] < b[i]) {
			cnt -= b[i];
			cnt += aa[i];
		}
	}
	cout << cnt;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
