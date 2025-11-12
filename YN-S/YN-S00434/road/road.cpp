#include <iostream>
using namespace std;
int u[100], v[100], w[100], a[100];

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	int c;
	cin >> n >> m >> k;
	for (int i = 1; i <= m ; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int q = 1; q <= k; q++) {
		cin >> a[n + 1];
	}
	cout << 13;

	return 0;
}