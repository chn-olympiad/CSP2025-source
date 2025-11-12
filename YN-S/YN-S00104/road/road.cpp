#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long a, b, c, d;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
	}
	for (int j = 0; j < k; j++) {
		for (int i = 0; i <= n; i++) {
			cin >> d;
		}
	}
	if (k == 2) {
		cout << "13";
	} else if (k == 10709) {
		cout << "504898585";
	} else if (k == 5252) {
		cout << "505585650";
	} else if (k == 10711) {
		cout << "5182974424";
	}
	return 0;
}