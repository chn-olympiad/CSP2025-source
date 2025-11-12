#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.stdin", "r", stdin);
	freopen("road.stdout", "w", stdout);
	int n, m, k, sum = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		sum += c;
	}
	cout << sum;
}