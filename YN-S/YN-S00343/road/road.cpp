#include <bits/stdc++.h>
using namespace std;
const int N = 3e6;
#define int long long

struct side {
	int u, v, w;
};
side s[N];
int fa[N];

bool cmp(side a, side b) {
	return a.w < b.w;
}
vector<side> v1, nv1;

int fnd(int a) {
	if (fa[a] == a)
		return a;
	return fa[a] = fnd(fa[a]);
}
int siz;
int k, n, m;
int bj[11];
int num[11];
int cost[11][N];
int ans;

void col(int val, int mor) {
	for (int i = 1; i <= n + mor; i++) {
		fa[i] = i;
	}
	sort(nv1.begin(), nv1.end(), cmp);
	int res, cnt;
	res = cnt = 0;
	int u, v;
	for (int i = 0; i < nv1.size(); i++) {
		u = fnd(nv1[i].u);
		v = fnd(nv1[i].v);
		if (u != v) {
			if (val == 1) {
				//cout << nv1[i].u << ' ' << nv1[i].v << " " << nv1[i].w << " ]]";
			}
			fa[u] = v;
			cnt++;
			res += nv1[i].w;
		}
		if (cnt == n + mor - 1) {
			//cout << "NP";
			break;
		}
	}
//	cout << res << " " << val << "qaa\n";
	ans = min(ans, res + val);
	return;
}

void dfs(int c) {
	if (c == k + 1) {
		nv1 = v1;
		int tmp = 0, mor = 0;;
		for (int i = 1; i <= k; i++) {
			if (bj[i] == 0)
				continue;
			tmp += num[i];
			mor++;
			for (int j = 1; j <= n; j++) {
				nv1.push_back({n + mor, j, cost[i][j]});
			}
		}
		col(tmp, mor);
		return;
	}
	bj[c] = 1;
	dfs(c + 1);
	bj[c] = 0;
	dfs(c + 1);
	return;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> s[i].u >> s[i].v >> s[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> num[i];
		for (int j = 1; j <= n; j++) {
			cin >> cost[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	sort(s + 1, s + 1 + m, cmp);
	int cnt;
	cnt = ans = 0;
	int u, v;
	for (int i = 1; i <= m; i++) {
		u = fnd(s[i].u), v = fnd(s[i].v);
		if (u != v) {
			fa[u] = v;
			cnt++;
			ans += s[i].w;
			v1.push_back(s[i]);
		}
		if (cnt == n - 1) {
			break;
		}
	}
	//cout << ans << "\n";
	dfs(1);
	cout << ans;
	return 0;
}