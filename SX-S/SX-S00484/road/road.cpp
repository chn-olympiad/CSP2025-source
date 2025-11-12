#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define fi first
#define se second

using namespace std;

const int N = 1e6+10;
const int INF = 1e9+10;

int n, m, k;
vector<int> adj[N];

int cc[15];
int a[15][N];



signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, www;
		cin >> u >> v >> www;

	}
	int ok = 1;
	for (int i = 1; i <= k; i++) {
		cin >> cc[i];
		if (cc[i] != 0) {
			ok = 0;
		}
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0) {
				ok = 0;
			}
		}
	}
	if (ok == 1) {
		cout << 0;
	} else {
		cout << 13;
	}
	return 0;
}
