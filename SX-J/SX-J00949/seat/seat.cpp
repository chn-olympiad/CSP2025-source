#include <bits/stdc++.h>
using namespace std;
long long a[100006];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n, ans = 0;
	cin >> m, n;
	ans = m * n;
	for (int i = 1; i <= ans; ++i) {
		cin >> a[i];
	}
	sort(1, ans);
	return 0;
}