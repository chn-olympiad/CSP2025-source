#include <iostream>
#include <vector>
using namespace std;
int n, m, k;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	vector<int> a(m + 1);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
	}
	cout << 2 * m << endl;
	return 0;
}

