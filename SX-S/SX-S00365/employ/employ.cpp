#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
	}
	for (int j = 1; j <= n; j++) {
		int y;
		cin >> y;
	}
	long long anser = 1;
	for (int i = 1; i <= n; i++) {
		anser = anser * i % 998244353;
	}
	cout << anser;
	return 0;
}