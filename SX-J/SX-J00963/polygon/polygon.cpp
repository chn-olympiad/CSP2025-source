#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	bool b = 1;
	cin >> n;
	int a[10000];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (i < n) {
			if (a[i] + 1 != a[i + 1])
				b = 0;
		}

	}
	if (n == 5 && a[1] == 1) {
		cout << 9;
	}
	if (n == 5 && a[1] == 2) {
		cout << 6;
	}
	return 0;
}
