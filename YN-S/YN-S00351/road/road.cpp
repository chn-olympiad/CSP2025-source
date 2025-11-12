#include <iostream>
using namespace std;
const int N = 100000 + 5;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	long long ans =  9999999999999;
	cin >> n >> m >> k;
	int r[m + 5][4] = {0}, c[k + 5][m + 5] = {0};
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 3; j++)
			cin >> r[i][j];
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= m; j++)
			cin >> c[i][j];
		ans = min(ans, (long long)c[i][0]);
	}
	cout << ans;
	return 0;
}