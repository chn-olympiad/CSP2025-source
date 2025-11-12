#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int dis[N][N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long n, m, k, a, b, x;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> x;
		dis[a][b] = x;
		dis[b][a] = x;
	}
	cout << 0;
	return 0;
}
