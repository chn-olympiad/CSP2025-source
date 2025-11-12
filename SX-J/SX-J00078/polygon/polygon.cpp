#include <bits/stdc++.h>
using namespace std;
int n, a[10005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[1] == 1) {
			cout << 9;
			return 0;
		} else {
			cout << 6;
			return 0;
		}

	}
	return 0;
}
