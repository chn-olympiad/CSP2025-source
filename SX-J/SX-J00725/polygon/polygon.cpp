#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[5];
bool flas;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n < 3) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			flas = 1;
	}
	if (n == 3) {
		if (a[3] + a[1] > a[2] && a[3] + a[2] > a[1] && a[1] + a[2] > a[3])
			cout << 1;
		else
			cout << 0;
	} else
		cout << n - 2;
	return 0;
}
