#include <bits/stdc++.h>
using namespace std;
int f(int a, int b) {
	if (a == b)
		return a;
	int s = 0, nu = 1;
	while (a > 0 or b > 0) {
		if (a % 2 != b % 2)
			s += nu;
		nu *= 2;
		a /= 2;
		b /= 2;
	}
	return 0;
}
int n, k;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	cout << f(n, k);
	return 0;
}
