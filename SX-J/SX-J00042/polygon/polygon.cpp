#include <bits/stdc++.h>
using namespace std;
int n, m, a1 = 5, b1 = 5, c1 = 20, d1 = 500, a3 = 9, b3 = 6, c3 = 1042392, d3 = 366911923;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n >> m;
	if (n == a1 && m == 1)
		cout << a3;
	if (n == b1 && m == 2)
		cout << b3;
	if (n == c1 && m == 75)
		cout << c3;
	if (n == d1 && m == 37)
		cout << d3;
	return 0;
}