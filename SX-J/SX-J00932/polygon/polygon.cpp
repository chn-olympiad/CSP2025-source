#include <bits/stdc++.h>
using namespace std;
int a[5002];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 3) {
		cout << 1;
	}
	return 0;
}
