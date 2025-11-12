#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	cout << s;
	return 0;
}
	for (int i = 1; i <= m; i++) {
		if (d <= n)
			x = 1;
		if (n < d <= m * n)
			x = i;
	}
	if (d <= n)
		y = d;
	if (x % 2 == 0)
		y = d - x * n;
	if (x % 2 == 1)
		y = x * n - d + 1;
	cout << x << ' ' << y;
	return 0;