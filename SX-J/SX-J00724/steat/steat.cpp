#include <bits/stdc++.h>
using namespace std;
int a[105], z;

int main() {
	freopen("steat.in", "r", stdin);
	freopen("steat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n * m; i++) {
		if (a[i] < a[i + 1]) {
			z = a[i];
			a[i + 1] = a[i];
			a[i + 1] = n;
		}
		cout << a[i];
	}
	return 0;
}