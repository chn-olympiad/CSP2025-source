#include <bits/stdc++.h>
using namespace std;
int n, a[1005], s, m;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			s += a[j];
		}
		if (s > a[i]) {
			m++;
		}
	}
	cout << m;
	return 0;
}
