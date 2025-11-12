#include <bits/stdc++.h>
using namespace std;
//#define int long long
int a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int sum = 0, maxx = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		maxx = max(maxx, a[i]);
	}
	if (sum > 2 * maxx) {
		cout << 1;
	}
	return 0;
}