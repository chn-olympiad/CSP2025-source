#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[20], m;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		m = max(m, a[i]);
	}
	if (a[1] + a[2] + a[3] > 2 * m && n == 3) {
		cout << 1;
	} else {
		cout << 0;


	}
}
