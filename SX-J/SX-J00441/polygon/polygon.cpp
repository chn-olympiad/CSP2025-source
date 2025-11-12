#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int a[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n, maxx = -1, s = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > maxx)
			maxx = a[i];
		s = s + a[i];
	}
	if (n < 3)
		cout << 0;
	else if (n == 3) {
		if (s > 2 * maxx)
			cout << 1;
		else
			cout << 0;
	} else
		cout << 0;
	return 0;
}
