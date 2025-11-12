#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	long long a = 0;
	for (int i = n; i >= 3; i--) {
		int j = n - i;
		a = a + pow(5, j);
		a %= 998244353;
	}
	cout << a;
	return 0;
}