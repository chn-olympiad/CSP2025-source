#include <bits/stdc++.h>
using namespace std;
int n, m, a[225];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int j = 1; j <= m; j++) {
		cin >> a[j];
	}
	cout << n << m << a;
	return 0;
}
