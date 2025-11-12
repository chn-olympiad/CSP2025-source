#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+100;
int f[N], c[N], a[20][N];

int find(int x) {
	if (f[x] == x) {
		return x;
	}
	return f[x] = find(f[x]);
}

struct Ed {
	int x, y, w;
};

bool cmp(Ed t, Ed tt) {
	return t.w < tt.w;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<Ed> v;
	map<pair<int, int>, int> p;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++) {
		int U, V, W;
		cin >> U >> V >> W;
		p[ {min(U, V)	,	max(U, V)}] = W;
		v.push_back({U, V, W});
		v.push_back({V, U, W});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
		for (int j = 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
//				if (a[i][j] + a[i][k] < p[ {j, k}]) {
				v.push_back({j, k, a[i][j] + a[i][k] + c[i]});
//				}
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	int ans = 0;
	int nn = v.size();
	for (int i = 0; i < nn; i++) {
		int a = v[i].x;
		int b = v[i].y;
		int c = v[i].w;
		if (find(a) == find(b)) {
			continue;
		}
		f[find(a)] = f[find(b)];
		ans = ans + c;
	}
	cout << ans << endl;
	return 0;
}
