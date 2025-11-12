#include <bits/stdc++.h>
using namespace std;
long long n, m;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 3; i <= n; i++) {
		m += i;
	}
	cout << m % 998244353;
	return 0;
}
