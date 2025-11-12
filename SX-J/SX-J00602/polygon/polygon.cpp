#include <bits/stdc++.h>
using namespace std;
int n, sum = 0, maxx = INT_MIN;
int a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int num = 0;
	for (int i = 0; i < n; i++) {
		num += a[i];
		maxx = max(maxx, a[i]);
	}
	if (num > 2 * maxx)
		sum++;
	sum %= 998244353;
	cout << sum;
	return 0;
}
