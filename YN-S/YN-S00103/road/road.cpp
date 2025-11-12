#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	long long n, m, k, road[1000000], from[10000], to[10000], way[10000][10000];
	long long sumw = 0;
	cin >> n >> m >> k;
	for (long long i = 0; i < m; i++) {
		cin >> road[i] >> from[i] >> to[i];
	}
	while (k == 0) {
		long long minw;
		for (long long j = 1; j < m ; j++) {
			minw = min{road[j], road[j - 1]};
			long long op = j;
		}
		sumw += minw;
		cout << minw;
	}
	return 0;
}