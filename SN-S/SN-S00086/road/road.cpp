#include <iostream>
using namespace std;

int n, m, k, u, v;
long long w, c, a, sum;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++) {
		cin >> u >> v >> w;
		sum += w;
	}
	for (int i = 1;i <= k;i++) {
		cin >> c;
		for (int i = 1;i <= n;i++) {
			cin >> a;
		}
	}
	
	cout << sum;
	return 0;
}
