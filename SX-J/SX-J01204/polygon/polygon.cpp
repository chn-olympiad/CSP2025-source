#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n <= 2)
		cout << 0;
	else {
		cin >> n;
		if (a + b + c > a * 2 && a + b + c > b * 2 && a + b + c > c * 2)
			cout << 1;
		else
			cout << 0;
	}
	return 0;
}
