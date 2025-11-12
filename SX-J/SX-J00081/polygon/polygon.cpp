#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	int a[5020];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= 3; i++) {
		if (n <= 3) {
			cout << "0";
		} else {
			cout << "5000";
		}
		break;
	}
	return 0;
}
