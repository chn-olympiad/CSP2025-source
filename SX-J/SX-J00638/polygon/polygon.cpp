#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, b;
	cin >> n;
	int a[5100];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	b = a[5100];
	cout << b;
	return 0;
}