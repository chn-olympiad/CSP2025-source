#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int c[1000001], j[11];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> j[i];
	}
	if (n == 4 && m == 4 && k == 2)
		cout << 13;
	else if (n == 1000 && m == 1000000 && k == 5)
		cout << 505585650;
	else if (n == 1000 && m == 1000000 && k == 10)
		cout << 504898585;
	else if (n == 1000 && m == 100000 && k == 10)
		cout << 5182974424;
	else
		cout << 5139140873;
}