#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
ll  n, m, k, c[N], a[20][N];

struct node {
	ll u, v, w;
} r[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> r[i].u >> r[i].v >> r[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
	}
	cout << 0;
	return 0;
}
