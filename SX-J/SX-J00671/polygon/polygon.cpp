#include <bits/stdc++.h>
using namespace std;
int n, a[105];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int min = a[0] + a[1] + a[2];
	int max = a[n] + a[n - 1] + a[n - 2];
	cout << max - min + 1;
	return 0;
}
