#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a, b, c, k;
	cin >> n;
	cin >> a >> b >> c;
	k = max({a, b, c});
	if (a + b + c > 2 * k)
		cout << 1;
	else
		cout << 0;
	return 0;
}